/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/07 13:31:49 by srioboo-         ###   ########.fr       */
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

static int	map_size(char *map_path)
{
	int		fd;
	char	*line;
	int		height;
	int		end;

	fd = open(map_path, O_RDONLY);
	height = 0;
	end = 1;
	while (end == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			end = 0;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static char	**load_map(char *game_map, int height)
{
	int		fd;
	char	**lines;
	char	*line;
	int		y;

	fd = open(game_map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	lines = (char **)malloc((height + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	y = 0;
	line = get_next_line(fd);
	lines[y] = line;
	y++;
	while (line)
	{
		line = get_next_line(fd);
		lines[y] = line;
		y++;
	}
	close(fd);
	return (lines);
}

static t_map	*process_map(char *map_path, int height)
{
	t_map	*map;
	char	**map_lines;

	map = NULL;
	map_lines = NULL;
	map_lines = load_map(map_path, height);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (free_map_lines(map_lines), map);
	map->map_height = height;
	map->map_with = ft_strlen(map_lines[0]) - 1;
	map->lines = map_lines;
	map->player_x = -1;
	map->player_y = -1;
	map = set_data_count(map);
	map = fill_map_data(map);
	return (map);
}

t_map	*get_map(char *map_path)
{
	int		height;
	char	**map_lines;
	t_map	*valid_map;

	valid_map = NULL;
	height = map_size(map_path);
	map_lines = load_map(map_path, height);
	if (!map_lines)
		return (error_msg("Map path not valid"),
			free_map_lines(map_lines), NULL);
	else if (is_valid_map_shape(map_lines) == FALSE)
		return (NULL);
	else if (is_valid_map_borders(map_lines, height) == FALSE)
		return (NULL);
	valid_map = process_map(map_path, height);
	if (is_valid_data(valid_map) == FALSE)
		return (NULL);
	return (valid_map);
}
