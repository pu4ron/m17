# M17

* Script de instalação do módulo cross-over DMR2M17 / PI-STAR.
* ATENÇÃO: deve-se ativar o modo DMRGateway para uso do Cross-over DMR/M17.
* Suporte pi-star v4.1.7 e RPI 2/3/4(...)

# COMANDOS DE INSTALAÇÃO

* rpi-rw
* sudo git clone https://github.com/pu4ron/m17.git
* cd m17
* sudo chmod +x install.sh
* sudo chmod 777 install.sh
* sudo ./install.sh
  
![m17](https://github.com/pu4ron/m17/assets/40077152/6d639365-8b4e-47a6-8b6d-4afbd051dc92)

# TALKGROUP
* TG 17 / slot 2

# CONTROLE DE GANHO - SSH
* O ajuste é feito de três em três dB(s) - máximo 18dB positivo e negativo.

***Exemplo:***

* -3 db (default)
* sudo volume -3
 
* +5 db
* sudo volume +5

* Após o ajuste aguarde de 3 a 4 segundos para TX.

# LEIA-ME
* Uma portadora curta (TX) para ativar o modo DMR2M17 (TX/RX).
