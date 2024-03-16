#!/bin/bash

../cliente 0
# Bucle for que itera 100 veces
for ((i=82; i<=100; i++))
do
    ../cliente 4 100-$i
done