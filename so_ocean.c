/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_ocean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/24 11:21:07 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_ocean(mlx_t *mlx, char *line, int y)
{
	int			result;
	int			x;
	mlx_image_t	*img;
	char		*relative_path;

	relative_path = "./img/png/ocean_64.png";
	img = get_image(mlx, relative_path);
	result = 0;
	x = 0;
	while (line[x] != 0)
	{
		result = mlx_image_to_window(mlx, img, x * IMG_SIZE, y * IMG_SIZE);
		x++;
	}
	if (result < 0)
		error();
	return (result);
}
