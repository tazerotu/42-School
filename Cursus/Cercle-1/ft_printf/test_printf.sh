#!/bin/bash

make re
git clone https://github.com/tazerotu/42-Test.git
clear
grep -R "Created:" -A 1 ./**
printf "\n\n\n"
cc ./42-Test/Cercle-1/Printf/Printf-Main.c libftprintf.a
rm -rf 42-Test
./a.out
make clean
