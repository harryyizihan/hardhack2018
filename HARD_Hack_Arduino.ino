/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMecha
* tronics.com
*
*/
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int movementPin = 7; //sends a digital signal to dragonboard digital input port to indicate movement
int pos = 0;
// defines variables
float duration;
float distance;
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(movementPin , OUTPUT); // Sets the movementPin as an Output
Serial.begin(9600); // Starts the serial communication

}
void loop() {
  digitalWrite(movementPin, LOW);
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration*0.034/2;
//If the distance is less than or equal to 1 meter, movementPin will signal dragonboard to actvate "open" operation
if( distance <= 100) {
  digitalWrite(movementPin, HIGH);
  Serial.println("movmenetPin = HIGH"); 
}
else {
  digitalWrite(movementPin, LOW);
   Serial.println("movmenetPin = LOW");
}
// Prints the distance on the Serial Monitor

Serial.print("Distance: ");
Serial.println(distance);
}
