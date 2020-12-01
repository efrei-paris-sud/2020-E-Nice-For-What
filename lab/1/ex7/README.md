# Step 9 : RGB LED

## **Exercise 7**:

In this last exercise, we want to create a program that can produce any color with a RGB LED, with a delay of 1 second. 

The associated program to test the RGB LED is as follow :
## Code
```
int red_pin=11;
int green_pin = 10;
int blue_pin = 9;
void setup() {
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
}
void loop() {
  setColor(255, 0, 0); // Red
  delay(1000);
  setColor(0, 255, 0); // Green
  delay(1000);
  setColor(0, 0, 255); // Blue
  delay(1000);

}
void setColor(int red, int green, int blue)
 {
  analogWrite(red_pin, red);
  analogWrite(green_pin, green);
  analogWrite(blue_pin, blue);
}
```

We tested this program and we obtained the result below : 

![](step9-issue.gif)

# - Issue :

>As we can see here, we only have 2 colors, which are red and green instead of the 3 that we implemented in the code. 

>At first, we though it was a physical manipulation problem with the wires and the micro-controller.

>After rechecking our connections, we figured it might be a problem in our code. But we still couldn't find the problem.  

> So we thought about swapping our RGB LED with another group's to see if the problem was the LED. And we get the following result : 

![](step9-noissue.gif)

Finally here, you can see that the color blue appears well on our RGB LED. 

We can conclude that our only problem was a defective LED.




