import pyautogui as gui
import time
import os
import sys

workshopNumber=sys.argv[1]
datafile = f'./ms{workshopNumber}/inputs.txt'

time.sleep(1)

# auto type test data from text file:
with open(datafile, 'r') as tst:
    time.sleep(5)
    tst = tst.readlines()
    for i in range(0, len(tst), 1):
        gui.typewrite(tst[i])

