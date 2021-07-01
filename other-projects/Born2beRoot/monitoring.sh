#!/bin/bash

#Arquitecture
echo -e "\t#Architecture:" $(uname -a)

#CPU Physical
echo -e "\t#CPU physical:" $(lscpu | awk ' NR==5 {print $2}')

#Virtual CPU
echo -e "\t#vCPU :" $(lscpu | grep Socket\(s\) | awk '{print $2}')

#Memory Usage
free --mega | awk 'NR==2{printf "\t#Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2 }'

#Disk Usage
df -h | awk '$NF=="/"{printf "\t#Disk Usage: %d/%dGB (%s)\n", $3,$2,$5}'

#CPU Load
top -bn1 | awk 'NR==3 {printf "\t#CPU Load: %.2f%s\n", $2 + $4, "%"}'

#Last Boot
echo -e "\t#Last boot:" $(who -b | awk ' {print $3,$4}')

#LVM
echo -e "\t#LVM use:" $(/usr/sbin/lvm pvdisplay | grep Allocatable | awk '{print $2}')

#Connections TCP
echo -e "\t#Connetions TCP:" $(ss -s | grep TCP | awk 'NR==2 {printf "%d ESTABLISHED\n", $3}')

#User log
echo -e "\t#User log:" $(who | wc -l)

#Network IP
echo -e "\t#Network: IP" $(hostname -I) $(ip a | grep link/ether | awk '{printf " (%s)\n", $2}')

#Sudo Count
echo -e "\t#Sudo : $(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l) cmd"
