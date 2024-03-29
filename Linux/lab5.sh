#!/bin/bash

# Виконати команду sleep 1000, запам’ятати PID
sleep 1000

# Перевести виконання у фоновий режим:
# Ctrl + Z
bg

# Iдентифікатор батьківського процесу
ps
ps j [PID]

# Знайти процес у дереві процесів
pstree -h

# Знайти у списку процесів та припинити виконання
top -p [PID]
kill [PID]

# Вивести ід та команди запущених процесів, які у стані виконання 
ps -Al | grep '\<[0-9]* R'
