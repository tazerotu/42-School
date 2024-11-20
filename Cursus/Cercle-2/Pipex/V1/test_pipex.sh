#!/bin/bash

rm -rf test.txt
printf "Ecrivez le contenu de votre fichier d'entree\n"
printf "Une fois terminer utiliser ctrl + d\n"
cat > test.txt
make re
./pipex test.txt cat 'wc -l' test2.txt
printf "\nCommande effectuer : ./pipex test.txt cat 'wc -l' test2.txt\n"
printf "Equivalent bash : cat test.txt | wc -l > test2.txt\n"
printf "\nContenu du ficher test.txt :\n"
cat test.txt
printf "\nResultat du programme :\n"
cat test2.txt

printf "\nReference :\n"
cat test.txt | wc -l


printf "\n\n\n"
printf "\nCommande effectuer : ./pipex test.txt 'cat -e' 'grep $' test2.txt\n"
printf "Equivalent bash : cat -e test.txt | grep '$' > test2.txt\n"
./pipex test.txt "cat -e" "grep '$'" test2.txt
printf "\nContenu du ficher test.txt :\n"
cat test.txt
printf "\nResultat du programme :\n"
cat test2.txt

printf "\nReference :\n"
cat -e test.txt | grep "$"
