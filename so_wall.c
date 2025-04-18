/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:57:33 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/18 18:01:22 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_wall(mlx_t *mlx)
{
	char			*relative_path;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

	relative_path = "./img/png/wall_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img_wall = mlx_texture_to_image(mlx, texture);
	if (!img_wall)
		error();
	return (img_wall);
}

int	draw_wall(mlx_t *mlx, mlx_image_t *img_wall, char *line, int y)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == '1')
			result = mlx_image_to_window(mlx, img_wall, count * 64, y * 64);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}
