from tkinter import *
import serial
import time
import threading
import continuous_threading
import tkinter.font

font = "Comic Sans MS","90","bold"

arduino = serial.Serial('COM6',9600)

def reading():
    data = arduino.readline().decode().strip()
    data = int(data)
    label.configure(text = data)
    if data < 10:
            label.configure(text = data,font = font,bg = 'red')
    else:
            label.configure(text = data,font = font,bg = 'green')
            

height = 300
width=400

t1 = continuous_threading.PeriodicThread(0.5,reading)


win = Tk()
win.title('sample project')
win.geometry('600x400')
win.config(background='cyan')



label = Label(win,text = 'OK',font = font,bg = 'green')
label.place(x=100,y=50,height = height,width=width)

t1.start()
win.mainloop()





