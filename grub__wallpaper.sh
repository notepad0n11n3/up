#!/usr/bin/bash

mango=$(whoami)
umu=$(echo $up)

  # las imagenes para remplazar son .png      voy a probar con .jpg

 
#BLOQUE 1  
         # El fondo con las opciones del grub cambio PERO... despu[es de escoger una opci[on al momento de cargar se llega a ver por unos segundos el anterior wallpaper
sudo cp /home/${mango}/Desktop/0n11n3/up/8/wallhaven-01339g.jpg /boot/grub/themes/kali/grub-4x3.png
sudo cp /home/${mango}/Desktop/0n11n3/up/8/wallhaven-01339g.jpg /boot/grub/themes/kali/grub-16x9.png


#BLOQUE 2 
        # fondeDelGrub postSelecci[on fondoCargaPreSystem     <<== este no es tan importantePOR AHORA
sudo cp ${umu}/8/wallhaven-01339g.jpg /usr/share/grub/themes/kali/grub-4x3.png
sudo cp ${umu}/8/wallhaven-01339g.jpg /usr/share/grub/themes/kali/grub-16x9.png
