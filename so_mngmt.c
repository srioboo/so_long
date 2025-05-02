/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/02 15:28:49 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_window(t_game_data *game_data)
{
	// TODO - here need to release memory
	mlx_delete_image(game_data->mlx, game_data->exit_img);
	mlx_delete_image(game_data->mlx, game_data->fish_img);
	mlx_delete_image(game_data->mlx, game_data->wall_img);
	mlx_delete_image(game_data->mlx, game_data->ocean_img);
	game_data->exit_img = NULL;
	game_data->fish_img = NULL;
	game_data->wall_img = NULL;
	mlx_close_window(game_data->mlx);
}

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
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
		close_window(game_data);
}
mlx_texture_t *get_texture(char *relative_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	return (texture);
}

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = get_texture(relative_path);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	mlx_delete_texture(texture);
	return (img);
}
