"  :source %
syntax on 
set number 
set mouse=a
set numberwidth=1   "ancho de los número set number  set relativenumber
set clipboard=unnamedplus	"habilita el elClipboard para poder llevar textodeVim afueraPEGAR
set showcmd "muestra los comandos que estoy ejecutando NOfuncioaCOMOesperaba :(
set ruler   "número de linea y número de columna
set encoding=utf-8
set showmatch "si me paro sobre un ({[ muestra el otro que esta cerrando 
set sw=2  "tabulador   ahora es 2 espacios
set relativenumber 
set laststatus=2  "muestra barra inferior ( si we si... esaBarra de color :u )
set noshowmode   "quita el aviso -- INSERTAR --  al entrar en modo inserción noFunciona:(

set tabstop=2 softtabstop=2
set shiftwidth=2
set smartindent
set incsearch "no espera a dar ENTER para mostrar resultados de busqueda con /
set hlsearch "Resalta las letras al hacer búsquedas

set nu " == set number

"ThePrimeagen
set noerrorbells
set expandtab
set nowrap "don't work :'u
  "solution
set wrap
set textwidth=0 wrapmargin=0
  "noitulos
set smartcase
set noswapfile
set nobackup
set undodir=~/.vim/undodir
set undofile

set colorcolumn=80
highlight ColorColumn ctermbg=0 guibg=lightgrey


call plug#begin('~/.vim/plugged')

Plug 'easymotion/vim-easymotion'
Plug 'scrooloose/nerdtree'

"Plug 'ervandew/supertab'  
  "CONTEXTUAL DE RECOMENDACIONES
  "Recomendacion de palabras usadas    SE USA CON TAB PARA MOSTRAR EL MENU

"Themes
Plug 'joshdick/onedark.vim'
Plug 'morhetz/gruvbox'
Plug 'dikiaap/minimalist'

"Linea celeste INSERT 
Plug 'itchyny/lightline.vim'

"Lineas de identacion
Plug 'nathanaelkane/vim-indent-guides'


#Plug 'git@github.com:Valloric/YouCompleteMe.git'
Plug 'ycm-core/YouCompleteMe'
  "https://www.youtube.com/watch?v=n9k9scbTuvQ



call plug#end()


let NERDTreeQuitOnOpen=1


"colorscheme gruvbox
"let g:gruvbox_contrast_dark = hard" HARD ENTRE COMILLAS DOBLES  creo que no
"es necesario


let g:indent_guides_enable_on_vim_startup = 1 "" Lineas de identacion enable desde inicio


let mapleader=" "
nmap <Leader>nt :NERDTreeFind<CR>
nmap <Leader>s <Plug>(easymotion-s2)


imap zz <Esc>

set t_Co=256
colorscheme gruvbox
let g:gruvbox_transparent_bg=1

hi! Normal ctermbg=NONE guibg=NONE
