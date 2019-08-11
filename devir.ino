#include<Encoder.h> // Adding encoder library

Encoder left_enc(13,0); // Left dc motor encoder output pin is 2.
Encoder right_enc(9,0); //Right dc motor encoder output pin is 5.


void setup() {
 float Input1  = 0;
  float Input2 = 0;


  //turn the PID on

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting...");
 

}
//right dc motor is A left dc motor is B.
float start;
float start_2;
float stop_2=0;
float diff_2;
float stop_=0;
float diff;
float rpm = 0;
float rpm2=0;
long oldPosition  = -999;
long oldPosition2 = -999;
int counter=0;
int counter2 = 0;
int dev;

void loop() {
  start = millis();

  long newPosition = right_enc.read();
  
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    counter++;
    if(counter%40==0){
      diff = start-stop_;
      rpm=1/(diff/60000);
      stop_=start;
  Serial.print("right :\t");Serial.print(rpm);
       Serial.println();
      }
  }
    long newPosition2 = left_enc.read();
    start_2 = millis();
 
  if(newPosition2!=oldPosition2){
    oldPosition2 = newPosition2;
    counter2++;

    if(counter2%40==0){
       
      diff_2=start_2-stop_2;
      
      rpm2=1/(diff_2/60000);
      stop_2=start_2;
   Serial.print("left : \t");Serial.print(rpm2);
    Serial.println();
      }
    
    
    }
  

}
