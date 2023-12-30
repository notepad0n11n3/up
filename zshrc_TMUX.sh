#!/bin/bash

# tmux new -s "Go" -c $htb -n "main" 
# tmux split-window -v / -h

tiempo=0.5

tmux new-session -d -t "htb" -c $htb && sleep ${tiempo}
tmux rename-session "HTB"
tmux rename-window "vpn()" && tmux split-window -h -c $htb && tmux split-window -v -c $htb

#tmux send-key "bash" C-m && tmux send-key "clear" C-m && sleep ${tiempo}
#tmux send-key "bash" C-m && tmux send-key "clear && vim ." C-m && sleep ${tiempo}

tmux select-pane -t 0
#tmux send-key "sudo openvpn $up/0x/lab_burn" M-a && sleep ${tiempo}
tmux send-key "sudo apt update" M-a && sleep ${tiempo}

tmux select-pane -t 1
tmux send-key "clear && ifconfig tun0" && sleep ${tiempo}

tmux select-pane -t 2
tmux send-key "ping -c 4 -4 " 

tmux select-pane -t 0

tmux new-window -t HTB:1 -n "?[]" -c $htb && sleep ${tiempo} && tmux send-keys "ls -lah" C-m
tmux select-window -t 0
