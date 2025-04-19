/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/19 11:28:46 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_door(mlx_t *mlx)
{
	char			*relative_path;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	relative_path = "./img/png/dungeon_door_64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	return (img);
}

int	draw_door(mlx_t *mlx, mlx_image_t *img, char *line, int y)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == 'E')
			result = mlx_image_to_window(mlx, img, count * 64, y * 64);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}
