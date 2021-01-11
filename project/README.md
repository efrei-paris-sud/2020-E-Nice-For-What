
# Project Title : Scale+ 



**Description:**  

Scale+ is a connected scale that reads the weight using sensors. This scale is connected through a Wi-Fi network from a smartphone for example. From the ThingSpeak platform, the user will be able to see their weight directly on the dedicated dashboard and will be able to follow the evolution of their weight thanks to a graph according to days, weeks and months. 
 - [x] **When you apply pressure on the load cells, the strain gauge will determine the variation and convert the weight in a unit of measurement.** 
 - [x] **Raw data are calibrated to SI units**
 - [x] **Data is transmitted to the platform through Wi-Fi connection**
 - [x] **The IoT platform used is ThingSpeak**
 
First, the user get on the scale, the weight is displayed on the OLED screen. Then, the user select his user id in the serial monitor, wait until the weight is stabilized and the value is sent to the IoT platform. Finally, the platform store the data and display a graph with the historic of the weight.


# Scale+ Video

 [Scale+ Video of the project](https://youtu.be/EP7MpaAjP2Q)

# Main components
- 1 x ESP32
- 1 x HX711
- 4 x 50KG Load Cells
- OLED screen
- Breadboard
- Wires


# Schematic
![schema](/Scale+_Schematic.PNG)

# Overview on the code


```#include "ThingSpeak.h"
#include <WiFi.h>
#include "HX711.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Adafruit_SSD1306.h>
#include <WiFiClient.h>
#define DOUT  2
#define CLK  12

Adafruit_SH1106 display(23);

char ssid[] = "Billy";   // your network SSID (name) 
char pass[] = "billy123";   // your network password

WiFiClient  client;

unsigned long myChannelNumber = 1279151;
const char * myWriteAPIKey = "PLRAMVJRKKOXIOMP";

HX711 scale(DOUT, CLK);
float weight = 0;
float calibration_factor = - 22500;

void setup() {
 Serial.begin(9600);
  display.begin();  // initialize oled display
  display.clearDisplay(); // clear the display

 WiFi.mode(WIFI_STA);
 ThingSpeak.begin(client);  // Initialize ThingSpeak
 Serial.println("Welcome to Scale+ ! ");
  scale.set_scale();
  scale.tare(); //Reset the scale to 0
  delay(2000);
}

void loop() {

    /* ------- Connection to WiFi ------- */
 if(WiFi.status() != WL_CONNECTED){
   Serial.print("Attempting to connect to SSID: Billy");
   while(WiFi.status() != WL_CONNECTED){
     WiFi.begin(ssid, pass); // initialize the connection
     Serial.print(".");
     delay(2000);
   } 
   Serial.println("\nConnected.");
 }

 /* ------- Reading the weight ------- */
  scale.set_scale(calibration_factor);
  Serial.print("Reading: ");
  weight = scale.get_units();
  Serial.print(weight, 1);
  Serial.print(" kg");
  Serial.println();

        /* ------- OLED Display ------- */
  display.setCursor(0, 5);
  display.setTextColor(WHITE);
  display.setTextSize(1);  
  display.println("Weight Scale");

  display.setCursor(30, 25);
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.println(weight);
  
  display.display();
  delay(1500);
  display.clearDisplay();
  display.display();
  delay(1500);

        /* ------- Make many users -------- */

 if(Serial.available())
  {
    char temp = Serial.read();
    if(temp == '1')
    {
      int x = ThingSpeak.writeField(myChannelNumber, 1, weight, myWriteAPIKey);
      delay(2000);
    }
    else if (temp == '2')
    {
      int x = ThingSpeak.writeField(myChannelNumber, 2, weight, myWriteAPIKey);
      delay(2000);
    }
    else if (temp == '3')
    {
      int x = ThingSpeak.writeField(myChannelNumber, 3, weight, myWriteAPIKey);
      delay(2000);
    }
  }
}
``` 


