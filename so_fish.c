/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_fish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/24 11:06:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_fish(mlx_t *mlx, char *line, int y)
{
	int			result;
	int			count;
	mlx_image_t	*img;
	char		*relative_path;

	relative_path = "./img/png/clown-fish_64.png";
	img = get_image(mlx, relative_path);
	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == 'C')
			result = mlx_image_to_window(mlx, img, count * IMG_SIZE, y * IMG_SIZE);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}
