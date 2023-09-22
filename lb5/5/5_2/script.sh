#!/bin/bash
# Количество читателей и писателей
rd=5
wr=5
# Запуск читателей
for ((i=0; i<$rd; i++)); do
gnome-terminal -- ./proc_rd
done
# Запуск писателей
for ((i=0; i<$wr; i++)); do
gnome-terminal -- ./proc_wr
done
