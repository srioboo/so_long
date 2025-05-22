#!/bin/bash

# set -e

clear && make $1

# EXEC="valgrind --leak-check=summary ./so_long"
EXEC="./so_long"
GREEN="\033[1;32m"
NC="\033[m"

function border_error()
{
	for file in $(ls maps/error-border*.ber)
	do
		printf "\n${GREEN}Border:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function exit_error()
{

	for file in $(ls maps/error*exit*.ber)
	do
		printf "\n${GREEN}Exit:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function fish_error()
{
	for file in $(ls maps/error-*fish*.ber)
	do
		printf "\n${GREEN}Fish:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function player_error()
{
	for file in $(ls maps/error-*player*.ber)
	do
		printf "\n${GREEN}Player:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function shape_error()
{
	printf "\n${GREEN}Shape:${NC} maps/error-no-rectangle.ber\n"
	${EXEC} maps/error-no-rectangle.ber; echo $?
	printf "\n===================================\n";
}

function wrong_char_error()
{
	for file in $(ls maps/error-wrong-char*.ber)
	do
		printf "\n${GREEN}Wrong char:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function too_small_error()
{
	for file in $(ls maps/error-too*.ber)
	do
		printf "\n${GREEN}Too Empty:${NC} $file\n"
		${EXEC} $file; echo $?
	done
	printf "\n===================================\n";
}

function extension_error()
{
	printf "\n${GREEN}Extension:${NC} maps/map.ber.wrong\n"
	${EXEC} maps/map.ber.wrong; echo $?
	printf "\n${GREEN}Extension:${NC} maps/map.ger\n"
	${EXEC} maps/map.ger; echo $?
	printf "\n${GREEN}Extension:${NC} maps/map.is_correct.ber\n"
	${EXEC} maps/map.is_correct.ber; echo $?
	printf "\n===================================\n";
}

# border_error
# player_error
# shape_error
# too_small_error
# extension_error
wrong_char_error
exit_error
fish_error