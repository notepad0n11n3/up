#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	::: sha256sum ./vm_slave_autoConf
//  d2545904b2e1dbab08ce6f0b95fe9341776fdde0373b1bacab7d9675b074a751 ./vm_slave_autoConf

// TODO::  el .i3status.conf y ./config   se copian manualmente para no romper configuraciones en i3blocks

int main(int argc, char **argv){

	fprintf(stdout, "\xA\x9 Downloading... 0n11n3 files for linux environments... \xA");

	const char *urls[]={"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/zshrc_self",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/0x/lab_x89p",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/arch/i3/.i3status.conf",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/arch/i3/config",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/.vimrcESSENTIAL",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/nvim/init.lua",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/alacritty/alacritty.toml",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/wallhaven-01339g.png",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/terminal_Finale.jpg",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/biosho_bigDaddy_littleSstr.jpg",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/grub__wallpaper_noSUDO.sh",
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/tmux/.tmux.conf"};

// "https://github.com/notepad0n11n3/up/raw/refs/heads/master/0x/lab_x89p",
// "https://github.com/notepad0n11n3/up/raw/refs/heads/master/zshrc_self",

	// Paths 
	const char *paths={"bash -c \"mkdir -p ~/.config/{nvim,alacritty,i3} ~/.0n11n3/{up/{8,0x},vimrc__nanorc/{nvim,alacritty},tmux} \""};

	// Config files (tmux, *.jpg , *,png , vim, nvim, alacritty)
	const char *mv_config_files={"mv ./.tmux.conf ~/.tmux.conf && mv ./*.jpg ~/.0n11n3/up/8/ && mv ./*.png ~/.0n11n3/up/8/ && mv ./.vimrcESSENTIAL ~/.vimrc && mv ./alacritty.toml ~/.config/alacritty/ && mv ./init.lua ~/.config/nvim/"};

	// decifra -> insert -> borra el original (./zshrc_self ./lab_x89p)  :::    
	const char *gpg_files={"gpg --yes -dq -o ~/.zshrc_self --pinentry-mode loopback ./zshrc_self && gpg --yes -dq -o ~/.0n11n3/up/0x/lab_x89p --pinentry-mode loopback ./lab_x89p ; rm ./zshrc_self ./lab_x89p && echo '\xA\x9 Comprobando los sources\xA' && for i in ~/.bashrc ~/.zshrc; do grep -Hn 'source ~/.zshrc_self' ${i} || echo 'source ~/.zshrc_self' >> ${i}; done "};

	// i3wm configFiles , copia solo si no existe, si existe muestra el diff (config , .i3status.conf)
	const char *i3wm_config={"bash -c \"( if [ ! -f ~/.config/i3/config ]; then mv ./config ~/.config/i3/ ; else diff ./config ~/.config/i3/config ; rm ./config ;fi) && ( if [ ! -f ~/.config/i3/.i3status.conf ]; then mv ./.i3status.conf ~/.config/i3/ ; else diff ./.i3status.conf ~/.config/i3/.i3status.conf ; rm ./.i3status.conf ;fi)\""};

	const char *grub_img={"bash ./grub__wallpaper_noSUDO.sh && rm ./grub__wallpaper_noSUDO.sh"};
	// if [ -f ./file_here ];then ....
	// if test -f ./file_here;then ....							" La sintaxis con [] es un alias de  test  "

	system(paths); // Creacion de paths
	fprintf(stdout, "\xA\x9 ===>* Paths Ready... <3 <3 <3\xA\xA");

	// Curl config files
	char mochimango[4096];
	int number_urls = sizeof(urls) / sizeof(urls[0]);
	fprintf(stdout, " Number urls: %d \xA", number_urls);

	for (int i=0; i<number_urls; i++){
		fprintf(stdout, "\x9= %d >> %s\xA", i, urls[i]);
		snprintf(mochimango, sizeof(mochimango), "curl -sS -O \"%s\" ", urls[i]);
		system(mochimango);
	}

	system(mv_config_files); // mv config files after curl
	fprintf(stdout, "\xA\xA\x9 ===>* mv_configFiles Ready... <3 <3 <3\xA");
	system(gpg_files);
	fprintf(stdout, "\xA\x9 ===>* gpg Files Ready... <3 <3 <3\xA");
	system(i3wm_config);
	fprintf(stdout, "\xA\x9 ===>* i3wm config  if  Ready... <3 <3 <3\xA");

	system(grub_img);
	fprintf(stdout, "\xA\x9 ===>* grub Ready... <3 <3 <3\xA");

	return 0;
}
