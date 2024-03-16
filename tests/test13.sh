#!/bin/bash

../cliente 0
# Bucle for que itera 100 veces
for ((i=0; i<=100; i++))
do
    ../cliente 1 $i "valor $i" 1
done
../cliente 6