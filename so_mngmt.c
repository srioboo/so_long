/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/05 10:24:37 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game_data *game_data, int cause)
{
	// TODO - here need to release memory
	//mlx_delete_image(game_data->mlx, game_data->exit_img);
	//mlx_delete_image(game_data->mlx, game_data->fish_img);
	//mlx_delete_image(game_data->mlx, game_data->wall_img);
	//mlx_delete_image(game_data->mlx, game_data->ocean_img);

	// if (game_data->exit_img)
	// 	free(game_data->exit_img);
	// if (game_data->fish_img)
	// 	free(game_data->fish_img);
	// if (game_data->wall_img)
	// 	free(game_data->wall_img);
	// if (game_data->ocean_img)
	// 	free(game_data->ocean_img);
	// if (game_data->player_img)
	// 	free(game_data->player_img);
	//if (game_data->exit_img)
	//	free(game_data->map->lines);
	mlx_close_window(game_data->mlx);
	if (cause == 1)
		ft_printf("YOU WIN!!!\n");
	else
		ft_printf("See you later!\n");
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

