# Bölüm 03 – PWM / DC Motor Sürme / PIGPIO Kütüphanesi
Bölüm 3 de kullanılan komutlar burada yer alır

## PIGPIO  Komutları 
```bash
sudo nano /etc/apt/sources.list.d/raspi.list
```
## Açılan sayfaya aşağıdaki yol yazılır ve kayıt edilip çıkılır
- deb http://archive.raspberrypi.org/debian/ bookworm main

```bash
curl -fsSL https://archive.raspberrypi.org/debian/raspberrypi.gpg.key \ | sudo gpg --dearmor -o /usr/share/keyrings/raspberrypi-archive-keyring.gpg
sudo apt update
sudo apt install pigpio pigpio-tools
sudo systemctl enable pigpiod
sudo systemctl start pigpiod
systemctl status pigpiod
pigs t
```
## Derleme ve Çalıştırma Komutları
```bash
gcc pwm_test.c -o pwm_test -lpigpiod_if2 -lrt -lpthread
./pwm
```
