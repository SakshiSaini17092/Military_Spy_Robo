#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

struct data {
  uint16_t xPosition;
  uint16_t yPosition;
} myData;

    int enA = 2;
    int in1 = 3;
    int in2 = 5;

    int enB = 7;
    int in3 = 6;
    int in4 = 9;
void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
         Serial.println("init failed");
    Serial.begin(9600);
    //pinMode(4,OUTPUT);
    //pinMode(5,OUTPUT);
    //pinMode(8,OUTPUT);
    //pinMode(9,OUTPUT);
    

    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    pinMode(enB, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  //digitalWrite(enA, LOW);
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, HIGH);
    
    //int a = 0;      
}

void loop()
{
    //digitalWrite (enA , HIGH);
    //digitalWrite (enB , HIGH);
    //const char *msg = "upppp";
    //const char *abc = "downn";
    //const char *def = "right";
    //const char *ghi = "leftt";
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    //uint8_t buf[5];
    //uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen))
    // Non-blocking
    {
      //int i;
       memcpy(&myData, buf, buflen);
       //Serial.println("xPosition");
       //Serial.println(myData.xPosition);      // Message with a good checksum received, dump it.
      //Serial.print("Message: ");
      //Serial.println((char*)buf);
      //Serial.println("yPosition");
       //Serial.println(myData.yPosition);   
        //if((char*)buf.equals(*msg)){
        //digitalWrite(4,LOW); 
        //Serial.println("weird");
           
      //}

      if ( myData.xPosition >=600){
        Serial.println("left");
        //digitalWrite(4,HIGH);
        digitalWrite(enA, HIGH);
        digitalWrite(enB, HIGH);
        analogWrite(in1, 255);
        analogWrite(in2,0);
        analogWrite(in3, 0);
        analogWrite(in4,255);
        }

        else if ( myData.xPosition == 0){
        Serial.println("right");
        digitalWrite(enB,HIGH);
        digitalWrite(enA, HIGH);
        analogWrite(in3 , 255);
        analogWrite(in4 , 0);
        analogWrite(in1, 255);
        analogWrite(in2,0);
        }
        else if ( myData.yPosition >=600){
          Serial.println("up");
          digitalWrite(enA,HIGH);
          digitalWrite(enB,HIGH);
          analogWrite(in3,255);
          analogWrite(in4,0);
          analogWrite(in1,255);
          analogWrite(in2,0);
          
        }
        else if ( myData.yPosition == 0){
          Serial.println("down");
          digitalWrite(enA,HIGH);
          digitalWrite(enB,HIGH);
          analogWrite(in3,0);
          analogWrite(in4,255);
          analogWrite(in1,0);
          analogWrite(in2,255);
          }
      delay(1000);
    
      analogWrite(in3,0);
      analogWrite(in4,0);
      analogWrite(in1,0);
      analogWrite(in2,0);
        digitalWrite(enA,LOW);
      digitalWrite(enB,LOW);
    }
}    
