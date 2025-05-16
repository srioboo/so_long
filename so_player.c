/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/16 12:24:11 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*draw_player(t_game_data *game_data)
{
	mlx_image_t		*img;
	int				result;
	mlx_texture_t	*texture;

	texture = get_texture(game_data, "./textures/dolphin_64.png");
	img = mlx_texture_to_image(game_data->mlx, texture);
	if (!img)
		error_msg("Can't draw the player");
	result = mlx_image_to_window(game_data->mlx, img,
			IMG_SIZE * (game_data->map->player_x),
			IMG_SIZE * (game_data->map->player_y));
	if (result < 0)
		error_msg("Can't show the player in the window");
	mlx_delete_texture(texture);
	return (img);
}

void	is_player_blocked(t_map *map, int y, int x)
{
	if ((map->lines[y + 1][x] == '1') && (map->lines[y - 1][x] == '1')
		&& (map->lines[y][x - 1] == '1') && (map->lines[y][x + 1] == '1')
	)
		map->player_blocked = TRUE;
}

static int	is_move_posible(t_game_data *game_data, int next_x, int next_y)
{
	int	can_move;

	can_move = 1;
	if (next_x < 0 || next_y < 0
		|| next_x >= game_data->map->map_with
		|| next_y >= (game_data->map->map_height)
		|| game_data->map->lines[next_y][next_x] == '1')
		can_move = 0;
	return (can_move);
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
	if (is_move_posible(game_data, next.x, next.y) > 0 && game_data->game_start)
	{
		game_data->player_img->instances[0].x += (steps_x * IMG_SIZE);
		game_data->player_img->instances[0].y += (steps_y * IMG_SIZE);
		if (game_data->map->lines[next.y][next.x] == 'C')
		{
			game_data->map->lines[next.y][next.x] = '0';
			delete_fish_instance(game_data, next.x, next.y);
			game_data->redraw = 1;
			draw_scene(game_data);
		}
		if (game_data->map->lines[next.y][next.x] == 'E'
			&& game_data->fish_img->count == 0)
			close_game(game_data, WIN);
		game_data->moves++;
		ft_printf("move: %d\n", game_data->moves);
	}
}
