/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/07 13:32:43 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_images(t_game_data *game_data)
{
	mlx_delete_image(game_data->mlx, game_data->ocean_img);
	mlx_delete_image(game_data->mlx, game_data->wall_img);
	mlx_delete_image(game_data->mlx, game_data->fish_img);
	mlx_delete_image(game_data->mlx, game_data->player_img);
	mlx_delete_image(game_data->mlx, game_data->exit_img);
}

void	close_game(t_game_data *game_data, int cause)
{
	delete_images(game_data);
	free_map_lines(game_data->map->lines);
	if (game_data->map)
		free(game_data->map);
	mlx_close_window(game_data->mlx);
	if (game_data->mlx)
		free(game_data->mlx);
	if (game_data->player)
		free(game_data->player);
	if (game_data)
		free(game_data);
	if (cause == WIN)
		ft_printf("YOU WIN!!!\n");
	else
		ft_printf("You don't complete the game, hope see you later!\n");
	exit(EXIT_SUCCESS);
}

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
