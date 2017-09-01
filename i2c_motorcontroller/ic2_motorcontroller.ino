#include <Wire.h>

#define i2c_id 0x07
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin(i2c_id);  
  delay(100);
  Wire.onReceive(receive_event);
  Wire.onRequest(request_event);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
  // put your main code here, to run repeatedly:

}

void receive_event(int n){
  Serial.println("received: ");
  Serial.print(n);
  while(Wire.available()){
    Serial.println("read: ");
    Serial.print(Wire.read());
  }
}  
  
void request_event(){
  Serial.println("requested: ");
  while(Wire.available()){
    Serial.println("read: ");
    Serial.print(Wire.read());
  }
}
