#include <Servo.h>;
Servo sm1, sm2, sm3; 
int pos = 0; 
void setup() {
sm1.attach(13);
sm2.attach(8);
sm3.attach(1); 
}
void loop() {
for (pos = 0; pos <= 180; pos += 1) { 

sm1.write(pos);
sm2.write(pos);
sm3.write(pos); 


delay(15); 
}
for (pos = 180; pos >= 0; pos -= 1) {

sm1.write(pos);
sm2.write(pos);
sm3.write(pos); 
delay(15); 
}
}