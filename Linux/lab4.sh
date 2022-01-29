#!/bin/bash

# Cтворити каталоги abc, def
mkdir abc def

# Створити у кожному з каталогів файли, назви яких -
# це перші слова з рядків, які починаються з B файлу city.txt,
# вміст - унікальні рядки з city.txt
grep -o '^B[a-z]*' city.txt | sort | uniq |
xargs -I{} sh -c 'sort city.txt | uniq | tee abc/{} def/{}'

# Знайти файли, імена яких коротші 7 символів, та змінити ім’я на ім’я.new
find abc/ def/ | egrep '/[0-Z]{1,7}\>' | xargs -I{} mv {} {}.new

# Знайти всі файли, імена яких закінчуються на .log у підкаталогах /var
# та вивести кількість рядків у кожному з цих файлів
sudo find /var | egrep -o '.*\.log\>' | sort | uniq | xargs sudo wc -l
