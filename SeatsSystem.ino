/*
  Hello World.ino
  2013 Copyright (c) Seeed Technology Inc.  All right reserved.

  Author:Loovee
  2013-9-18

  Grove - Serial LCD RGB Backlight demo.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

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
