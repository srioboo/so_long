/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_manage_images.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/19 18:31:39 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_texture_t	*get_texture(t_game_data *game_data, char *relative_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(relative_path);
	if (!texture)
	{
		close_game(game_data, TEX);
		return (NULL);
	}
	return (texture);
}

mlx_image_t	*get_image(t_game_data *game_data, char *relative_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = get_texture(game_data, relative_path);
	img = mlx_texture_to_image(game_data->mlx, texture);
	if (!img)
		error_msg("Can't load the image");
	mlx_delete_texture(texture);
	return (img);
}

void	delete_images(t_game_data *game_data)
{
	if (game_data->ocean_img)
		mlx_delete_image(game_data->mlx, game_data->ocean_img);
	if (game_data->wall_img)
		mlx_delete_image(game_data->mlx, game_data->wall_img);
	if (game_data->fish_img)
		mlx_delete_image(game_data->mlx, game_data->fish_img);
	if (game_data->exit_img)
		mlx_delete_image(game_data->mlx, game_data->exit_img);
	if (game_data->player_img)
		mlx_delete_image(game_data->mlx, game_data->player_img);
}

t_game_data	*get_objects_images(t_game_data *game_data)
{
	game_data->wall_img = get_image(game_data,
			"./textures/wall_64.png");
	game_data->ocean_img = get_image(game_data,
			"./textures/ocean_64.png");
	game_data->exit_img = get_image(game_data,
			"./textures/luffys_flag_64.png");
	game_data->fish_img = get_image(game_data,
			"./textures/clown-fish_64.png");
	return (game_data);
}
