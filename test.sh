#!/bin/bash

clear && make

function border_error()
{
	printf "\nBorder: maps/error-border-1.ber\n"
	./so_long maps/error-border-1.ber
	printf "\nBorder: maps/error-border-2.ber\n"
	./so_long maps/error-border-2.ber
	printf "\nBorder: maps/error-border-3.ber\n"
	./so_long maps/error-border-3.ber
	printf "\nBorder: maps/error-border-4.ber\n"
	./so_long maps/error-border-4.ber
	printf "\n===================================\n";
}

function exit_error()
{
	printf "\nExit: maps/error-cant-exit.ber\n"
	./so_long maps/error-cant-exit.ber
	printf "\nExit: maps/error-no-exit.ber\n"
	./so_long maps/error-no-exit.ber
	printf "\nExit: maps/error-exit-blocked-1.ber\n"
	./so_long maps/error-exit-blocked-1.ber
	printf "\n===================================\n";
}

function fish_error()
{
	printf "\nFish: maps/error-fish-blocked-1.ber\n"
	./so_long maps/error-fish-blocked-1.ber
	printf "\nFish: maps/error-fish-blocked-2.ber\n"
	./so_long maps/error-fish-blocked-2.ber
	printf "\nFish: maps/error-no-fish.ber\n"
	./so_long maps/error-no-fish.ber
	printf "\n===================================\n";
}

function player_error()
{
	printf "\nPlayer: maps/error-no-player.ber\n"
	./so_long maps/error-no-player.ber
	printf "\nPlayer: maps/error-player-blocked.ber\n"
	./so_long maps/error-player-blocked.ber
	printf "\nPlayermaps/error-two-players.ber\n"
	./so_long maps/error-two-players.ber
	printf "\n===================================\n";
}

function shape_error()
{
	printf "\nShape: maps/error-no-rectangle.ber\n"
	./so_long maps/error-no-rectangle.ber
	printf "\n===================================\n";
}

function too_small_error()
{
	printf "\nEmpty: maps/error-too-empty.ber\n"
	./so_long maps/error-too-empty.ber
	printf "\nEmpty: maps/error-too-narrow.ber\n"
	./so_long maps/error-too-narrow.ber
	printf "\nEmpty: maps/error-too-short.ber\n"
	./so_long maps/error-too-short.ber
	printf "\n===================================\n";
}

function extension_error()
{
	printf "\nExtension: maps/map.ber.wrong\n"
	./so_long maps/map.ber.wrong
	printf "\nExtension: maps/map.ger\n"
	./so_long maps/map.ger
	printf "\nExtension: maps/map.is_correct.ber\n"
	./so_long maps/map.is_correct.ber
	printf "\n===================================\n";
}

border_error
exit_error
fish_error
player_error
shape_error
too_small_error
# extension_error