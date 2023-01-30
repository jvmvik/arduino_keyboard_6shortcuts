# VSCode HID keyboard shortcut over USB using Arduino Nano 33 

## Code
[source code](keyboard_6shortcuts.io)
- setup() initialize the input and serial ports for debugging.
- loop() enables checking each shortcut incrementally.

## Electronic
Each button is connected as a regular input following this diagram:
![Connection](diagram.svg)

The digital I/O are located on the right side of the Arduino Nano 33 from D2 to D12.
where D2 is the pin 2 that must be configured as INPUT in the `setup()` function.
![Arduino pin](arduino_nano_pinout.png)

[cheat sheet](https://docs.arduino.cc/tutorials/nano-33-ble-sense/cheat-sheet)

## Conclusion
The final build looks like this:
![final build](breadboard.jpg)
