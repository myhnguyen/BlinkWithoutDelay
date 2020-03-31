/*
  BlinkWithoutDelay
*/
const int Red=12;// the number of the LED pin
const int Green=33;// the number of the LED pin
const int Blue=27;// the number of the LED pin


int ledState=LOW;// Set to LOW
unsigned long preMillis=0;// will store last time LED changed

const long interval=1000;// interval in milliseconds
int color=0;//Counter

void setup() {
  // set digital pin as output:
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);  
  pinMode(Blue, OUTPUT);
}

void loop() {  
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long curMillis=millis();
  
  if(curMillis-preMillis>=interval) 
  {
    //Save the last time Led blinked
    preMillis=curMillis;
  
    //if the LED is off turn it on or off
    if(ledState==LOW) 
    {
      ledState=HIGH;    
      color+=1;//color changes to next
    }
    else 
    {
      ledState=LOW;
    }     

    //checks the modulo and sets to different colors
    if(color%6==0)
    {
      digitalWrite(Blue, ledState);     
    }
    else if(color%4==0)
    {
      digitalWrite(Green, ledState);  
    }
    else if(color%2==0)
    {
      digitalWrite(Red, ledState); 
    }   
  }
 } 
  
