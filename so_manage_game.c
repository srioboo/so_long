/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_manage_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/19 22:33:02 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_map(t_map *map, char *msg)
{
	if (map)
	{
		free_map_lines(map->lines);
		free(map);
	}
	if (msg != NULL)
		error_msg(msg);
}

void	free_map_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i] != NULL)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	close_game(t_game_data *game_data, int cause)
{
	game_data->game_start = FALSE;
	if (game_data)
	{
		delete_images(game_data);
		close_map(game_data->map, NULL);
		if (game_data->player)
			free(game_data->player);
		mlx_close_window(game_data->mlx);
		mlx_terminate(game_data->mlx);
		if (game_data)
			free(game_data);
	}
	if (cause == WIN)
		ft_printf("YOU WIN!!!\n");
	else if (cause == TEX)
	{
		ft_printf("Error\nCan't load the texture\n");
		exit(EXIT_FAILURE);
	}
	else
		ft_printf("You didn't complete the game, hope see you later!\n");
	exit(EXIT_SUCCESS);
}
