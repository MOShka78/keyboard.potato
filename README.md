# Keyboard.Potato
Данная статья расскажет вам, как с помощью картошки создать собственную клавиатуру. Для реализации вам потребуется:

- Arduino UNO; 
- 5 резисторов на 170 кОм;
- Много проводов;

Для начала разберемся, как все работает на физическом уровне. На аналоговые порты через резистор мы подаем постоянное напряжение и одновременно подключаем порты к соответсвующим картошкам. Провод заземления держим в собственной руке. При соприкосновении руки и картошки напряжение уходит на землю, поэтому на порту оно падает и мы это фиксируем.

![Alt-текст](https://github.com/MOShka78/keyboard.potato/blob/main/1%20часть%20для%20заг.png?raw=true))

На месте кнопок находятся ваша рука и картошка.
---

После физической реализации переходим к программной. Зальем в наш Arduino следуюий код.
```C

#define pinW 4
#define pinS 3
#define pinA 2
#define pinD 1
#define pinSpace 0

int timer = 26; //Задержка при проверке и выводе значения в консоль


void setup() {

  pinMode(pinW, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinS, INPUT);
  pinMode(pinD, INPUT);
  pinMode(pinSpace, INPUT);
  
  Serial.begin(9600);
}

void loop() {
//проверяем падение напряжения и выводим результат

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
```
---
Через Arduino UNO мы не можем напрямую воздействовать на нажатие клавиш клавиатуры, поэтому необходимо написать скрипт, который будет считывать значения, отправленные Arduino, и симулировать нажатие клавиш.
Выглядит он следующим образом и написан на языке Python:
```Python
import serial #Подключаем библиотеку для работы с портом последовательной связи
import time #Библиотека для организации задержек в программе
import pyautogui #Библиотека для нажатия клавиш

ArduinoSerial = serial.Serial('com7',9600) # создаем объект порта последовательной связи с именем ArduinoSerial

time.sleep(2) #ждем 2 секунды чтобы установилась последовательная связь
while 1:
    incoming = str (ArduinoSerial.readline()) # считываем данные с последовательного порта связи и печатаем их в виде строки
    print (incoming)

    if 'Space' in incoming:
        pyautogui.press('space')
    if 'Forward' in incoming:
        pyautogui.press('w')
    if 'back' in incoming:
        pyautogui.press('s')
    if 'left' in incoming:
        pyautogui.press('a')
    if 'Right' in incoming:
        pyautogui.press('d')
    incoming = ""  //обнуляем значение
```
