/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 22:25:18 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	process_moves(mlx_key_data_t keydata, void *param)
{
	t_game_data			*data;
	static mlx_image_t	*img;
	int					step;

	data = param;
	img = data->player_img;
	step = IMG_SIZE / 2;
	if ((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		move(img, step, 0);
	if ((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		move(img, -step, 0);
	if ((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		move(img, 0, -step);
	if ((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		move(img, 0, step);
	if (keydata.key == MLX_KEY_ESCAPE)
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
