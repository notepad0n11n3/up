"             for nvim go tail here
"  :source %  :: so %   " cargar archivo .vimrc actual
"  :h tabstop    :h noerrorblells    " infoHelp para los opci[ones de confi.
"  :options      " todas las opciones de configuraci[on
syntax on 
set encoding=utf-8
set number 
  "set nu " == set number
set mouse=a "mouseIntegration
set relativenumber 
set numberwidth=1 "number width ==> relative number

" Copy Paste 
set clipboard=unnamedplus	
  "::: vim -- version | grep clipboard  ==>> -clipboard -xterm_clipboard ===> sudo apt install vim-gtk

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
  "pre- mkdir $HOME/.vim/undodir
set undodir=~/.vim/undodir
set undofile

set colorcolumn=80,75,70,1
highlight ColorColumn ctermbg=0 guibg=lightgrey

" TP 21
"colorscheme gruvbox ==>> 'gruvbox-community/gruvbox'    nvim???
"highlight Normal guibg=none     ##fondo transparente    nvim???
"set hidden

call plug#begin('~/.vim/plugged')
" busqueda por coincidencia <Espace>+s
Plug 'easymotion/vim-easymotion' 

" explorador lateral carpetaActual
Plug 'scrooloose/nerdtree'

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
  "al reinstalar da un error ./.vim/***/***/YouCompleteMe/ ::: ./install.py --ts-completer


  " :!git  ===>>>  :Git  :: :G commit/log/status/....
Plug 'tpope/vim-fugitive' 
" git left signs[+-~] lineas modificadas
Plug 'airblade/vim-gitgutter'
" commit trees
Plug 'junegunn/gv.vim'
  " [c ]c salta entre las modificaciones del archivo, arriba/abajo :) hunks

  " time tree
Plug 'mbbill/undotree'
  
call plug#end()

" Cerrar nerdTree despues de seleccionar un archivo
let NERDTreeQuitOnOpen=1

" Lineas de identacion desde el inicio
let g:indent_guides_enable_on_vim_startup = 1 "" Lineas de identacion enable desde inicio

""""""""======>>>>> Atajo aeo8 personalizado <<<<<<<========""""""""""""""
imap zz <Esc>
" Tecla lider
let mapleader=" "
nmap <Leader>nt :NERDTreeFind<CR>
nmap <Leader>s <Plug>(easymotion-s2)
nmap <Leader>q :q<CR>
nmap <Leader>w :w<CR>
nmap <Leader>z :! clear && zsh<CR>
nmap <Leader>x :! 
nmap <Leader>. :nohlsearch<CR> 
nmap <Leader>g :Git<CR>
    " :nohl === :noh  === :nohlsearch
nnoremap <leader>h :wincmd h<CR>
nnoremap <leader>j :wincmd j<CR>
nnoremap <leader>k :wincmd k<CR>
nnoremap <leader>l :wincmd l<CR>

set copyindent    " copy the previous indentation on autoindenting

"like a nerdTree pero con Ex
nnoremap <leader>pv :wincmd v<bar> :Ex <bar> :vertical resize 30<CR>

" YCM
" The best part
nnoremap <silent> <Leader>yd :YcmCompleter GoTo<CR>
nnoremap <silent> <Leader>yf :YcmCompleter FixIt<CR>

              "" GIT GIT GIT GIT en vim...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
" resaltado de lineas modificadas git LIGHT DARKNES  vim-gitgutter
nmap <Leader>o :GitGutterLineHighlightsEnable<CR>
nmap <Leader>O :GitGutterLineHighlightsDisable<CR>

" commit tree  junegunn/gv.vim
nmap <Leader>ct :GV<CR>
" file commit's junegunn/gv.vim
nmap <Leader>cf :GV!<CR>

" time tree  mbbill/undotree
nmap <Leader>tt :UndotreeToggle<CR>

" disable all key mappings vim-gitgutter
let g:gitgutter_map_keys = 0
let g:gitgutter_preview_win_floating = 1
" signos git desde arranque  vim-gitgutter
set signcolumn=yes
"refresco de vim para EJECUTAR vim-gitgutter
set updatetime=100 " este se QUEDA :)

" config addd  https://github.com/itchyny/lightline.vim
" LEFT left
  " branch 
let g:lightline = {
      \ 'colorscheme': 'powerline',
      \ 'active': {
      \   'left': [ 
      \             [ 'x89p', 'modified' ],
      \             [ 'filename', 'percent', 'modified' ], 
      \             [ 'lineinfo' ],
      \             [ 'readonly', 'gitbranch'], [ 'goewe', 'modified' ],
      \             ],
      \  'right': [ 
      \             [ 'modified', 'mode', 'paste', 'fire' ],
      \             [ 'modified', 'lineinfo', 'filename' ],
      \             [ 'percent', 'gitbranch' ],
      \             [ 'fileformat', 'fileencoding', 'rightHere' ] ]
      \ },
      \ 'component_function': {
      \   'gitbranch': 'FugitiveHead'
      \ },
      \ 'component': {
      \      'x89p': '🔥ψ(｀∇´)ψ(ノ｀⌒´)ノ🔥',
      \      'goewe': ' (~‾▿‾)~🔥ﾉ(° -°ﾉ)',
      \     'rightHere': '🎼♩♪♫ 💪(￣ヘ￣;)',
      \      'fire': '🔥'
      \ },
      \ }

" Transparencia en grubox
set t_Co=256
colorscheme gruvbox
let g:gruvbox_transparent_bg=1

colorscheme minimalist "tambien vale onedark :)  <3<3<3
colorscheme gruvbox

hi! Normal ctermbg=NONE guibg=NONE

" no lineas al infinito :')
set wrap
set textwidth=0 wrapmargin=0

"""""""""""""""""""""""""'NVIM""""""""""""""""""""""""""""""""""""''
"mismo archivo de configuraci[on para vim nvim
"
"       $HOME/.config/nvim/init.vim
"     ::: vim init.vim
"
"         set runtimepath^=~/.vim runtimepath+=~/.vim/after
"         let &packpath=&runtimepath
"         source ~/.vimrc
"
set cursorline cursorcolumn
