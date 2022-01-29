#!/bin/bash

# Cтворити newfile.txt, записавши в нього кількість рядків, де є слова,
# що починаютьcя на B, R, S та закінчуються на а, n з city.txt
egrep -c '\<[BRS][^ ]*[an]\>' city.txt > newfile.txt

# Дописати у newfile.txt за алфавітом у зворотному порядку рядки,
# що закінчуються на 6 або 8 з файлу city.txt
egrep '[68]$' city.txt | sort -r >> newfile.txt

# Вивести newfile.txt
cat newfile.txt

# Виконати ls, stdout перенаправити у result.txt, а stderr у error.txt
ls > result.txt 2> error.txt

# Вибрати з файлу /etc/passwd користувачів, в яких є /bin/bash,
# визначити їх домашній каталог, та вивести список файлів у ньому
grep '/bin/bash' /etc/passwd | cut -d":" -f6 | xargs sudo ls
