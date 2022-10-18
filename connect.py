import serial #подключаем библиотеку для работы с портом последовательной связи
import time #библиотека для организации задержек в программе
import pyautogui
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
    incoming = ""
