#include<LiquidCrystal_I2C_Hangul.h>
#include<Wire.h>

LiquidCrystal_I2C_Hangul lcd(0x3F, 16, 2); 


//progress bar character for brightness
byte pBar[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("Loading");
  lcd.createChar(0, pBar);
}

void loop() {
  for (int j = 0; j < 1024; j++) {
    int brightness = map(j, 0, 1024, 0, 255);
    int pBari = map(brightness, 0, 255, 0, 17);
    for (int i = 0; i < pBari; i++)
    {
      lcd.setCursor(i, 1);
      lcd.write(byte(0));
    }
  }
}
