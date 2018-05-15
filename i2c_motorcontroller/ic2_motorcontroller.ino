#include <Wire.h>

#define i2c_id 0x49

#define op_init 0x01
#define op_motor 0x02
#define op_servo 0x03
#define op_encoder 0x04
#define m1A 8
#define m1E 6

#define m2A 7
#define m2E 5
  
#define m3A 12
#define m3E 11

#define m4A 10
#define m4E 9
int motors[][3] = {{m1A,m1E}, {m2A,m2E}, {m3A,m3E},{m4A,m4E}};
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

void set_motor_speed(int motor_no, boolean motor_dir, int motor_speed){
  analogWrite(motors[motor_no-1][1],motor_speed);
  digitalWrite(motors[motor_no-1][0], motor_dir);
}
void receive_event(int n){
  Serial.println("received: ");
  while(Wire.available()){
    switch(Wire.read()){
      case op_motor:
        if(!Wire.available()) return;
        int motor_no = Wire.read();
        if(!Wire.available()) return;
        boolean motor_dir = Wire.read();
        if(!Wire.available()) return;
        int motor_speed = Wire.read();
        set_motor_speed(motor_no, motor_dir, motor_speed);
      break;
    }
    Serial.print("read: ");
  }
}  
  
void request_event(){
  Serial.println("requested: ");
  while(Wire.available()){
    Serial.print("read: ");
    Serial.println(Wire.read());
  }
}
