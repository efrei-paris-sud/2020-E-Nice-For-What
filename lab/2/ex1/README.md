
## UART Protocol 
  

First of all, we will begin with one of the most basic communication protocol in electronics : UART protocol
> UART stands for Universal Asynchronous Receive Transmit

This protocol is the most popular. It needs two wires to assure the communication between two devices. The goal here is to read easily and writing data from external devices. 

## **Exercise 1** : 

To implement this protocol we will build an arduino program which can read byte from serial and adjust the passive buzzer frequency with that. 

To do that, we will use the former program that we were able to do in the Lab 1 and we will modify so that it corresponds to what is expected here. 

Here is the code that corresponds to the passive buzzer that we have modified in order to change the frequency and read the value : 
<br>

## Code 
<br>

```
const int buzzer = 5; //buzzer to arduino pin 5

void setup(){
  Serial.begin(9600); // initialize serial:
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 5 as an output
}

void loop(){
 
 // if there's any data available, read it:
  while (Serial.available() > 0) {

    int i  = Serial.parseInt();    // look for the next valid integer in the incoming serial stream:
    byte b = Serial.read();    // look for the next valid byte in the incoming serial stream:
    if (i!=0)
    {
      tone(buzzer, i);
      delay(1000);
      Serial.print("sound");
    }
  }
}
```

## I2C 

I2C is another communication protocol that is used specificly to interact with sensors, memory devices and LCDs. Unlike UART Protocol, I2C is a synchronous protocol. 

> I2C stands for Inter Integrated Circuit 