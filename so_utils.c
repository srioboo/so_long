/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/05 10:26:17 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

mlx_texture_t	*get_texture(char *relative_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(relative_path);
	if (!texture)
		error_msg("Can't load the texture");
	return (texture);
}

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = get_texture(relative_path);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error_msg("Can't load the image");
	mlx_delete_texture(texture);
	return (img);
}
