/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_door.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/19 22:20:38 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_door(mlx_t *mlx, char *line, int y)
{
	int			result;
	int			count;
	mlx_image_t	*img;
	char		*relative_path;

	relative_path = "./img/png/dungeon_door_64.png";
	img = get_image(mlx, relative_path);
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
