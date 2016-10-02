////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/////                                                  /////
/////       Modulo de lectura para procesamiento en    /////
/////        hardware externo de datos del MPU6050     /////
/////                                                  /////
/////           Hecho por Lucas Martin Gago como       /////
/////          Trabajo adicional para Mecatronica      /////
/////                                                  /////
/////                        17/6/2016                 /////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"
#include <Servo.h> 

////////////////////////////////////////////////////////////
/////                                                  /////
/////             Delaracion de variables              /////
/////                                                  /////
////////////////////////////////////////////////////////////

Servo esc;
int escPin = 11;
int minPulseRate        = 1000;
int maokPulseRate        = 2000;
int throttleChangeDelay = 50;
int currentThrottle;
int data = 0;  
int in=0;
int count=0;
MPU6050 mpu(0x68);
#define OUTPUT_READABLE_YAWPITCHROLL
#define LED_PIN 13 
bool blinkState = false;
bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;  
uint16_t packetSize;  
uint16_t fifoCount; 
uint8_t fifoBuffer[128]; 
Quaternion q;         
VectorFloat gravity; 
float euler[3];       
float ypr[3];         
volatile bool mpuInterrupt = false;     


////////////////////////////////////////////////////////////
/////                                                  /////
/////                     SETUP                        /////
/////                                                  /////
////////////////////////////////////////////////////////////

void setup() {

    Wire.begin();
    TWBR = 24; 
    Serial.begin(9600);
    initEscs();
    //startUpMotors();
    mpu.initialize();
    devStatus = mpu.dmpInitialize();
    mpu.setXGyroOffset(220);
    mpu.setYGyroOffset(76);
    mpu.setZGyroOffset(-85);
    mpu.setZAccelOffset(1788);
    if (devStatus == 0) {
        mpu.setDMPEnabled(true);     
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
        dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
    } else {
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }
    pinMode(LED_PIN, OUTPUT);
    delay(1000);
}

////////////////////////////////////////////////////////////
/////                                                  /////
/////                     LOOP                         /////
/////                                                  /////
////////////////////////////////////////////////////////////

void loop() {
    if (!dmpReady) return;
    // Lectura de datos serie si estan disponibles
    // Asegurandonos de que no estamos en una interrupcion ni en 
    // un desbordamiento del buffer
    while (!mpuInterrupt && fifoCount < packetSize) {
               
                if (Serial.available() > 0) {
                   data = Serial.read();
                   serialFlush();
                   delay(10);
                }
                
         changeThrottle(data);

    }
    // Bajo flag para interrupcion
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();

    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
    } else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        fifoCount -= packetSize;
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
        float datitoy=(ypr[2] * 180/M_PI)*100;
        int idatitoy=datitoy;
        char ch[4];
        // Envio los datos a Simulink, empezando la cadena con E si es 
        // positivo o con D si es negativo
        if(idatitoy<0){
          Serial.write("E");
          idatitoy=idatitoy*-1;
            }
        else{Serial.write("D");}
        int mil=idatitoy/1000;
        int inter=idatitoy%1000;
        int cent=inter/100;
        inter=inter%100;
        int dec=inter/10;
        int uni=inter%10;
        itoa(idatitoy, ch, 10);
        Serial.write(mil+48);
        Serial.write(cent+48);
        Serial.write(dec+48);
        Serial.write(uni+48);
        delay(50);
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
////////////////////////////////////////////////////////////
/////                                                  /////
/////         Interrupcion para leer datos             /////
/////                                                  /////
////////////////////////////////////////////////////////////

  void dmpDataReady() {
    mpuInterrupt = true;
  }
  
////////////////////////////////////////////////////////////
/////                                                  /////
/////        Cambio gradual de thrust para evitar      /////
/////                 picos de corriente               /////
////////////////////////////////////////////////////////////
 void changeThrottle(int throttle) {
  int currentThrottle = readThrottle();
  
  int step = 1;
  if(throttle < currentThrottle) {
    step = -1;
  }
  
  while(currentThrottle != throttle) {
    writeToEscs(currentThrottle + step);
    
    currentThrottle = readThrottle();
    delay(throttleChangeDelay);
  }
}
 ////////////////////////////////////////////////////////////
/////                                                  /////
/////              Lectura de valor actual             /////
/////                                                  /////
////////////////////////////////////////////////////////////
int readThrottle() {
  int throttle = esc.read();
  return throttle;
}
 
 ////////////////////////////////////////////////////////////
/////                                                  /////
/////                 Escritura a ESC                  /////
/////                                                  /////
////////////////////////////////////////////////////////////

void writeToEscs(int throttle) {
  esc.write(throttle);
}
 
 ////////////////////////////////////////////////////////////
/////                                                  /////
/////              Iniciar los ESC                     /////
/////                                                  /////
////////////////////////////////////////////////////////////

void initEscs() {
  esc.attach(escPin, minPulseRate, maokPulseRate);
  
  

  writeToEscs(0);
}
 
////////////////////////////////////////////////////////////
/////                                                  /////
/////                   Calentar motores               /////
/////                                                  /////
////////////////////////////////////////////////////////////
void startUpMotors() {
  writeToEscs(50);
}
 
////////////////////////////////////////////////////////////
/////                                                  /////
/////                Normalizar valores                /////
/////                                                  /////
////////////////////////////////////////////////////////////

int normalizeThrottle(int value) {
  if(value < 0) {
    return 0;
    
  } else if(value > 180) {
    return 180;
  }
  
  return value;
}

////////////////////////////////////////////////////////////
/////                                                  /////
/////               Vaciar buffer serie                /////
/////                                                  /////
////////////////////////////////////////////////////////////

void serialFlush(){
  while(Serial.available() > 0) {
    char t = Serial.read();
  }
}   

