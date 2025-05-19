#!/bin/bash

clear && make
printf "\nBorder: maps/error-border-1.ber\n"
./so_long maps/error-border-1.ber
printf "\nBorder: maps/error-border-2.ber\n"
./so_long maps/error-border-2.ber
printf "\nBorder: maps/error-border-3.ber\n"
./so_long maps/error-border-3.ber
printf "\nBorder: maps/error-border-4.ber\n"
./so_long maps/error-border-4.ber

printf "\nExit: maps/error-cant-exit.ber\n"
./so_long maps/error-cant-exit.ber
printf "\nExit: maps/error-no-exit.ber\n"
./so_long maps/error-no-exit.ber
printf "\nExit: maps/error-exit-blocked.ber\n"
./so_long maps/error-exit-blocked.ber

printf "\nFish: maps/error-fish-blocked.ber\n"
./so_long maps/error-fish-blocked.ber
printf "\nFish: maps/error-no-fish.ber\n"
./so_long maps/error-no-fish.ber

printf "\nPlayer: maps/error-no-player.ber\n"
./so_long maps/error-no-player.ber
printf "\nPlayer: maps/error-player-blocked.ber\n"
./so_long maps/error-player-blocked.ber
printf "\nPlayermaps/error-two-players.ber\n"
./so_long maps/error-two-players.ber

printf "\nShape: maps/error-no-rectangle.ber\n"
./so_long maps/error-no-rectangle.ber

printf "\nEmpty: maps/error-empty.ber"
./so_long maps/error-empty.ber

printf "\nExtension: maps/map.ber.wrong\n"
./so_long maps/map.ber.wrong