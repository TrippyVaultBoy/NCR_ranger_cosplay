#include <FastLED.h>

#define NUM_LEDS 14
#define LED_PIN 2

#define EYES_PIN 3
#define FLASHLIGHT_PIN 4

#define FLASH_OUT 5

CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(400);
  
  pinMode(EYES_PIN, INPUT);
  pinMode(FLASHLIGHT_PIN, INPUT);
  
  pinMode(FLASH_OUT, OUTPUT);
  
  digitalWrite(EYES_PIN, HIGH);
  digitalWrite(FLASHLIGHT_PIN, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Eye LEDS: ");
  Serial.println(digitalRead(EYES_PIN));

  Serial.print("Flashlight LED: ");
  Serial.println(digitalRead(FLASHLIGHT_PIN));

  if (digitalRead(EYES_PIN) == LOW && digitalRead(FLASHLIGHT_PIN) == HIGH) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    digitalWrite(FLASH_OUT, LOW);
  }

  if (digitalRead(EYES_PIN) == HIGH && digitalRead(FLASHLIGHT_PIN) == HIGH) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.setBrightness(100);
    FastLED.show();
    delay(random(85,100));
    FastLED.show();
    digitalWrite(FLASH_OUT, LOW);
  }

  if (digitalRead(EYES_PIN) == HIGH && digitalRead(FLASHLIGHT_PIN) == LOW) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.setBrightness(100);
    FastLED.show();
    delay(random(85,100));
    FastLED.show();
    digitalWrite(FLASH_OUT, HIGH);
  }
}
