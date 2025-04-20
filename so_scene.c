/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 10:54:02 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*get_map()
{
	char		*line;
	int			fd;
	int			end;
	int			y;
	t_map		*map;
	char		**lines;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (map);
	end = 1;
	fd = open("map.ber", O_RDONLY);
	y = 0;
	lines = (char **)malloc(sizeof(char *) * 8);
	if (lines == NULL)
		lines = NULL;
	while (end == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end = 0;
		else
			lines[y] = line;
		y++;
	}
	lines[y] = NULL;
	map->lines = lines;
	map->map_height = y;
	close(fd);
	return (map);
}

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
	int		result;
	int		y;
	char	**lines;
	int		nbr_lines;
	t_map	*map;

	map = get_map();
	result = 0;
	y = 0;
	lines = map->lines;
	nbr_lines = map->map_height;

	while (y < (nbr_lines - 1))
	{
		result = full_scene(mlx, lines[y], y);
		y++;
	}
	return (result);
}
