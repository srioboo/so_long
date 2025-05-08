/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/08 11:40:31 by srioboo-         ###   ########.fr       */
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

static t_map	*map_size(char *map_path)
{
	int		fd;
	char	*line;
	int		height;
	int		end;
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	fd = open(map_path, O_RDONLY);
	height = 0;
	end = TRUE;
	while (end == TRUE)
	{
		line = get_next_line(fd);
		if (height == 0 && line != NULL)
			map->map_with = ft_strlen(line) - 1;
		if (line == NULL)
			end = FALSE;
		free(line);
		height++;
	}
	map->map_height = height;
	map->map_path = map_path;
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
	if (fd == -1)
		return (NULL);
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
	t_map	*valid_map;

	valid_map = NULL;
	if (ft_strnstr(map_path, ".ber", ft_strlen(map_path)) == NULL)
		return (error_msg("Map extension not valid"), NULL);
	valid_map = map_size(map_path);
	valid_map = load_map(valid_map);
	if (!valid_map->lines)
		return (error_msg("Map path not valid"),
			free_map_lines(valid_map->lines), NULL);
	else if (is_valid_map_shape(valid_map) == FALSE)
		return (free_map_lines(valid_map->lines),
			error_msg("Map is not a rectangle"), NULL);
	else if (is_valid_map_borders(valid_map) == FALSE)
		return (free_map_lines(valid_map->lines),
			error_msg("Map is not surrounded by walls"), NULL);
	valid_map = process_map(valid_map);
	if (is_valid_data(valid_map) == FALSE)
		return (free_map_lines(valid_map->lines), free(valid_map), NULL);
	return (valid_map);
}
