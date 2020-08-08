#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;
//joystick
int xPin = A1;
int yPin = A0;
int buttonPin = 2;

int xPosition = 0;
int yPosition = 0;
int buttonState = 0;
//joystick


struct data {
  uint16_t xPosition;
  uint16_t yPosition;
} myData;


void setup()
{
    Serial.begin(9600);   // Debugging only
    if (!driver.init())
         Serial.println("init failed");
  //joystick
  Serial.begin(9600); 
  
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);

  //activate pull-up resistor on the push-button pin
  pinMode(buttonPin, INPUT_PULLUP); 
  //joystick
}

void loop()
{
  //joystick
  myData.xPosition = analogRead(xPin);
  myData.yPosition = analogRead(yPin);
  buttonState = digitalRead(buttonPin);
                                          
  Serial.print("X: ");
  Serial.print( myData.xPosition);
  Serial.print(" | Y: ");
  Serial.print(myData.yPosition);
  Serial.print(" | Button: ");
  Serial.println(buttonState);
  
    driver.send((uint8_t *)&myData, sizeof(myData))
    driver.waitPacketSent();
    delay(1000);
}
