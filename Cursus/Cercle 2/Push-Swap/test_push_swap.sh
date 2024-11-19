#!/bin/bash

make re
printf "program for 100 random numbers between -2147483648 and 2147483647\n"

./push_swap $(awk 'BEGIN {srand(); for(i=0; i<100; i++) print int(rand() * (4294967296) - 2147483648)}') | cat > 100

./push_swap $(awk 'BEGIN {srand(); for(i=0; i<100; i++) print int(rand() * (4294967296) - 2147483648)}') | wc -l

printf "Testeur linux :\n"
ARG=$(awk 'BEGIN {srand(); for(i=0; i<100; i++) print int(rand() * (4294967296) - 2147483648)}'); ./push_swap $ARG | ./checker_linux $ARG

printf "\n\n\n"
printf "program for 500 random numbers between -2147483648 and 2147483647\n"

./push_swap $(awk 'BEGIN {srand(); for(i=0; i<500; i++) print int(rand() * (4294967296) - 2147483648)}') | cat > 500

./push_swap $(awk 'BEGIN {srand(); for(i=0; i<500; i++) print int(rand() * (4294967296) - 2147483648)}') | wc -l

printf "Testeur linux :\n"
ARG=$(awk 'BEGIN {srand(); for(i=0; i<500; i++) print int(rand() * (4294967296) - 2147483648)}'); ./push_swap $ARG | ./checker_linux $ARG

