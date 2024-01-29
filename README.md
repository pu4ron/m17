# M17

* Script de instalação do módulo cross-over DMR2M17 / PI-STAR.
* ATENÇÃO: deve-se ativar o modo *DMRGateway* para uso do Cross-over DMR/M17.

* Versão mínima para instalação: v4.1.7 pi-star e RPI 2/3/4(...).
* Nota: codec M17 não funciona em dispositivos *raspberryPI zero*.
  
# COMANDOS DE INSTALAÇÃO

* rpi-rw
* sudo git clone https://github.com/pu4ron/m17.git
* cd m17
* sudo chmod +x install.sh
* sudo chmod 777 install.sh
* sudo ./install.sh

  
![m1](https://github.com/pu4ron/m17/assets/40077152/2dfd7eb1-3ab8-411f-bd27-ae36a806a0e0)


![m2](https://github.com/pu4ron/m17/assets/40077152/a9c23b51-4c87-4392-9b8d-0f31dc3d6052)


![m17](https://github.com/pu4ron/m17/assets/40077152/6d639365-8b4e-47a6-8b6d-4afbd051dc92)

# Rádio
* Evite distorções diminuindo o ganho de audio do seu equipamento.
* Um valor recomendado para quem usa o firmware opengd é: 0 a -3db.
  
# TALKGROUP
* TG 1700000 / slot 2

# CONTROLE DE GANHO - SSH
* O ajuste é feito em dB(s) - máximo 18dB negativo e positivo.

***Exemplo:***

* -3 db (default)
* sudo volume -3
 
* +5 db
* sudo volume +5

* Após o ajuste aguarde de 3 a 5 segundos para TX.

# LEIA-ME
* Uma portadora curta (TX) para ativar o modo DMR2M17 (TX/RX).

* Runualdo - PU4RON
