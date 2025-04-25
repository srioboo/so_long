/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/26 11:51:37 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*draw_player(t_game_data *game_data)
{
	mlx_image_t			*img;
	int					result;
	char				*relative_path;
	mlx_texture_t		*texture;

	relative_path = "./img/dolphin_64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(game_data->mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(game_data->mlx, img,
			IMG_SIZE * (game_data->map->player_x),
			IMG_SIZE * (game_data->map->player_y));
	// mlx_set_instance_depth(&game_data->player_img->instances[0], 100);
	if (result < 0)
		error();
	return (img);
}

void	move_player(t_game_data *game_data,
				int steps_x, int steps_y)
{
	t_map_pos	pixels;
	t_map_pos	next;

	pixels.x = game_data->player_img->instances[0].x;
	pixels.y = game_data->player_img->instances[0].y;
	next.x = (pixels.x + (steps_x * IMG_SIZE)) / IMG_SIZE;
	next.y = (pixels.y + (steps_y * IMG_SIZE)) / IMG_SIZE;
	if (is_move_posible(game_data, next.x, next.y) > 0)
	{
		game_data->player_img->instances[0].x += (steps_x * IMG_SIZE);
		game_data->player_img->instances[0].y += (steps_y * IMG_SIZE);
		if (game_data->map->lines[next.y][next.x] == 'C')
		{
			ft_printf("PESCAOOOOOO!!!! - RE-DRAW\n");
			game_data->map->lines[next.y][next.x] = '0';
			// redraw_scene(game_data); // FIXME - redraw scene
		}
		game_data->moves++;
		ft_printf("move: %d\n", game_data->moves);
	}
}
