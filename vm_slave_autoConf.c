#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	::: sha256sum ./vm_slave_autoConf
//	94b68ea664960011e39961626901b196df764e18b79faeddc864cb90d1c5fddd  ./vm_slave_autoConf

// TODO::  el .i3status.conf y ./config   se copian manualmente para no romper configuraciones en i3blocks

int main(int argc, char **argv){

	fprintf(stdout, "\xA\x9 Downloading 0n11n3 files for linux environments \xA");

	const char *urls[]={"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/zshrc_self",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/arch/i3/.i3status.conf",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/arch/i3/config",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/.vimrcESSENTIAL",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/nvim/init.lua",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/vimrc__nanorc/alacritty/alacritty.toml",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/wallhaven-01339g.png",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/terminal_Finale.jpg",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/8/biosho_bigDaddy_littleSstr.jpg",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/up/0x/lab_x89p",\
											"https://raw.githubusercontent.com/notepad0n11n3/up/refs/heads/master/tmux/.tmux.conf"};

	const char *paths={"bash -c \"mkdir -p ~/.config/{nvim,alacritty,i3} ~/.0n11n3/{up/{8,0x},vimrc__nanorc/{nvim,alacritty},tmux} \""};

	const char *mv_config_files={"mv ./.tmux.conf ~/.tmux.conf && mv ./*.jpg ~/.0n11n3/up/8/ && mv ./*.png ~/.0n11n3/up/8/ && mv ./.vimrcESSENTIAL ~/.vimrc && mv ./alacritty.toml ~/.config/alacritty/ && mv ./init.lua ~/.config/nvim/"};

	const char *gpg_files={"gpg -dq -o ~/.zshrc_self ./zshrc_self && gpg -dq -o ~/.0n11n3/up/0x/lab_x89p ./lab_x89p && rm ./zshrc_self ./lab_x89p && for i in ~/.bashrc ~/.zshrc; do grep 'source ~/.zshrc_self' ${i} || echo 'source ~/.zshrc_self' >> ${i}; done "};
	const char *i3wm_config={"bash -c \"( if [ ! -f ~/.config/i3/config ]; then mv ./config ~/.config/i3/ ; else diff ./config ~/.config/i3/config ;fi) && ( if [ ! -f ~/.config/i3/.i3status.conf ]; then mv ./.i3status.conf ~/.config/i3/ ; else diff ./.i3status.conf ~/.config/i3/.i3status.conf ;fi)\""};

	// if [ -f ./file_here ];then ....
	// if test -f ./file_here;then ....							"La sintaxis con [ es un alias de [] "

	system(paths); // Creacion de paths

	// Curl config files
	char mochimango[2048];
	int number_urls = sizeof(urls) / sizeof(urls[0]);
	fprintf(stdout, "\xA\x9\x9 Number urls: %d \xA", number_urls);

	for (int i=0; i<number_urls; i++){
		printf("\xA== %d == \xA", i);
		fprintf(stdout, "\xA\x9\x9\x9 %d >> %s\xA", i, urls[i]);
		snprintf(mochimango, sizeof(mochimango), "curl -sS -O \"%s\" ", urls[i]);
		system(mochimango);
	}

	system(mv_config_files); // mv config files after curl
	system(gpg_files);
	system(i3wm_config);

	return 0;
}
