import pyautogui
import pyperclip
import time
import random

time.sleep(5)

with open("test.txt", encoding="utf-8") as file:
    for line in file:
        for i in line:
            if i=='\n':
                break
            time.sleep(random.uniform(0.05, 0.2))  # Random delay between 0.1 and 0.3 seconds
            pyperclip.copy(i)
            pyautogui.typewrite('{}'.format(i))
        time.sleep(random.uniform(0.1, 0.2))