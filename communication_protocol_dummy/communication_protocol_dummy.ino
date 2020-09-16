/*
 * The following is a dummy implementation communication
 * test for the CUNY knee exoskeleton communication protocol
 */

/* PROTOCOL
 * BYTE       DATA
 * ----|-----------------|
 *  0    165
 *  1    90
 *  2    Data Length
 *  3    Left Knee Actual Torque
 *  5    Right Knee Actual Torque
 *  7    Left Knee Angle
 *  9    Right Knee Angle
 *  11   Left Thigh IMU Angle
 *  13   Right Thigh IMU Angle
 *  15   Left Shank IMU Angle
 *  17   Right Shank IMU Angle
 *  19   Left Thigh IMU Angular Velocity
 *  21   Right Thigh IMU Angular Velocity
 *  23   Left Shank IMU Angular Velocity
 *  25   Right Shank IMU Angular Velocity
 */

#define _PACKSIZE 27 //packet size

byte packet[_PACKSIZE];
void setup() {
  Serial.begin(115200);
}

void loop() {
  if(_PACKSIZE <= Serial.availableForWrite()){
    Serial.write(packet,_PACKSIZE);
  }
  
  delay(10);
}
