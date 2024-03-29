#!/bin/bash

# Визначити свою IP-адресу
ifconfig

# Визначити IP-адресу шлюзу за замовчанням
route

# Визначити IP вузла google.com.ua
host google.com.ua

# Визначити ім’я вузла 8.8.8.8
host 8.8.8.8

# Чи доступний по мережі 127.0.0.1
ping 127.0.0.1

# Знайти перші 3 маршрутизатори на шляху до google.com
traceroute -m 3 google.com

# Чи доступний по мережі kpi.ua, та  визначити середній час проходження пакетів
ping kpi.ua -c5
