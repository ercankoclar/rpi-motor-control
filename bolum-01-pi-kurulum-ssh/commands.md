# Bölüm 01 – OS / Wi-Fi / SSH
Bölüm 1 de kullanılan komutlar burada yer alır

## Font  Komutları 
```bash
sudo dpkg-reconfigure console-setup
```
## Wifi Komutları
```bash
sudo nmcli dev wifi rescan
nmcli dev wifi list
sudo nmcli dev wifi connect "SSID_ADI" password "SIFRE" ifname wlan0
```
## SSH Komutları
```bash
sudo systemctl enable --now ssh 
ssh-keygen -t ed25519 -a 64 -f ~/.ssh/pi_ed25519
cat ~/.ssh/pi_video.pub | ssh -o IdentitiesOnly=yes ercankoclar@192.168.1.12 "mkdir -p ~/.ssh && chmod 700 ~/.ssh && cat >> ~/.ssh/authorized_keys && chmod 600 ~/.ssh/authorized_keys"
ssh -o IdentitiesOnly=yes -i ~/.ssh/pi_video ercankoclar@192.168.1.12
sudo nano /etc/ssh/sshd_config 
```
## Aşağıdaki ayarlar bulunup aynısı yapılır 
  -  PubkeyAuthentication yes
  -  PasswordAuthentication no
  -  KbdInteractiveAuthentication no
  -  ChallengeResponseAuthentication no
```bash
sudo systemctl restart ssh 
```