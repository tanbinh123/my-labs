#!/bin/bash
# (під рутом)

# Спочатку встановлюємо lvm і reiserfs
apt install lvm2
apt install reiserfsprogs

# Створюємо файли
dd if=/dev/zero of=/home/loop0 bs=100M count=10
dd if=/dev/zero of=/home/loop1 bs=100M count=10

# Представляємо у вигляді дисків
cd /home
losetup -fP loop0
losetup -fP loop1

# Перевіряємо під якими номерами вони з'явились(2 останніх loopX):
lsblk

# Створюємо volume group та logical volume
vgcreate VG /dev/loopX1 /dev/loopX2
lvcreate -L 1200M -n test VG
lvcreate -L 300M -n newdata VG
lsblk

# Створюємо файлові системи та перевіряємо результат
mkfs -t ext4 /dev/VG/test
mkfs -t reiserfs /dev/VG/newdata
lsblk -f
