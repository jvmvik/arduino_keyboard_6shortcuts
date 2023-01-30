#include "PluggableUSBHID.h"
#include "USBKeyboard.h"

USBKeyboard Keyboard;

/***
 * VSCode HID keyboard shortcut over USB
 * using Arduino Nano 33 
 * 
 * tested on Mac OSX Jan 2023
 *  with Arduino nano 33
 * 
 * Short cut examples:
 *  - duplicate line with a simple single input button  (default shortcut)
 *  - run task (default shortcut)
 *  - Toggle to zen mode (non default shortcut)
 *
 * Library source code
 * https://github.com/arduino/ArduinoCore-nRF528x-mbedos/blob/master/libraries/USBHID/USBKeyboard.cpp
 */

const int ledPin = LED_BUILTIN;
volatile int states[] = {LOW, LOW, LOW, LOW, LOW, LOW};
volatile int states_[] = {LOW, LOW, LOW, LOW, LOW, LOW};
volatile bool ready = true;

// raw keycodes can be imported from here https://gist.github.com/MightyPork/6da26e382a7ad91b5496ee55fdc73db2#file-usb_hid_keys-h
// duplicate line short cut in vscode (default)
#define KEY_COMMAND 0x08 // command
#define KEY_CONTROL 0x01 // left control
#define KEY_D       0x07 // d
#define KEY_F9      0x42 // F9
#define KEY_Z       0x1d // z

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(2, INPUT); // duplicate
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
}

void shortcut(int index, int button, int key, int modifier) {
  // read single button
  states[index] = digitalRead(button);
  if (states_[index] != states[index]) {
    if (states[index] == HIGH) 
    {
      Serial.println(button);
   //   Serial.println(button);
   //   Serial.println(key);
   //   Serial.println(modifier);
      digitalWrite(ledPin, HIGH);
      Keyboard.key_code_raw(key, modifier);
    } 
    else 
    {
      digitalWrite(ledPin, LOW);
    }
    states_[index] = states[index];
    delay(50);
  }
}

void loop() 
{
  if(ready) {
    Serial.println("ready!");
    ready = false;
    delay(1000);
  }

  // duplicate line
  shortcut(0, 2, KEY_D, KEY_COMMAND);

  // run task build
  shortcut(1, 3, KEY_F9, KEY_COMMAND);

   // zen mode toggle 
  shortcut(5, 7, KEY_Z, KEY_CONTROL);

  delay(10);
}


