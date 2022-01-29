#!/bin/bash

# Cкопіювати файл /etc/passwd в поточний каталог
cp /etc/passwd ./pass.txt

# Вивести файли
cat test.txt city.txt pass.txt

# Кількість рядків
wc -l test.txt city.txt pass.txt

# Вивести з кожного рядка pass.txt 3 та 1 поле
cut pass.txt -d':' -f3,1

# Вивести перші 3 рядки з pass.txt
head -3 pass.txt

# Вивести city.txt з сортуванням за алфавітом
sort city.txt

# Вивести city.txt з виконанням заміни a на b
sed 's/a/b/g' city.txt

# Вивести з city.txt рядки в яких є Spain
grep Spain city.txt

# Розділити city.txt на файли по 3 рядки
split city.txt -3
