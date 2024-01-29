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

mmdvm="/etc/mmdvmhost"
m17gat="/etc/m17gateway"

valorATUAL1=$(sed -n "/\[M17\]/{n;p;}" /etc/mmdvmhost | awk -F '=' '{print $2}')
valorATUAL2=$(sed -n "/\[M17 Network\]/{n;p;}" /etc/mmdvmhost | awk -F '=' '{print $2}')
valorATUAL3=$(sed -n "/\[General\]/{n;n;n;n;p;}" /etc/m17gateway | awk -F '=' '{print $2}')
valorATUAL4=$(sed -n "/\[General\]/{n;n;n;n;n;p;}" /etc/m17gateway | awk -F '=' '{print $2}')

sudo mount -o remount,rw /

sudo sed -i "/\[M17\]/{n;s/Enable=${valorATUAL1}/Enable=1/}" ${mmdvm}
sudo sed -i "/\[M17 Network\]/{n;s/Enable=${valorATUAL2}/Enable=1/}" ${mmdvm}
sudo sed -i "/\[General\]/{n;n;n;n;s/RptPort=${valorATUAL3}/RptPort=17511/}" ${m17gat}
sudo sed -i "/\[General\]/{n;n;n;n;n;s/LocalPort=${valorATUAL4}/LocalPort=17510/}" ${m17gat}

 