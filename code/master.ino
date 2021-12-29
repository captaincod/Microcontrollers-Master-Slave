#include <SoftwareSerial.h>

SoftwareSerial master_serial(10, 11);
int ph_resistors[] = {A0, A1, A2, A3, A4};
int array_size = sizeof(ph_resistors) / sizeof(ph_resistors[0]);

void setup(){
  
  Serial.begin(115200);
  
  master_serial.begin(4800);
}

void loop(){
  
  if (master_serial.available()){
    Serial.println();
    
    String receiving = "";
    
    Serial.println("Received data:");
    while(master_serial.available()){
      receiving += (char)master_serial.read();
    }
    Serial.println(receiving);
    
    Serial.println("This data:");
    for (int i = 0; i < array_size; i++){
      Serial.print("A" + (String)i + ":" + (String)analogRead(ph_resistors[i]) + "; ");
    }
  }
  
  else{
    Serial.println("Waiting for data");
  }
  delay(1000);
  Serial.println();
}
