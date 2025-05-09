/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/09 17:48:00 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_map	*fill_map_data(t_map *map)
{
	int		x;
	int		y;
	char	**lines;

	lines = map->lines;
	y = 0;
	while (lines[y] != NULL)
	{
		x = 0;
		while ((lines[y] != NULL && lines[y][x] != '\0') && lines[y][x] != 'P')
			x++;
		if (lines[y][x] == 'P')
		{
			map->player_x = x;
			map->player_y = y;
			map->nbr_player++;
		}
		y++;
	}
	return (map);
}

static t_map	*map_init(t_map *map)
{
	int		fd;
	char	*line;
	int		end;

	fd = open(map->map_path, O_RDONLY);
	if (fd == -1)
		return (free(map), NULL);
	map->map_height = 0;
	end = TRUE;
	while (end == TRUE)
	{
		line = get_next_line(fd);
		if (map->map_height == 0 && line != NULL)
			map->map_with = ft_strlen(line) - 1;
		if (line == NULL)
			end = FALSE;
		free(line);
		map->map_height++;
	}
	close(fd);
	return (map);
}

static t_map	*load_map(t_map *map)
{
	int		fd;
	char	*line;
	int		y;
	int		end;

	fd = open(map->map_path, O_RDONLY);
	map->lines = (char **)malloc((map->map_height + 1) * sizeof(char *));
	if (!map->lines)
		return (close(fd), NULL);
	y = 0;
	end = TRUE;
	while (end == TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end = FALSE;
		map->lines[y] = line;
		y++;
	}
	close(fd);
	free(line);
	return (map);
}

static t_map	*process_map(t_map *map)
{
	if (!map)
		return (free_map_lines(map->lines), map);
	map->player_x = -1;
	map->player_y = -1;
	map = set_data_count(map);
	map = fill_map_data(map);
	return (map);
}

t_map	*get_map(char *map_path)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (free(map), NULL);
	map->map_path = map_path;
	map = map_init(map);
	if (!map)
		return (close_map(map, "Map path not valid"), NULL);
	map = load_map(map);
	if (is_valid_map_shape(map) == FALSE)
		return (close_map(map, "Map is not a rectangle"), NULL);
	else if (is_valid_map_borders(map) == FALSE)
		return (close_map(map, "Map is not surrounded by walls"), NULL);
	map = process_map(map);
	if (is_valid_data(map) == FALSE)
		return (close_map(map, NULL), NULL);
	return (map);
}
