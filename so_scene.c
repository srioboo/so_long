/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/19 22:29:58 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	full_scene(mlx_t *mlx, char *line, int y)
{
	int	result;

	result = 0;
	result += draw_wall(mlx, line, y);
	result += draw_ocean(mlx, line, y);
	result += draw_door(mlx, line, y);
	result += draw_fish(mlx, line, y);
	return (result);
}

int	draw_scene(mlx_t *mlx)
{
	int			result;
	char		*line;
	int			fd;
	int			end;
	int			y;

	result = 0;
	end = 1;
	fd = open("map.ber", O_RDONLY);
	y = 0;
	while (end == 1) // TODO - sustituir por (line != NULL || line != 0)
	{
		line = get_next_line(fd);
		if (line != NULL || line != 0)
		{
			result = full_scene(mlx, line, y);
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
