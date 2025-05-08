/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/08 16:42:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_images(t_game_data *game_data)
{
	if (game_data->ocean_img)
		mlx_delete_image(game_data->mlx, game_data->ocean_img);
	if (game_data->wall_img)
		mlx_delete_image(game_data->mlx, game_data->wall_img);
	if (game_data->fish_img)
		mlx_delete_image(game_data->mlx, game_data->fish_img);
	if (game_data->exit_img)
		mlx_delete_image(game_data->mlx, game_data->exit_img);
	if (game_data->player_img)
		mlx_delete_image(game_data->mlx, game_data->player_img);
}

void	close_game(t_game_data *game_data, int cause)
{
	if (game_data)
	{
		delete_images(game_data);
		if (game_data->map)
		{
			free_map_lines(game_data->map->lines);
			free(game_data->map);
		}
		if (game_data->player)
			free(game_data->player);
		if (game_data)
			free(game_data);
		mlx_terminate(game_data->mlx);
	}
	if (cause == WIN)
		ft_printf("YOU WIN!!!\n");
	else
		ft_printf("You didn't complete the game, hope see you later!\n");
	exit(EXIT_SUCCESS);
}

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
