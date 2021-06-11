"  :source %     " cargar archivo .vimrc actual
syntax on 
set encoding=utf-8
set number 
  "set nu " == set number
set mouse=a "mouseIntegration
set relativenumber 
set numberwidth=1 "number width ==> relative number

" Copy Paste 
set clipboard=unnamedplus	

set showcmd "muestra los comandos que estoy ejecutando NOfuncioaCOMOesperaba :(
set ruler   "número de linea y número de columna
set showmatch "si me paro sobre un ({[]}) muestra el otro que esta cerrando 
set laststatus=2  "muestra barra inferior ( si we si... esaBarra de color :u )
set noshowmode   "quita el aviso -- INSERTAR --  al entrar en modo inserción noFunciona:(

set sw=2  "tabulador   ahora es 2 espacios
set tabstop=2 softtabstop=2
set shiftwidth=2
set smartindent
set incsearch "no espera a dar ENTER para mostrar resultados de busqueda con /
set hlsearch "Resalta las letras al hacer búsquedas


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
" busqueda por coincidencia " "s
Plug 'easymotion/vim-easymotion' 

" explorador lateral carpetaActual
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
Plug 'yggdroot/indentline'

"Auto completado  go github for help men... go github ...
Plug 'ycm-core/YouCompleteMe'
  "https://www.youtube.com/watch?v=n9k9scbTuvQ
  
call plug#end()

" Cerrar nerdTree despues de seleccionar un archivo
let NERDTreeQuitOnOpen=1

" Lineas de identacion desde el inicio
let g:indent_guides_enable_on_vim_startup = 1 "" Lineas de identacion enable desde inicio

" Tecla lider
let mapleader=" "
nmap <Leader>nt :NERDTreeFind<CR>
nmap <Leader>s <Plug>(easymotion-s2)

" Atajo personalizado
imap zz <Esc>

" Transparencia en grubox
set t_Co=256
colorscheme gruvbox
let g:gruvbox_transparent_bg=1

hi! Normal ctermbg=NONE guibg=NONE

" no lineas al infinito :')
set wrap
set textwidth=0 wrapmargin=0
