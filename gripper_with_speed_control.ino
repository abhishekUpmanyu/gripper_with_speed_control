#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//pin definitions
#define FPIN A0
#define BPIN A1
#define LPIN A2
#define RPIN A3
#define GFPIN 4
#define GBPIN 5
#define GOPIN A6
#define GCPIN A7
#define SUPIN 11
#define SDPIN 12
#define LF 9
#define LB 8
#define RF 7
#define RB 6
#define GF 3
#define GB 2
#define GO 1
#define GC 0
#define PW 10

//global variables
LiquidCrystal_I2C lcd(0x27, 16, 2);
int spd = 9;
char lcd_buffer[3];

void setup() {
	pinMode(FPIN, INPUT);
	pinMode(BPIN, INPUT);
	pinMode(LPIN, INPUT);
	pinMode(RPIN, INPUT);
	pinMode(GFPIN, INPUT);
	pinMode(GBPIN, INPUT);
	pinMode(GOPIN, INPUT);
	pinMode(GCPIN, INPUT);
	pinMode(GC, OUTPUT);
	pinMode(GO, OUTPUT);
	pinMode(GB, OUTPUT);
	pinMode(GF, OUTPUT);
	pinMode(RB, OUTPUT);
	pinMode(RF, OUTPUT);
	pinMode(LB, OUTPUT);
	pinMode(LF, OUTPUT);
	pinMode(PW, OUTPUT);
	pinMode(SUPIN, INPUT);
	pinMode(SDPIN, INPUT);
        analogWrite(PW, 255);
        lcd.begin();
        lcd.backlight();
        lcd.setCursor(4,0);
        lcd.print("PreAlpha");
        lcd.setCursor(7,1);
        lcd.print("10");
        lcd.setCursor(7,1);
        sprintf(lcd_buffer, "%2d", spd);
        lcd.print(lcd_buffer);
}

void loop() {
	if (analogRead(FPIN) >= 500) {
		digitalWrite(LF, HIGH);
		digitalWrite(RF, HIGH);
		while(analogRead(FPIN) >= 500);
		digitalWrite(LF, LOW);
		digitalWrite(RF, LOW);
	} else if (analogRead(BPIN) >= 500) {
		digitalWrite(LB, HIGH);
		digitalWrite(RB, HIGH);
		while(analogRead(BPIN) >= 500);
		digitalWrite(LB, LOW);
		digitalWrite(RB, LOW);
	} else if (analogRead(LPIN) >= 500) {
		digitalWrite(LB, HIGH);
		digitalWrite(RF, HIGH);
		while(analogRead(LPIN) >= 500);
		digitalWrite(LB, LOW);
		digitalWrite(RF, LOW);
	} else if (analogRead(RPIN) >= 500) {
		digitalWrite(LF, HIGH);
		digitalWrite(RB, HIGH);
		while(analogRead(RPIN) >= 500);
		digitalWrite(LF, LOW);
		digitalWrite(RB, LOW);
	} /*else if (analogRead(GFPIN) >= 500) {
		digitalWrite(GF, HIGH);
		while(analogRead(GFPIN) >= 500);
		digitalWrite(GF, LOW);
	} else if (analogRead(GBPIN) >= 500) {
		digitalWrite(GB, HIGH);
		while(analogRead(GBPIN) >= 500);
		digitalWrite(GB, LOW);
	} else if (analogRead(GOPIN) >= 500) {
		digitalWrite(GO, HIGH);
		while(analogRead(GOPIN) >= 500);
		digitalWrite(GO, LOW);
	} else if (analogRead(GCPIN) >= 500) {
		digitalWrite(GC, HIGH);
		while(analogRead(GCPIN) >= 500);
		digitalWrite(GC, LOW);
	}*/ else if (digitalRead(SUPIN) == HIGH) {
		if (spd<10) {
                        spd++;
                        analogWrite(PW, 25.5*spd);
                        lcd.setCursor(7,1);
                        sprintf(lcd_buffer, "%2d", spd);
                        lcd.print(lcd_buffer);
                }
	} else if (digitalRead(SDPIN) == HIGH) {
		if (spd>1) {
                        spd--;
                        analogWrite(PW, 25.5*spd);
                        lcd.setCursor(7,1);
                        sprintf(lcd_buffer, "%2d", spd);
                        lcd.print(lcd_buffer);
                }
	}
}
