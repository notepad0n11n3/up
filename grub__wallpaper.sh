#!/usr/bin/bash

  # las imagenes para remplazar son .png      voy a probar con .jpg

#BLOQUE 1  
         # El fondo con las opciones del grub cambio PERO... despu[es de escoger una opci[on al momento de cargar se llega a ver por unos segundos el anterior wallpaper
sudo cp /home/aeo8/Desktop/up/8/10990583.png /boot/grub/themes/kali/grub-4x3.png
sudo cp /home/aeo8/Desktop/up/8/10990583.png /boot/grub/themes/kali/grub-16x9.png

#BLOQUE 2 
        # fondeDelGrub postSelecci[on fondoCargaPreSystem     <<== este no es tan importantePOR AHORA
sudo cp $up/8/10990583.png /usr/share/grub/themes/kali/grub-4x3.png
sudo cp $up/8/10990583.png /usr/share/grub/themes/kali/grub-16x9.png
