# LED_Lamp
#
# It is a LED lamp with a custom PCB for the LEDs, multiple modules and a temperature sensor . The circuit is powered on 10-30V DC.
#
#  Hardware used:
* GroundStudio NANO+(Arduino Nano Clone)
* 18B20 Temperature Sensor
* CJMCU_0401 Capacitive Touch Sensor with 4 inputs
* PIR Sensor
* PWM Module
* Boost-Buck Converter 5-32VDC to 1.2-35VDC
* 1x4.7Kohm Resistor
* L78S18CV Voltage Regulator
* 18xOSRAM GW JTLMS2.EM LEDs
#
# Schematic:
* It needs some rework:)
#
# STLS:
* You can print them with your own settings.
* For the Light Diffuser is recoMmended 100% infill.
#
# Code:
* It makes the lamp turning on only if the PIR sensor is active and a capacitive input is actioned.
* Each capacitive input represents a brigthness level.
