// Scott Clandinin - 2016
//
// ----------------------
// DS3231:  SDA pin   -> Arduino Analog 4 or the dedicated SDA pin
//          SCL pin   -> Arduino Analog 5 or the dedicated SCL pin

#include <DS3231.h> 
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 15     // make this higher to slow down

DS3231  rtc(SDA, SCL);
// Init a Time-data structure
Time  t;

int pir = 13;               // choose the input pin (for PIR sensor)
int test_button = 11;               // choose the input pin (for PIR sensor)
 
void setup() {
  Serial.begin(9600);
  
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  pinMode(pir, INPUT);     // declare sensor as input
  pinMode(test_button, INPUT);     // 
  
  rtc.begin();
  //The following lines can be uncommented to set the date and time
//  rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
//  rtc.setTime(23, 15, 0);     // Set the time to 12:00:00 (24hr format)
//  rtc.setDate(22, 8, 2016);   // Set the date to January 1st, 2014
}
 
 
void loop() 
{
  int test_val;
  
  test_val = digitalRead(test_button);  // read input value
  if (test_val == HIGH)
  {
    light_test();
  }
  
  // Get data from the DS3231
  t = rtc.getTime();
  
  if (t.hour == 21 || t.hour == 22 || t.hour == 23 || t.hour == 24 || t.hour == 1 || t.hour == 2 || t.hour == 3 || t.hour == 4 || t.hour == 5 || t.hour == 6 || t.hour == 7 || t.hour == 8)
  {
    lights();
  }

   delay(100);
   analogWrite(BLUEPIN, 0);
   analogWrite(REDPIN, 0);
   analogWrite(GREENPIN, 0);
 
}

/**************************************************************************
Light display triggered by the motion detector. Only works during the 
hours of 9PM and 8AM.
**************************************************************************/
void lights()
{
  int r, g, b;
  int val;

 
 val = digitalRead(pir);  // read input value
 
 while (val == HIGH)
 {
  // fade in blue
  for (b = 0; b < 255; b++) 
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from blue to violet
  for (r = 0; r < 255; r++) 
  { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for  (b = 255; b > 0; b--)
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 255; g++) 
  { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) 
  { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 255; b++) 
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  }
  // fade from teal to blue
  for (g = 255; g > 0; g--) 
  { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  }   
  // fade out blue
  for  (b = 255; b > 0; b--)
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
   val = digitalRead(pir);  // read input value 
 }
}


/**************************************************************************
A capacitive touch sensor is used to test the lights outside of 
operating hours.
**************************************************************************/
void light_test()
{
  int r, g, b;
 
 
  // fade in blue
  for (b = 0; b < 255; b++) 
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from blue to violet
  for (r = 0; r < 255; r++) 
  { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from violet to red
  for  (b = 255; b > 0; b--)
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  // fade from red to yellow
  for (g = 0; g < 255; g++) 
  { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  } 
  // fade from yellow to green
  for (r = 255; r > 0; r--) 
  { 
    analogWrite(REDPIN, r);
    delay(FADESPEED);
  } 
  // fade from green to teal
  for (b = 0; b < 255; b++) 
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  }
  // fade from teal to blue
  for (g = 255; g > 0; g--) 
  { 
    analogWrite(GREENPIN, g);
    delay(FADESPEED);
  }   
  // fade out blue
  for  (b = 255; b > 0; b--)
  { 
    analogWrite(BLUEPIN, b);
    delay(FADESPEED);
  } 
  
}
