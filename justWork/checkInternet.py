import socket

def internet():#ПРОВЕРКА НА НАЛИЧИЕ ИНТЕРНЕТА
    try:
        socket.gethostbyaddr('www.yandex.ru')
        return True
    except socket.gaierror:
        return False