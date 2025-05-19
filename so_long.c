/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/20 09:00:56 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_base_game_data(t_game_data	*game_data)
{
	mlx_image_t	*img;

	game_data->game_start = TRUE;
	game_data->moves = 0;
	game_data->redraw = 0;
	draw_scene(game_data);
	img = draw_player(game_data);
	game_data->player_img = img;
}

static void	create_game(char *map_path)
{
	mlx_t		*mlx;
	t_game_data	*game_data;
	t_map		*map;

	map = get_map(map_path);
	if (map != NULL)
	{
		mlx_set_setting(MLX_MAXIMIZED, false);
		mlx = mlx_init((IMG_SIZE * map->map_with),
				(IMG_SIZE * (map->map_height - 1)), "So long", false);
		if (!mlx)
			close_map(map, "Can't initialize");
		game_data = (t_game_data *)ft_calloc(1, sizeof(t_game_data));
		game_data->map = map;
		game_data->mlx = mlx;
		set_base_game_data(game_data);
		mlx_key_hook(mlx, &process_moves, game_data);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
}

int32_t	main(int argc, char **argv)
{
	if (argc == 1)
		return (error_msg("To launch: ./so_long path/to/map.ber"),
			EXIT_FAILURE);
	if (argc == 2)
	{
		if (is_valid_extension(argv[1]) == FALSE)
			return (error_msg("Map extension not valid"), EXIT_FAILURE);
		create_game(argv[1]);
	}
	else
		return (error_msg("To launch: ./so_long path/to/map.ber"),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
