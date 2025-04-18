/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/18 18:44:56 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_scene(mlx_t *mlx)
{
	int			result;
	char		*line;
	int			fd;
	int			end;
	mlx_image_t	*mlx_wall;
	mlx_image_t	*mlx_ocean;
	int			y;

	end = 1;
	mlx_wall = get_wall(mlx);
	mlx_ocean = get_ocean(mlx);
	fd = open("map.ber", O_RDONLY);
	y = 0;
	while (end == 1)
	{
		line = get_next_line(fd);
		// TODO if y > 6 fail, because the file ends there, need to fix this
		if (line == NULL || y == 5)
			end = 0;
		printf("%s", line);
		result = draw_wall(mlx, mlx_wall, line, y);
		result = draw_ocean(mlx, mlx_ocean, line, y);
		free(line);
		line = NULL;
		y++;
	}
	close(fd);
	return (result);
}
