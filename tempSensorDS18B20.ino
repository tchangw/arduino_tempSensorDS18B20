
/* LiquidCrystal Library
   One Wire Digital Temperature Sensor - DS18B20

Demonstrates the use of a 16x2 LCD display. The LiquidCrystal
library works with all LCD display that are compatible with 
the Hitachi HD44780 driver. There are many of them out there,
and you can usually tell them by the 16-pin interface.

The circuit for LCD:
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
* 47K resistor:
* ends to +5V and ground
* wiper to LCD VO pin (pin 3)

The circuit for 18B20 temp sensor
* sensor GND to 0V
* sensor Vdd to +5V
* sensor DQ to digital pin 7 
   ________
   | 1 2 3 | (bottom view)
    \_____/

    _________
    | 18B20 |
    | 1 2 3 |
    |       |
    |_______|
     |  |  |
     |  |  |
     |  |  |
    GND DQ Vdd
    
* Dallas Temperature library for Arduino
* http://www.milesburton.com/?title=Dallas_Temperature_Control_Library
* Download library. Will find 2 folders
*   - Dallas Temperature (file folder)
*   - OneWire (file folder)
*   - README

* Drag and drop the Dallas Temperature folder into your arduino/libraries folder
* If you don't already have OneWire library then you will need to copy that folder into the libraries folder also.


*/

// include the library code:
#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>    // Include the library to use a LCD display

#define ONE_WIRE_BUS 7

// Setup a oneWire instance to communicate with any OneWire devices
// (not just Maxim/Dallas ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature
DallasTemperature sensors(&oneWire);
//DeviceAddress insideThermometer = {0x28, 0x94, 0xE2, 0xDF, 0x02, 0x00, 0x00, xFE};
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float temperature;

void setup(){
  
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  
  // Start up the library
  sensors.begin();
  
  // set up the LCD's number of rows and columns
  lcd.begin(16, 2);
  lcd.print("Temperature: ");
}

void loop(){
 
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();  // Send the command to get temp
  Serial.println("DONE");

  Serial.print("Temperature for Device 1 is: ");
  temperature = sensors.getTempCByIndex(0);
  // You can have more than one IC on the same bus.
  // 0 refers to the first IC on the wire
  
  lcd.setCursor(0,1);          // Moves the cursor of the display to the next line
  lcd.print(temperature);
  lcd.print(" C");  

 
}

