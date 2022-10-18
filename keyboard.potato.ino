#include <Wire.h>

#define pinW 4
#define pinS 3
#define pinA 2
#define pinD 1
#define pinSpace 0

int timer = 26;


void setup() {
  pinMode(pinW, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinS, INPUT);
  pinMode(pinD, INPUT);
  pinMode(pinSpace, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (analogRead(pinSpace) > 1000) {Serial.println(" "); delay (timer);}
  else {Serial.println("Space"); delay (timer);}
  //if (analogRead(pinW) > 1000) {Serial.println(" ");delay (timer);}
  //else {Serial.println("Forward");delay (timer);}
  if (analogRead(pinA) > 1000) {Serial.println(" ");delay (timer);}
  else {Serial.println("Left");delay (timer);}
  if (analogRead(pinS) > 1000) {Serial.println(" ");delay (timer);}
  else {Serial.println("Back");delay (timer);}
  if (analogRead(pinD) > 1000) {Serial.println(" ");delay (timer);}
  else {Serial.println("Right");delay (timer);}
}