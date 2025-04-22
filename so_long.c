/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 22:18:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_game_data	*game_data;
	t_map		*map;

	map = get_map();
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init((IMG_SIZE * map->map_with),
			(IMG_SIZE * (map->map_height - 1)), "So long", true);
	if (!mlx)
		error();
	draw_scene(mlx, map);
	game_data = (t_game_data *)ft_calloc(100, sizeof(t_game_data));
	game_data->map = map;
	game_data->mlx = mlx;
	img = draw_player(mlx, game_data);
	game_data->player_img = img;
	// mlx_loop_hook(mlx, &win_close, mlx);
	mlx_key_hook(mlx, &process_moves, game_data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
