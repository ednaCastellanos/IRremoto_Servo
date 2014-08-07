#include <Servo.h>
#include <IRremote.h>

#define code1 255
#define code2 51765
Servo myservo;
int pos = 0;
int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  myservo.attach(9);
  Serial.println("LEYENDO");
}

void loop(){
  if (irrecv.decode(&results)) {  
    unsigned int value = results.value;
    Serial.println(value);
    irrecv.resume();
    switch(value){
    case code1:
      for(pos = 0; pos < 180; pos+=1)
      {
        myservo.write(pos);
        delay(15);
      }
      break;
    case code2:
      for(pos = 180; pos >= 1; pos-=1)
      {
        myservo.write(pos);
        delay(15);
      }
      break; 
    }
}
  delay(1000);
}


