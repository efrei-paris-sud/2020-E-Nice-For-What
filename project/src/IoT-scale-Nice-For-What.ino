/*
 * At first, we worked with Blynk app so we watched this video : 
 * https://www.youtube.com/watch?v=9fyj5zvEl38&ab_channel=IoTFlair
 * 
 * And used this code for reading the weight and to get the HX711.cpp and HX811.h:
 * https://github.com/iotflair/ESP32-Scale-Blynk/blob/master/ESP32-Scale-Blynk.ino
 * 
 * For the Wi-Fi connection we used the code from our Lab4 exercise 3
 * 
 */

#include "ThingSpeak.h"
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
