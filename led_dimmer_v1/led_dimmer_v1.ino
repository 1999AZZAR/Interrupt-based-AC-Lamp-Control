int potPin= A0;  
int LEDPin= 11; 
int readValue; 
int writeValue; 

void setup() {
  pinMode(potPin, INPUT);  
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 readValue = analogRead(potPin);  
 writeValue = (255./1023.) * readValue;
 analogWrite(LEDPin, writeValue);    
 Serial.write(writeValue);
 delay(50);
}
