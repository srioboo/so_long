/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/21 16:32:20 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map(char **map_lines)
{
	int	y;
	int	x;

	y = 0;
	while (map_lines[y])
	{
		x = 0;
		while (map_lines[y][x])
		{
			ft_printf("%c", map_lines[y][x]);
			x++;
		}
		y++;
	}
}

void	error_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	process_moves(mlx_key_data_t keydata, void *param)
{
	t_game_data	*game_data;

	game_data = param;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(game_data, 1, 0);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(game_data, -1, 0);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(game_data, 0, -1);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_player(game_data, 0, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_game(game_data, BYE);
}

void	show_moves(int type, t_game_data *game_data)
{
	if (type == 0)
		ft_printf("move: %d\n", game_data->moves);
	else if (type == 1)
		mlx_put_string(game_data->mlx, ft_itoa(game_data->moves), 10, 10);
	else
	{
		ft_printf("move: %d\n", game_data->moves);
		mlx_put_string(game_data->mlx, ft_itoa(game_data->moves), 10, 10);
	}
}
