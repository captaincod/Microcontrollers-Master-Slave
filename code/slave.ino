#include <SoftwareSerial.h>

SoftwareSerial slave_serial(10, 11);
int ph_resistors[] = {A0, A1, A2, A3, A4};
int array_size  = sizeof(ph_resistors) / sizeof(ph_resistors[0]);

void setup(){
  
  Serial.begin(115200);
  
  slave_serial.begin(4800);
}

void loop(){
  
  String sending = "";
  
  for (int i = 0; i < array_size; i++){
    sending += "A" + (String)i + ":" + (String)analogRead(ph_resistors[i]) + "; ";
  }
  
  slave_serial.write(sending.c_str());
  delay(1000);
}
