/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/19 11:33:34 by srioboo-         ###   ########.fr       */
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
	mlx_image_t	*mlx_door;
	mlx_image_t	*mlx_fish;
	int			y;

	result = 0;
	end = 1;
	mlx_wall = get_wall(mlx);
	mlx_ocean = get_ocean(mlx);
	mlx_door = get_door(mlx);
	mlx_fish = get_fish(mlx);
	fd = open("map.ber", O_RDONLY);
	y = 0;
	while (end == 1)
	{
		line = get_next_line(fd);
		ft_printf("%s", line);
		if (line != NULL || line != 0)
		{
			result = draw_wall(mlx, mlx_wall, line, y);
			result = draw_ocean(mlx, mlx_ocean, line, y);
			result = draw_door(mlx, mlx_door, line, y);
			result = draw_fish(mlx, mlx_fish, line, y);
			free(line);
			line = NULL;
		}
		else
			end = 0;
		y++;
	}
	close(fd);
	return (result);
}
