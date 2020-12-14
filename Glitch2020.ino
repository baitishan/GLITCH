// This is the code for "GLITCH", an artwork by baitishan
// more details under www.batishan.wordpress.com


#include <OneWire.h>
#include <DallasTemperature.h>
 
// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  
}
 
 
void loop(void)
{
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  Serial.print("Temperature is: ");
  Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"? 
    // You can have more than one IC on the same bus. 
    // 0 refers to the first IC on the wire
    delay(1000);

  if (sensors.getTempCByIndex(0) > 27) {
    RGB_color(255, 0, 0); // Red)
  } else if (sensors.getTempCByIndex(0) > 26 && sensors.getTempCByIndex(0)< 27){ 
     RGB_color(255, 0, 55); // Magenta
  } else if (sensors.getTempCByIndex(0) > 25 && sensors.getTempCByIndex(0)< 26){ 
     RGB_color(255, 0, 125); // Raspberry
  } else if (sensors.getTempCByIndex(0) > 24 && sensors.getTempCByIndex(0)< 25){ 
    RGB_color(255, 255, 0); // Yellow
  } else if (sensors.getTempCByIndex(0) > 23 && sensors.getTempCByIndex(0)< 24){ 
    RGB_color(0, 255, 0); // Green
  } else if (sensors.getTempCByIndex(0) > 22 && sensors.getTempCByIndex(0)< 23){ 
    RGB_color(0, 255, 255); // Cyan
  } else if (sensors.getTempCByIndex(0) > 21 && sensors.getTempCByIndex(0)< 22){ 
    RGB_color(0, 0, 255); // Blue
  } else if (sensors.getTempCByIndex(0)< 21){ 
    RGB_color(255, 255, 255); // White
  }
}


void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
