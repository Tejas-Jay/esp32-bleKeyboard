#include <BleKeyboard.h>

BleKeyboard bleKeyboard("SamsungKeyboard", "ESP32", 100);

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
}

void typeText(const char* text, int delayTime = 50) {
  while (*text) {
    bleKeyboard.write(*text);
    delay(delayTime); 
    text++;
  }
}

void loop() {
  if (bleKeyboard.isConnected()) {
    delay(2000);

    bleKeyboard.press(KEY_LEFT_GUI);
    bleKeyboard.press('r');
    bleKeyboard.releaseAll();
    delay(500);

    typeText("cmd");
    bleKeyboard.write(KEY_RETURN);
    delay(1000);

    Serial.println("Sending keys...");

    typeText("start www.google.co.in");
    bleKeyboard.write(KEY_RETURN);  
    delay(3000);

    Serial.println("In Google!");

    bleKeyboard.press(KEY_RIGHT_CTRL);
    bleKeyboard.press('h');
    bleKeyboard.releaseAll();

    while(1);
  }
}
