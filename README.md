# Seats

An award-winning accessibility project which used an arduino-based sensor array and an iPhone application to direct blind students to open Seats in college dining halls.

Founding members: Juan Suarez, Lurein Perera, Yinzhe Ma, Estevan Feliz and Jay Agrawal.

Current Stage: Working Prototype, R&D to increase cost efficiency, Open to funding.


## Arduino Script Details
**Author:** Estevan Feliz<br/>**Language:** C++<br/>**Description:** This is the script that ran on the Arduino board. It monitors all of the hardware/sensors & then pushes that data through serial communication to the server running a local Python script. After the Python script receives the data, it parses the information & pushes it to our web server. We were using PHP for the primary backend language & all the data was stored as JSON objects. Refer to the PHP files for further information on how that worked.

## iOS App Details
**Author:** Juan Suarez <br/> **Language:** Swift<br/>**Description:** This application read data from our API and displayed this on an iPhone screen, consistent with Apple's accessibility guidelines making it easy to navigate with audio guidance.


## BrailleTouch App Details
**Author:** Lurein Perera <br/> **Language:** Swift<br/>**Description:** This application was supplemental to the Seats dining hall solution, utilizing OCR to translate dining hall menus directly into braille.

## API Pusher Script
**Author:** Yinzhe Ma <br/> **Language:** Python<br/>**Description:** This read data from the Arduino and pushed it to our PHP API Server

## PHP Script
**Authors:** Jay Agrawal, Estevan Feliz <br/> **Language:** PHP<br/>**Description:** This was our backend for the project, all arduino sensors would push their data to this, and the various applications would read from this API
