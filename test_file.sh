# !/bin/bash

#ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

#./push_swap $ARG | ./checker $ARG



ARG="4 67 3 87 23 -33 66 99 1023 -2024 1 2 5 6 7"; ./push_swap $ARG | wc -l

./push_swap $ARG | ./checker $ARG
