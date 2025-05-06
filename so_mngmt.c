/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/06 12:03:29 by srioboo-         ###   ########.fr       */
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
	// if (game_data->ocean_img)
	// 	free(game_data->ocean_img);
	// if (game_data->wall_img)
	// 	free(game_data->wall_img);
	// if (game_data->fish_img)
	// 	free(game_data->fish_img);
	// if (game_data->exit_img)
	// 	free(game_data->exit_img);
	// if (game_data->player_img)
	// 	free(game_data->player_img);
}

void	close_game(t_game_data *game_data, int cause)
{
	// TODO - here need to release memory
	// mlx_close_hook(game_data->mlx, &process_moves, NULL);
	// TODO - THIS HAS NO EFFECT
	delete_images(game_data);
	// TODO - this reduce leaks -
	free_map_lines(game_data->map->lines);
	// if (game_data->map)
	//	free(game_data->map);
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
		ft_printf("You has not completed the game, hope see you later!\n");
	exit(EXIT_SUCCESS);
}

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	// ft_printf("%s\n", strerror(errno));
	// ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

