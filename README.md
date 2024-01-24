# M17

* Script de instalação do módulo cross-over DMR2M17 / PI-STAR.
* ATENÇÃO: deve-se ativar o modo DMRGateway para uso do Cross-over DMR/M17.
* Suporte pi-star v4.1.7 e RPI 2/3/4(...)

# COMANDOS DE INSTALAÇÂO

* rpi-rw
* sudo git clone https://github.com/pu4ron/m17.git
* cd m17
* sudo chmod +x install.sh
* sudo chmod 777 install.sh
* sudo ./install.sh
  
![m17](https://github.com/pu4ron/m17/assets/40077152/6d639365-8b4e-47a6-8b6d-4afbd051dc92)

# TALKGROUP

* TG 17 / slot 2, porém estamos trabalhando com DMRGateway: 5000017 / slot 2
* TG 5000017 / slot 2

# CONTROLE DE GANHO - SSH
* O ganho é ajustado de três em três dB(s) - máximo 18 dB positivo e negativo.

***Exemplo:***

* -3 db (default)
sudo volume -3
 
* +5 db
sudo volume +5
