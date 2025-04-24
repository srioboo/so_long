/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/24 10:57:32 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int		is_move_posible(int next_x, int next_y)
{
	int can_move;

	can_move = 1;
	if (next_x < 0 || next_y < 0)
		can_move = 0;
	ft_printf("can move (%d,%d)?: %d\t", next_x, next_y, can_move); // TODO - remove
	return (can_move);
}

void	process_moves(mlx_key_data_t keydata, void *param)
{
	t_game_data			*data;
	static mlx_image_t	*img;

	data = param;
	img = data->player_img;
	ft_printf("INITIAL: %d,%d\t", img->instances[0].x / IMG_SIZE, img->instances[0].y / IMG_SIZE); // TODO - remove
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_player(img, data, 1, 0);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_player(img, data, -1, 0);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && keydata.action == MLX_PRESS)
		move_player(img, data, 0, -1);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_player(img, data, 0, 1);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	return (img);
}
