#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	::: sha256sum ./vm_slave_autoConf
//					3c2df6dea7dd7132e2e27ce8a23135678d34b80caed999f9b1f09d7b39ff01f5  vm_slave_autoConf

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
	const char *zshrc_tmux={"mv ./zshrc_self ~/.zshrc_self && mv ./.tmux.conf ~/.tmux.conf && echo 'source ~/.zshrc_self' >> ~/.bashrc && echo 'source ~/.zshrc_self' >> ~/.zshrc"};
	const char *img_nvim_alac_punt={"mv ./*.jpg ~/.0n11n3/up/8/ && mv ./*.png ~/.0n11n3/up/8/ && mv ./lab_x89p ~/.0n11n3/up/0x/ && mv ./.vimrcESSENTIAL ~/.vimrc && mv ./alacritty.toml ~/.config/alacritty/ && mv ./init.lua ~/.config/nvim/"};

	system(paths); // Creacion de paths

	char mochimango[2048];
	int number_urls = sizeof(urls) / sizeof(urls[0]);
	fprintf(stdout, "\xA\x9\x9 Number urls: %d \xA", number_urls);
	for (int i=0; i<number_urls; i++){
		printf("\xA== %d == \xA", i);
		fprintf(stdout, "\xA\x9\x9\x9 %d >> %s\xA", i, urls[i]);
		snprintf(mochimango, sizeof(mochimango), "curl -O \"%s\"", urls[i]);
		system(mochimango);
	}
	system(zshrc_tmux);
	system(img_nvim_alac_punt);

	return 0;
}
