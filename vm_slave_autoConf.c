#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	::: sha256sum ./vm_slave_autoConf
//	3006304894a4d2e6e63940ab4920f11aa90652c8be1a9ef1ce5802a760002012  ./vm_slave_autoConf


// TODO::  el .i3status.conf y ./config   se copian manualmente para no romper configuraciones en i3blocks

int run_cmd(const char *cmd){
	int ret = system(cmd);
	if( ret == 0 ){
		fprintf(stdout, "\x9 \033[92m [OK] \033[0m \xA");
	}else {
		fprintf(stderr, "\x9 \033[91m [FAIL] (Code: %d ) \033[0m \xA", ret);
	}
	return ret;
}

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
	const char *i3wm_config={"bash -c \"( if [ ! -f ~/.config/i3/config ]; then mv ./config ~/.config/i3/ ; else echo -e '\xA\x9 .../i3/config\xA' && diff ./config ~/.config/i3/config ; rm ./config ;fi) && ( if [ ! -f ~/.config/i3/.i3status.conf ]; then mv ./.i3status.conf ~/.config/i3/ ; else echo -e '\xA\x9 .../i3/.i3status.conf\xA' && diff ./.i3status.conf ~/.config/i3/.i3status.conf ; rm ./.i3status.conf ;fi)\""};

	const char *grub_img={"bash ./grub__wallpaper_noSUDO.sh && rm ./grub__wallpaper_noSUDO.sh"};
	// if [ -f ./file_here ];then ....
	// if test -f ./file_here;then ....							" La sintaxis con [] es un alias de  test  "

	// Creacion de paths
	(system(paths) == 0)? fprintf(stdout, "\xA\x9 \033[92m ===>* Paths Ready [OK]... <3 \033[0m \xA\xA") : fprintf(stderr, "\xA\x9 \033[92m ===>* Paths [FAIL]... \033[0m \xA\xA");

	// Curl config files
	char mochimango[4096];
	int number_urls = sizeof(urls) / sizeof(urls[0]);
	fprintf(stdout, " Number urls: %d \xA", number_urls);

	for (int i=0; i<number_urls; i++){
		fprintf(stdout, "\x9= %d >> %s\xA", i, urls[i]);
		snprintf(mochimango, sizeof(mochimango), "curl -sS -O \"%s\" ", urls[i]);
		run_cmd(mochimango);
	}

	// mv config files after curl
	(system(mv_config_files) == 0)? fprintf(stdout, "\xA\xA\x9 \033[92m ===>* mv_configFiles [OK]... <3 \033[0m\xA") : fprintf(stderr, "\xA\xA\x9 \033[91m ===>* mv_configFiles [FAIL]... \033[0m\xA") ;

	(system(gpg_files) == 0)? fprintf(stdout, "\xA\x9 \033[92m ===>* gpg Files [OK]... <3 \033[0m\xA") : fprintf(stderr, "\xA\xA\x9 \033[91m ===>* gpg Files [FAIL]... \033[0m\xA");

	(system(i3wm_config) == 0)? fprintf(stdout, "\xA\x9 \033[92m ===>* i3wm config if [OK]... <3 \033[0m\xA") : fprintf(stderr, "\xA\xA\x9 \033[91m ===>* i3wm config if [FAIL]... \033[0m\xA");

	(system(grub_img) == 0)? fprintf(stdout, "\xA\x9 \033[92m ===>* grub [OK]... <3 \033[0m\xA") : fprintf(stderr, "\xA\xA\x9 \033[91m ===>* grub [FAIL]... \033[0m\xA");

	return 0;
}
