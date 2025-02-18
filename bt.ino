const int Device1 = 6; // Relay pin 1 (IN1)

void setup() 
 {
  Serial.begin(9600); //Sets the baud for serial data transmission
  // Set Relay pins as OUTPUT  
  pinMode(Device1, OUTPUT);
 
 }

void loop() 
 { digitalWrite(Device1,HIGH);
  if (Serial.available() > 0)
  { 
    char Val = Serial.read();
   if (Val=='F')
     {
      
      
       digitalWrite(Device1,LOW);
       delay(1000);
      
     }else{
       digitalWrite(Device1,HIGH);
     }
   
  }
}
