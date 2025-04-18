/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_ocean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/18 18:08:53 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*get_ocean(mlx_t *mlx)
{
	char			*relative_path;
	mlx_image_t		*img_ocean;
	mlx_texture_t	*texture;

	relative_path = "./img/png/ocean_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img_ocean = mlx_texture_to_image(mlx, texture);
	if (!img_ocean)
		error();
	return (img_ocean);
}

int	draw_ocean(mlx_t *mlx, mlx_image_t *img_ocean, char *line, int y)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == '0')
			result = mlx_image_to_window(mlx, img_ocean, count * 64, y * 64);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}
