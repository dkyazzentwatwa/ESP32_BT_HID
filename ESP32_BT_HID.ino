#include <BleKeyboard.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <U8g2_for_Adafruit_GFX.h>

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

BleKeyboard bleKeyboard("mangocookiez", "cypher", 100);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE HID!");

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  display.display();  // Display Adafruit logo
  delay(2000);
  display.clearDisplay();  // Clear the buffer

  // Initialize U8g2_for_Adafruit_GFX
  u8g2_for_adafruit_gfx.begin(display);
  displayTitleScreen();
  delay(3000);
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.println("Starting Rick Roll Hack....!!!");
    Serial.println("Starting Rick Roll Hack....!!!");
    delay(1000);
    display.display();
    // Open browser home page
    bleKeyboard.write(KEY_MEDIA_WWW_HOME);
    delay(6000);
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Opening Rick Roll Hack....");
    Serial.println("Opening Rick Roll Hack....");
    display.display();
    // URL to open
    const char* url = "https://youtu.be/oHg5SJYRHA0?si=bfXXjVeR5UyKoh4n";

    // Type the URL with a small delay between each character
    for (size_t i = 0; i < strlen(url); i++) {
      bleKeyboard.write(url[i]);
      delay(50);  // Adjust this delay if needed
    }
    delay(500);  // Small delay before pressing enter
    bleKeyboard.press(KEY_RETURN);
    bleKeyboard.releaseAll();
    delay(10000);  // Adjust this delay according to Chrome's load time
    display.setCursor(0, 12);
    display.println("Hack complete....!");
    Serial.println("Hack complete....!");
    display.display();
    delay(1000);
    display.setCursor(0, 24);
    display.println("BT HID Complete....");
    Serial.println("BT HID Complete....");
    delay(2000);
    display.display();

    delay(1000);
  }

  Serial.println("Waiting 5 seconds to connect...");
  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Waiting 5 seconds to connect...");
  display.display();
  delay(5000);
}

void displayTitleScreen() {
  display.clearDisplay();
  u8g2_for_adafruit_gfx.setFont(u8g2_font_adventurer_tr);  // Use a larger font for the title
  u8g2_for_adafruit_gfx.setCursor(20, 40);                 // Centered vertically
  u8g2_for_adafruit_gfx.print("CYPHER BOX");
  display.display();
}