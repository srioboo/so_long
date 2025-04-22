/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 22:17:33 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(void)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	t_map	*map;
	char	**lines;
	int		found;

	fd = open("map.ber", O_RDONLY);
	lines = (char **)ft_calloc(8, sizeof(char *));
	line = get_next_line(fd);
	y = 0;
	lines[y++] = line;
	map = ft_calloc(1, sizeof(t_map));
	map->map_with = ft_strlen(line) - 1;
	found = -1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		x = 0;
		while ((line != NULL && line[x] != '\0') && found == -1)
		{
			if (line[x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				found = 0;
			}
			x++;
		}
		lines[y++] = line;
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

int	draw_scene(mlx_t *mlx, t_map *map)
{
	int		result;
	int		y;
	char	**lines;
	int		nbr_lines;

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
