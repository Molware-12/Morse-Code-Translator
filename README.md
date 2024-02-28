# Morse-Code-Translator
This project is an project idea using an Arduino Uno and using the Arduino IDE which is in C++. 

In the circuit, all the buttons have 2 wires connected to them. 1 wire must be connected to the ground pin (called GND on the arduino uno), and a pin number. For the buzzer, the same thing applies, but a resistor is placed to essentially lower the volume of the buzzer by resisting some of the current going into it. The higher resistance of the resistor, the lower the volume of the buzzer will be. In my case, im using a 1K Ohm resistor.

The code begins with including the necessary libraries and declaring variables for pins connected to the buzzer and buttons. The integer is just the pin number the wires are connected to on the arduino. The button variable refers to the button closest to the buzzer. The button2 variable refers to the right-most button. The button3 variable refers to the left-most button.

In the setup() function, it initializes serial communication, sets pin modes for the buzzer and buttons, and sets the timeout for serial communication.

The loop() function continuously checks the state of the buttons. If one of the buttons is pressed (indicating Morse code input), it emits the corresponding Morse code signal through the buzzer and accumulates the Morse code characters.

The button variable outputs the dit() function when pressed, which is simply a short sound on the buzzer. The button2 variable outputs the dah() function, which is a slightly longer sound on the buzzer. When button3 is pressed, it indicates the end of the Morse code input. At this point, the accumulated Morse code is translated into English characters using the morseToEng() function.

The morseToEng() function takes a Morse code sequence as input and returns the corresponding English character based on a predefined dictionary mapping Morse code to English characters.

This dictionary is created using a custom Dictionary class which can be downloaded as a .ZIP file from https://github.com/KeeganMartin/Dictionary. To use this dictionary, you simply have to download the file as a .ZIP and import it to the arduino IDE by going to Sketch -> Include Library -> Add .ZIP Library. The function simply maps each morse code to its corresponding English character.
The translated English text is then printed to the serial console.
