/*
 * The following is a dummy implementation communication
 * test for the CUNY knee exoskeleton communication protocol
 */

/* PROTOCOL Teensy -> Desktop
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
uint16_t data[] = {10,20,35,45,60,50,10,20,1,2,1,2};

void setup() {
  Serial.begin(115200);
}

void loop() {
  packet[0] = 165;
  packet[1] = 90;
  packet[2] = _PACKSIZE;

  for(int i=0; i < (_PACKSIZE-3)/2; i++){
    int temp = i*2+3; //used to index packet by 2 bytes for each iteration
    packet[temp] = highByte(data[i]);
    packet[temp+1] = lowByte(data[i]);
  }
  if(_PACKSIZE <= Serial.availableForWrite()){
    Serial.write(packet,_PACKSIZE);
  }
  
  delay(10);
}
