#!/bin/bash

make re
./pipex test.txt cat 'wc -l' test2.txt
printf "\nCommande effectuer : ./pipex test.txt cat 'wc -l' test2.txt\n"
printf "Equivalent bash : cat test.txt | wc -l > test2.txt\n"
printf "\nContenu du ficher test.txt :\n"
cat test.txt
printf "\n\nResultat du programme :\n"
cat test2.txt
