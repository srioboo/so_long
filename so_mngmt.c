/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/03 22:17:08 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game_data *game_data)
{
	// TODO - here need to release memory
	//mlx_delete_image(game_data->mlx, game_data->exit_img);
	//mlx_delete_image(game_data->mlx, game_data->fish_img);
	//mlx_delete_image(game_data->mlx, game_data->wall_img);
	//mlx_delete_image(game_data->mlx, game_data->ocean_img);

	free(game_data->exit_img);
	free(game_data->fish_img);
	free(game_data->wall_img);
	free(game_data->ocean_img);
	free(game_data->player_img);
	free(game_data->map->lines);
	game_data->exit_img = NULL;
	game_data->fish_img = NULL;
	game_data->wall_img = NULL;
	game_data->ocean_img = NULL;
	game_data->player_img = NULL;
	// free(game_data->mlx);
	mlx_close_window(game_data->mlx);
	free(game_data->mlx);
	free(game_data);
}

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

