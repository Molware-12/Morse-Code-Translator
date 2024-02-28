#include <Dictionary.h>

int buzzer = 9;  
int button = 12;
int button2 = 11;
int button3 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  Serial.setTimeout(10);
}

String morse = ""; // Declare a variable to hold received Morse code

void loop() {
  String translation = "";
  noTone(buzzer);
  
  if (digitalRead(button) == LOW) {
    String result = dit(); // Call dit function
    Serial.print(result); // Print result to console
    morse += result; // Accumulate Morse code
  }

  else if (digitalRead(button2) == LOW) {
    String result = dah();
    Serial.print(result); 
    morse += result;
  }
  
  if (digitalRead(button3) == LOW) {
    Serial.println(" "); // prints spaces to make it easier to analyze Morse code letters
    delay(1000); // delay to prevent multiple space prints for a single press
    if (morse.length() > 0) {
        translation = morseToEng(morse); // Translate the accumulated Morse code
        Serial.println(translation); // Print translated text
        morse = ""; // Reset received Morse code
    }
  }
}

String dah() {
  tone(buzzer, 1000);
  delay(850);
  noTone(buzzer);
  delay(400);
  return "-";  // Print Morse code for dah
}

String dit() {
  tone(buzzer, 1000);
  delay(150);
  noTone(buzzer);
  delay(400);
  return ".";  // Print Morse code for dit
}

String morseToEng(String code){
  Dictionary<String, String> mcDict;
  mcDict.set(".-", "A");
  mcDict.set("-...", "B");
  mcDict.set("-.-.", "C");
  mcDict.set("-..", "D");
  mcDict.set(".", "E");
  mcDict.set("..-.", "F");
  mcDict.set("--.", "G");
  mcDict.set("....", "H");
  mcDict.set("..", "I");
  mcDict.set(".---", "J");
  mcDict.set("-.-", "K");
  mcDict.set(".-..", "L");
  mcDict.set("--", "M");
  mcDict.set("-.", "N");
  mcDict.set("---", "O");
  mcDict.set(".--.", "P");
  mcDict.set("--.-", "Q");
  mcDict.set(".-.", "R");
  mcDict.set("...", "S");
  mcDict.set("-", "T");
  mcDict.set("..-", "U");
  mcDict.set("...-", "V");
  mcDict.set(".--", "W");
  mcDict.set("-..-", "X");
  mcDict.set("-.--", "Y");
  mcDict.set("--..", "Z");
  mcDict.set("-----", "0");
  mcDict.set(".----", "1");
  mcDict.set("..---", "2");
  mcDict.set("...--", "3");
  mcDict.set("....-", "4");
  mcDict.set(".....", "5");
  mcDict.set("-....", "6");
  mcDict.set("--...", "7");
  mcDict.set("---..", "8");
  mcDict.set("----.", "9");

return mcDict.get(code);
}
