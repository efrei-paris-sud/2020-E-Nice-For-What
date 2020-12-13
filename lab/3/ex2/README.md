# Step 4 : Display "Hello Word"

## **Exercice 2 :**

In this second exercise, we want to display some sentences such as "Hello World".

We will first go on Arduino IDE and follow this path :

> `File` -> `Examples` -> `Adafruit SH1106` -> `I2C`

Using the same schematic as in the step 2 we will use the following code : 

## **Code**

``` 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

Adafruit_SH1106 display(23);

void setup()   {
  display.begin();  // initialisation de l'afficheur
  display.clearDisplay(); // ça efface à la fois le buffer et l'écran
}

void loop() {
  display.setCursor(30, 15);  // coordonnées du point de départ du texte
  display.setTextColor(WHITE);
  display.setTextSize(1);  // taille par défaut
  display.println("Hello");
  display.setCursor(30, 25);  // coordonnées du point de départ du texte
  display.setTextSize(2);  // taille double
  display.println("World !");
  display.display();
  delay(1000);
  //
  display.clearDisplay();
  display.display();
  delay(1000);
  // 
}

``` 

## **Board Image**

![](step4.JPG)

We can see that the "Hello World" we had defined in the code was well displayed on the OLED with the right text size and the desired color.