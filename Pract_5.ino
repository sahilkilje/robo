void setup() 
  { 
  Serial.begin(9600); // // Initialize Serial Communication with 9600 baudrate speed 
  pinMode(7, OUTPUT); // Sets the Trig Pin as an OUTPUT   pinMode(6, INPUT); // Sets the Echo Pin as an INPUT
  
  }
void loop() 
{ 
  // Clears the Trig Pin condition   
  digitalWrite(7, LOW);  
  delayMicroseconds(2); 
  // Sets the Trig Pin HIGH (ACTIVE) for 10 microseconds   
  digitalWrite(7, HIGH);  
  delayMicroseconds(10);

digitalWrite(7, LOW); 
  // Reads the Echo Pin, returns the sound wave travel time in microseconds   
  long Duration = pulseIn(6, HIGH);   // Calculating the distance 
  int Distance = Duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back) ;
  // Displays the distance on the Serial Monitor
Serial.print("Distance: "); 
  Serial.print(Distance); 
  Serial.println(" cm"); 
}