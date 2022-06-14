#!/bin/bash

for mango in {0..255}; do
  printf "\x1b[38;5;${mango}mcolours${mango}\n"
done
