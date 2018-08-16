#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;
const int TouchPin=8;
int idNumber = 1;
int sensorValue = 0;
bool seatInUse = false;

void setup() 
{
    Serial.begin(9600);
    pinMode(TouchPin, INPUT);
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.

    delay(1000);
}

void sendSerialData(){
  Serial.print("sensorID:");
  Serial.print(idNumber);
  Serial.print(";");
  Serial.print("status:");
  Serial.print(seatInUse);
}

void updateUI(){
  lcd.setCursor(0, 0);
  lcd.print("SensorID: ");
  lcd.print(idNumber);
  lcd.setCursor(0, 1);
  lcd.print("Status: ");
   if (seatInUse == true){
     lcd.print("Taken");
   } else {
     lcd.print("Open ");
   }
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    sensorValue = digitalRead(TouchPin);
    if(sensorValue==1)
    {
        seatInUse = true;
    }
    else
    {
        seatInUse = false;
    }
    updateUI();
    sendSerialData();
    
    delay(100);
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
