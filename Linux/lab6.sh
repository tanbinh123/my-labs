#!/bin/bash
# (під рутом)

# Додати трьох користувачів з домашніми каталогами у /home/ім’я
useradd -m Lucia
useradd -m Maria
useradd -m Sofia

# Встановити паролі
passwd Lucia
passwd Maria
passwd Sofia

# Вказати їх прізвища
usermod -c Rodriguez Lucia
usermod -c Fernandez Maria
usermod -c Gonzalez Sofia

# Перенести домашній каталог третього користувача до /home/прізвище
usermod -d /home/Gonzalez Sofia

# Увійти в систему під кожним користувачем
login Lucia
login Maria
login Sofia

# Увійти під першим користувачем, та спробувати переключитись на рута
login Lucia
sudo su
exit

# Змінити shell на інший для другого користувача
usermod -s /bin/bash Maria

# Створити групу та включити до неї створених користувачів
groupadd Spain
usermod -aG Spain Lucia
usermod -aG Spain Maria
usermod -aG Spain Sofia

# Створити каталог /home/Spain та встановити власником Lucia, група Spain
mkdir /home/Spain
chown Lucia /home/Spain
chgrp Spain /home/Spain

# У першому терміналі створити test.txt у каталозі /home/Spain,
# встановити права на нього, щоб тільки цей користувач міг вивести вміст файлу.
# Спробувати вивести вміст у другому терміналі.
touch test.txt
chmod 700 test.txt

# Встановити права на файл, щоб тільки Lucia міг виводити вміст файлу,
# а користувачі з групи мали право змінювати його вміст
cat test.txt
chmod 702 test.txt

# Встановити для Maria строк дії – вчорашню дату. Спробувати увійти в систему
usermod -e 2021-12-12 Maria
login Maria
