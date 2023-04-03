#include <LiquidCrystal.h>
int THERMISTORPIN = 0, BCOEFFICIENT = 3380 ;
float THERMISTORNOMINAL = 10000 , TEMPERATURENOMINAL = 25 ,
SERIESRESISTOR = 10000 ;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int sample[5];
void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
}
void loop() {
 int i;
 float average;
 // take N samples in a row, with a slight delay
 for (i=0; i< 5; i++) {
 sample[i] = analogRead(THERMISTORPIN);
 delay(10);
 }
 // average all the samples out
 average = 0;
 for (i=0; i< 5; i++) {
 average += sample[i];
 }
 average /= 5;
 // convert the value to resistance
 average = 1023 / average - 1;
 average = SERIESRESISTOR / average;
 float steinhart;
 steinhart = average / THERMISTORNOMINAL; // (R/Ro)
 steinhart = log(steinhart); // ln(R/Ro)
 steinhart /= BCOEFFICIENT; // 1/B * ln(R/Ro)
 steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
 steinhart = 1.0 / steinhart; // Invert
 steinhart -= 273.15; // convert to C
 lcd.print("Temp = ");
 lcd.print((int)steinhart);
 lcd.print(" C");
 delay(500);
 lcd.clear();
}
