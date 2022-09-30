from kivy.app import App
from kivy.lang import Builder
from kivy.uix.boxlayout import BoxLayout
from kivy.properties import StringProperty
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
#from checkInternet import *
#from options import *
import threading
import socket

#Интерфейс
kv = """
MyBL:
        orientation: "horizontal"

        Label:
                font_size: "30sp"
                text: root.data_label
                
        TextInput:
                id: Inp
                multiline: False
                pudding_y: (5,5)
                size_hint: (1,0.5)

        Button:
                text: "Завести"
                bold: True
                background_color: '#00FFCE'
                size_hint: (1,0.5)
                on_press: root.callback()
"""

class MyBL(BoxLayout):
    data_label = StringProperty("HELLO")

    #СВЯЗЬ С СЕРВЕРОМ, тут ещё есть некоторые ошибки
    def __init__(self, **kwargs):
        super().__init__(**kwargs)
        host = '127.0.0.1'
        port = 3425

        self.client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.client.connect((host, port))
        self.client.sendall(bytes('979879789', 'utf-8'))
        
        threading.Thread(target=self.get_data).start()


    def callback(self):#При нажатиии на кнопку
        print("Отправить")

    def get_data(self):
        while App.get_running_app().running:
            in_data = self.client.recv(4096)
            print("От сервера :", in_data.decode())

    #НА ЭТО НЕ ОБРАЩАЙ ВНИМАНИЯ
    #try:
    #    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    #    client.connect((host, port))
    #    client.sendall(bytes("Контакт установлен!", "utf-8"))
    #    data_label = StringProperty("HELLO")
    #except socket.gaierror:
    #    data_label = StringProperty("ERROR")

class MyApp(App):
    running = True

    def build(self):#прорисовка интерфейса
        return Builder.load_string(kv)

    def on_stop(self):
        self.running = False

MyApp().run()