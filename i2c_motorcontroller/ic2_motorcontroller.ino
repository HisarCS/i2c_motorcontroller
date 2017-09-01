#include <Wire.h>

#define i2c_id 0x07

int m1A = 7
int m1B = 8
int m1E = 6

int m2A = 10
int m2B = 9
int m2E = 11
  
int m3A = 4
int m3B = 2
int m3E = 3

int m4A = 0
int m4B = 1
int m4E = 5
  
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
