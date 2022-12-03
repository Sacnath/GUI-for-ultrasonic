// This is code for ultrasonic sensor and data shown on python GUI desktop.


#define echoPin A0 // attach Echo pin  Arduino to pin Echo of HC-SR04
#define trigPin A1 //attach Trig pin Arduino to pin Trig of HC-SR04

long duration; 
int distance; 


void setup(){
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);

}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  Serial.print(distance);
  Serial.println("");
  delay(1000);
}
