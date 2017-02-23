# Fuzzy Logic Controller Propeller

Fuzzy Logic controller in real time, connected with an Arduino Mega sending IMU data attached to an arm with a propeller

## Installation

Clone the repository in your computer:

`git clone https://github.com/gagolucasm/Fuzzy-Logic-Controller-Propeller.git`

## Dependencies

You will need:

* [Matlab](https://es.mathworks.com/products/matlab.html)
* [Arduino IDE](https://www.arduino.cc/)

## Hardware

The components you will need are:

* Brussless DC motor
* ESC (Electronic Speed Controler)
* Arduino Mega
* IMU (MPU6050)
* Propeller blades
* Lipo battery

## How to use

When you got all the connections ready, start Matlab and run:

`simulink`

Open the model (helicecontrolV2.slx)

Upload the arduino code to the Mega board, and turn the power on

Select the COM port

Start the Simulink model

Have fun!


## Licence

This proyect is Copyright © 2016-2017 Lucas Gago. It is free software, and may be redistributed under the terms specified in the [MIT Licence](https://opensource.org/licenses/MIT).
