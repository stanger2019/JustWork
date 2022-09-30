import sqlite3

with sqlite3.connect('db/database.db') as db:#БАЗА ДАННЫХ
    cursor = db.cursor()
    #ТУТ ПРОИСХОДИТ СОЗДАНИЕ ТАБЛИЦЫ
    query = """ CREATE TABLE IF NOT EXISTS exspences(id INTEGER, name TEXT) """
    cursor.execute(query)