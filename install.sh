#!/bin/bash
#
################################################
#                                              #
#        Por: Ronualdo JSA - PU4RON            #
#                                              #
#                Janauba/MG                    #
#                                              #
################################################
#

ver=$(awk -F "= " '/Version/ {print $2}' /etc/pistar-release)
call=$(grep -m 1 'Callsign=' /etc/mmdvmhost | awk -F "=" '/Callsign/ {print $2}')
id=$(grep -m 1 'Id=' /etc/mmdvmhost | tac | tail -1 | awk -F "=" '/Id/ {print $2}')
dest="/etc/dmr2m17"
gatw="/etc/dmrgateway"
camsys="/lib/systemd/system/dmr2m17.service"

mount -o remount,rw /
clear
echo -e "\033[01;37m****************************************\033[00;37m"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m*     \033[01;33mPor: RONUALDO - PU4RON\033[00;37m           *"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m*            \033[01;33mDMR2M17 v1.0    \033[00;37m          *"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m****************************************\033[00;37m"
echo ""
echo ""
sleep 1
clear
echo -e "\033[01;37m****************************************\033[00;37m"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m*       \033[01;33mSUPER LINK BRASIL - M17\033[00;37m        *"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m*             \033[01;33mDMR2M17 v1.0    \033[00;37m         *"
echo -e "\033[01;37m*                                      *\033[00;37m"
echo -e "\033[01;37m****************************************\033[00;37m"
echo ""
echo ""
echo -e "\033[01;37m\033[03;36m*** Script desenvolvido para pi-star v4.1.7/RPI ***\033[00;37m"
echo ""
echo -e "\033[01;37m\033[03;36m*** Trabalha em conjunto com DMRGateway, ative nas config do seu pi-star ***\033[00;37m"
echo ""
echo ""
echo ""
read -p "Continuar? (S/N) " -n 1 -r
case "$REPLY" in 

  s|S ) echo "" ;;
  n|N ) exit 0 ;;
    * ) exit 0 ;;   
esac
echo ""

sleep 2
service_handle() {
	
	doWhat=${1}
	sudo systemctl ${doWhat} pistar-watchdog.service > /dev/null 2>&1
	sudo systemctl ${doWhat} pistar-remote.service > /dev/null 2>&1
	sudo systemctl ${doWhat} dapnetgateway.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ircddbgateway.service > /dev/null 2>&1
	sudo systemctl ${doWhat} timeserver.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ysfgateway.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ysf2dmr.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ysf2nxdn.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ysf2p25.service > /dev/null 2>&1
	sudo systemctl ${doWhat} ysfparrot.service > /dev/null 2>&1
	sudo systemctl ${doWhat} dmr2ysf.service > /dev/null 2>&1
	sudo systemctl ${doWhat} dmr2nxdn.service > /dev/null 2>&1
	sudo systemctl ${doWhat} p25gateway.service > /dev/null 2>&1
	sudo systemctl ${doWhat} p25parrot.service > /dev/null 2>&1
	sudo systemctl ${doWhat} nxdngateway.service > /dev/null 2>&1
	sudo systemctl ${doWhat} nxdn2dmr.service > /dev/null 2>&1
	sudo systemctl ${doWhat} nxdnparrot.service > /dev/null 2>&1
	sudo systemctl ${doWhat} dstarrepeater.service > /dev/null 2>&1
	sudo systemctl ${doWhat} mmdvmhost.service > /dev/null 2>&1 && sleep 2 > /dev/null 2>&1
	sudo systemctl ${doWhat} dmr2m17.service > /dev/null 2>&1
	sudo systemctl ${doWhat} dmrgateway.service > /dev/null 2>&1

}

echo ""
echo ""
echo "* Desativando servicos..."
echo ""
service_handle stop
sleep 3

echo ""
echo ""
echo "* Instalando dependencias..."
echo ""
sudo apt-get install git make cmake -y > /dev/null 2>&1
sleep 3

echo "* Compilando e criando programa... aguarde!!!"
echo ""
sleep 3

mount -o remount,rw /

if [ -d "/opt/mbelib" ]; then                                          
   # sudo rm -R /opt/mbelib
   # sudo cp -p -R /home/pi-star/m17/mbelib /opt
   # sudo chmod 777 /opt/mbelib
   # cd /opt/mbelib
   sudo rm -R /opt/mbelib
   cd /opt
   sudo git clone https://github.com/szechyjs/mbelib.git
   sudo chmod 777 mbelib
   cd mbelib
   sudo mkdir build
   cd build
   sudo cmake ..
   sudo make
   sudo make install
   sudo cp -f libmbe.a /usr/lib
   sudo cp -f libmbe.pc /usr/lib
   sudo cp -f libmbe.so /usr/lib
   sudo cp -f libmbe.so.1 /usr/lib
   sudo cp -f libmbe.so.1.3 /usr/lib


else
   # sudo cp -p -R /home/pi-star/m17/mbelib /opt
   # sudo chmod 777 /opt/mbelib
   # cd /opt/mbelib
   cd /opt
   sudo git clone https://github.com/szechyjs/mbelib.git
   sudo chmod 777 mbelib
   cd mbelib
   sudo mkdir build
   cd build
   sudo cmake ..
   sudo make
   sudo make install
   sudo cp -f libmbe.a /usr/lib
   sudo cp -f libmbe.pc /usr/lib
   sudo cp -f libmbe.so /usr/lib
   sudo cp -f libmbe.so.1 /usr/lib
   sudo cp -f libmbe.so.1.3 /usr/lib

 fi

sleep 1
mount -o remount,rw /
if [ -f "/opt/md380_vocoder" ]; then 
                                         
   # sudo rm -R /opt/md380_vocoder
   # sudo cp -p -R /home/pi-star/m17/md380_vocoder /opt
   # sudo chmod 777 /opt/md380_vocoder
   # cd /opt/md380_vocoder
   sudo rm -R /opt/md380_vocoder
   cd /opt
   sudo git clone https://github.com/nostar/md380_vocoder.git
   sudo chmod 777 md380_vocoder
   cd md380_vocoder
   sudo make
   sudo make install

else
   # sudo cp -p -R /home/pi-star/m17/md380_vocoder /opt
   # sudo chmod 777 /opt/md380_vocoder
   # cd /opt/md380_vocoder
   cd /opt
   sudo git clone https://github.com/nostar/md380_vocoder.git
   sudo chmod 777 md380_vocoder
   cd md380_vocoder
   sudo make
   sudo make install

 fi

sleep 1
mount -o remount,rw /
if [ -d "/opt/imbe_vocoder" ]; then                                          
   # sudo rm -R /opt/imbe_vocoder
   # sudo cp -p -R /home/pi-star/m17/imbe_vocoder /opt
   # sudo chmod 777 /opt/imbe_vocoder
   # cd /opt/imbe_vocoder
   sudo rm -R /opt/imbe_vocoder
   cd /opt
   sudo git clone https://github.com/nostar/imbe_vocoder.git
   sudo chmod 777 imbe_vocoder
   cd imbe_vocoder
   sudo make
   sudo make install
   sudo ldconfig

else
   # sudo cp -p -R /home/pi-star/m17/imbe_vocoder /opt
   # sudo chmod 777 /opt/imbe_vocoder
   # cd /opt/imbe_vocoder
   cd /opt
   sudo git clone https://github.com/nostar/imbe_vocoder.git
   sudo chmod 777 imbe_vocoder
   cd imbe_vocoder
   sudo make
   sudo make install
   sudo ldconfig

 fi

sleep 1
mount -o remount,rw /
if [ -d "/opt/DMR2M17" ]; then                                          
   sudo rm -R /opt/DMR2M17
   sudo cp -p -R /home/pi-star/m17/DMR2M17 /opt
   sudo chmod 777 /opt/DMR2M17
   cd /opt/DMR2M17
   sudo make
   sudo cp DMR2M17 /usr/local/bin
   # sudo cp DMR2M17.ini /etc/dmr2m17
   sudo chmod 777 /usr/local/bin/DMR2M17

else
   sudo cp -p -R /home/pi-star/m17/DMR2M17 /opt
   sudo chmod 777 /opt/DMR2M17
   cd /opt/DMR2M17
   sudo make
   sudo cp DMR2M17 /usr/local/bin
   # sudo cp DMR2M17.ini /etc/dmr2m17
   sudo chmod 777 /usr/local/bin/DMR2M17

 fi

sleep 1
mount -o remount,rw /
if [ -f "/usr/local/sbin/volume" ]; then

       sudo rm /usr/local/sbin/volume
       sudo cp -p /opt/DMR2M17/volume /usr/local/sbin
       sudo chmod 777 /usr/local/sbin/volume 

else 
       sudo cp -p /opt/DMR2M17/volume /usr/local/sbin
       sudo chmod 777 /usr/local/sbin/volume 
 fi

echo ""
echo ""
echo "* Configurando os arquivos..."
echo ""
sleep 3
mount -o remount,rw /

if [ -f "${dest}" ]; then
 sudo rm ${dest}
 fi

touch ${dest}
sudo chmod 777 ${dest}


echo "[M17 Network]"                        >> ${dest}
echo "Callsign=${call} H"                   >> ${dest}
echo "LocalPort=32010"                      >> ${dest}
echo "DstName=M17-SLB A"                    >> ${dest}
echo "DstAddress=165.73.249.152"            >> ${dest}
echo "DstPort=17000"                        >> ${dest}
echo "GainAdjustdB=-6"                      >> ${dest}
echo "Daemon=1"                             >> ${dest}
echo "Debug=0"                              >> ${dest}
echo " "                                    >> ${dest}
echo "[DMR Network]"                        >> ${dest}
echo "RptAddress=127.0.0.1"                 >> ${dest}
echo "RptPort=62598"                        >> ${dest}
echo "LocalAddress=127.0.0.4"               >> ${dest}
echo "LocalPort=62599"                      >> ${dest}
echo "Debug=0"                              >> ${dest}
echo " "                                    >> ${dest}
echo "[DMR Id Lookup]"                      >> ${dest}
echo "File=/usr/local/etc/DMRIds.dat"       >> ${dest}
echo "Time=24"                              >> ${dest}
echo " "                                    >> ${dest}
echo "[Log]"                                >> ${dest}
echo "# Logging levels, 0=No logging"       >> ${dest}
echo "DisplayLevel=0"                       >> ${dest}
echo "FileLevel=1"                          >> ${dest}
echo "FilePath=/var/log/pi-star"            >> ${dest}
echo "FileRoot=DMR2M17"                     >> ${dest}
echo " "                                    >> ${dest}
echo "[Voice]"                              >> ${dest}
echo "Enabled=1"                            >> ${dest}
echo "Language=es_ES"                       >> ${dest}
echo "Directory=/usr/local/etc/M17_Audio"   >> ${dest}
echo " "                                    >> ${dest}
echo "[Enabled]"                            >> ${dest}
echo "Enabled=1"                            >> ${dest}
echo " "                                    >> ${dest}


if [ -f "${camsys}" ]; then
 sudo rm ${camsys}
 fi

touch ${camsys}
sudo chmod 777 ${camsys}

echo "[Unit]"                                                                   >> ${camsys}
echo "Description=Pi-Star DMR2M17 Service"                                      >> ${camsys}
echo "After=syslog.target network.target"                                       >> ${camsys}
echo " "                                                                        >> ${camsys}
echo "[Service]"                                                                >> ${camsys}
echo "Type=simple"                                                              >> ${camsys}
echo "User=root"                                                                >> ${camsys}
echo "Group=root"                                                               >> ${camsys}
echo "Restart=always"                                                           >> ${camsys}
echo "RestartSec=3"                                                             >> ${camsys}
echo "Restart=on-abort"                                                         >> ${camsys}
echo "StandardOutput=null"                                                      >> ${camsys}
echo "WorkingDirectory=/usr/local/bin"                                          >> ${camsys}
echo "ExecStartPre=/bin/sh -c 'until ping -c1 google.com; do sleep 1; done;'"   >> ${camsys}
echo "ExecStart=/usr/local/bin/DMR2M17 /etc/dmr2m17"                            >> ${camsys}
echo "ExecReload=/bin/kill -HUP $MAINPID"                                       >> ${camsys}
echo "KillMode=process"                                                         >> ${camsys}
echo " "                                                                        >> ${camsys}
echo "[Install]"                                                                >> ${camsys}
echo "WantedBy=default.target"                                                  >> ${camsys}

sudo systemctl enable dmr2m17.service > /dev/null 2>&1


if [ -f "${gatw}" ]; then

   sudo mount -o remount,rw / 2>&1
   sudo chmod 777 ${gatw}

   if [[ $(grep -c "\[DMR Network 5\]" /etc/dmrgateway) -eq "1" ]]; then
      echo ""
      echo ""
      echo "---  ATENCAO: Ja existe uma rede "DMR Network 5" no conf do DMRGateway -----"
      echo ""
      echo "Verifique se no arquivo config se a rede network 5 corresponde ao DMR2M17"
      echo ""
      echo "Caso nao, apague "DMR Network 5" do config DMRGateway e tente novamente"
      echo ""
      sleep 10

   fi

   if [[ $(grep -c "\[DMR Network 5\]" /etc/dmrgateway) -eq "0" ]]; then
	
      echo ""                                         >> ${gatw}
      echo ""                                         >> ${gatw}
      echo "[DMR Network 5]"                          >> ${gatw}
      echo "Enabled=1"                                >> ${gatw}
      echo "Name=DMR2M17_Cross-over"                  >> ${gatw}
      echo "Id=${id}"                                 >> ${gatw}
      echo "Address=127.0.0.4"                        >> ${gatw}
      echo "Port=62599"                               >> ${gatw}
      echo "Local=62598"                              >> ${gatw}
      echo "TGRewrite0=2,5000017,2,5000017,1"         >> ${gatw}
      echo "PCRewrite0=2,5000017,2,5000017,1"         >> ${gatw}
      echo 'Password="PASSWORD"'                      >> ${gatw}
      echo "Location=0"                               >> ${gatw}
      echo "Debug=0"                                  >> ${gatw}
      echo ""                                         >> ${gatw}

      sudo chmod 644 ${gatw}      
   fi
fi

mount -o remount,rw /
echo ""
echo ""
echo "* Removendo os arquivos de instalacao..."
echo ""
sudo rm -R /home/pi-star/m17
sudo rm -R /opt/mbelib
sudo rm -R /opt/md380_vocoder
sudo rm -R /opt/imbe_vocoder
sudo rm -R /opt/DMR2M17
sleep 3

echo ""
echo ""
echo "* Ativando servicos..."
echo ""
service_handle start
sleep 3

echo ""
echo ""
echo "*** FIM ***"
echo ""
echo ""
echo -e "\033[01;37m\033[03;36m*** SUPER LINK BRASIL ***\033[00;37m"
echo -e "\033[01;37m\033[03;36m https://superlink.py2lrz.com \033[00;37m"
echo ""
echo ""
echo -e "\033[01;37m\033[03;36m*** DASHBOARD M17-SLB***\033[00;37m"
echo -e "\033[01;37m\033[03;36m https://m17-digitalvoice.dns.army \033[00;37m"
echo ""
echo ""
