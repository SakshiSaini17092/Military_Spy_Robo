#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
//10 on tx
//11 on rx 
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

int ledpin=13; 
int Data;
int Sensorvalue; 
//blue gnd 
// black vcc
// defines pins numbers
const int trigPin = 3;
const int echoPin = 5;
// defines variables
long duration;
int distance;
void setup() 
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  myservo.attach(9);
  mySerial.begin(9600);
  pinMode(ledpin,OUTPUT);
}
void loop()
{
  //Read on Bluetooth
  if (mySerial.available())
  {
    Data=mySerial.read();
    if(Data=='1')
    {  
      digitalWrite(ledpin,HIGH);
      myservo.attach(9);
      // attaches the servo on pin 9 to the servo object
      delay(15);
      myservo.write(1);
      // sets the servo position according to the scaled value
      delay(500);
      // waits for it to get to the position
      myservo.detach();
      //mySerial.println("LED On! ");
    }
    else  if (Data=='0')
    {
      digitalWrite(ledpin,LOW);
      //mySerial.println("LED Off! ");
    }
  }
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
    distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
    //Serial.print("Distance: ");
    //Serial.println(distance);
  //Write on Bluetooth
  Sensorvalue = analogRead(A0);
  mySerial.println(distance);
  mySerial.flush();
  delay(100);
  
}

