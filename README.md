# Exoskeleton

> Contains sample arduino and simulink models for sending and recieving data to the CUNY knee exoskeleton system

The following repo implements a custom serial communication protocol interface in simulink for  communicating with the Teensy 3.6 microcontroller on the knee exoskeleton system. A sample arduino sketch is included for recieving dummy data in the simulink model.

## Directions
***
After opening `serial_communicator.slx`, open the `From Teensy` and `To Teensy` subsystems, then change the `packet input` and `packet output` block board selection settings to correspond to the correct serial port (ex. `COM1`, `COM2`, `COM3`).

*Note: The Simulink Desktop Real-Time package needs to be installed in MATLAB to use the models*