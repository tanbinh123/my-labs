#!/bin/bash
# (під рутом)

# Список встановлених пакетів
dpkg -l

# Оновити локальну базу пакетів
apt update && upgrade

# Встановити та запустити Midnight Commander
apt install mc
mc

# Визначити версію встановленого пакету mc
dpkg -s mc

# Динамічні бібліотеки які використовує mc:
ldd /bin/mc

# Создать пакет(заранее подготовлена директория)
dpkg-deb --build ./hello

# Установить пакет
dpkg -i ~/hello.deb

# Запуск скрипта
hello
