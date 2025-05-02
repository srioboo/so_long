/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/02 16:48:51 by srioboo-         ###   ########.fr       */
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

static t_map	*process_map(char *game_map, int height)
{
	char	*line;
	int		fd;
	t_map	*map;
	char	**lines;

	fd = open(game_map, O_RDONLY);
	lines = (char **)ft_calloc(height + 1, sizeof(char *));
	height = 0;
	line = get_next_line(fd);
	lines[height] = line;
	height++;
	while (line != NULL)
	{
		line = get_next_line(fd);
		lines[height] = line;
		height++;
	}
	map = ft_calloc(8, sizeof(t_map)); // BUG - map size?
	map->map_height = height;
	map->map_with = ft_strlen(lines[0]) - 1;
	map->lines = lines;
	map = fill_map_data(map);
	close(fd);
	return (map);
}

t_map	*get_map(char *map_path)
{
	int		height;
	t_map	*map;

	map = NULL;
	if (is_valid_map_path(map_path) == FALSE)
		ft_printf("Error\nmap path %d not valid", map_path);
	height = is_valid_map_size(map_path);
	if (height == 0)
		ft_printf("Error\nmap %s is not a rectangle", map_path);
	else if (is_valid_data(process_map(map_path, height)) == TRUE)
		map = process_map(map_path, height);
	return (map);
}

static int	draw_all(t_game_data *game_data, char type, int x, int y)
{
	int	result;

	result = 0;
	if (game_data->redraw == 0)
	{
		result += draw_ocean(game_data, type, x, y);
		result += draw_wall(game_data, type, x, y);
		result += draw_exit(game_data, type, x, y);
	}
	result += draw_fish(game_data, type, x, y);
	return (result);
}

int	draw_scene(t_game_data *game_data)
{
	int		result;
	int		y;
	int		x;
	char	**lines;
	int		nbr_lines;

	result = 0;
	y = 0;
	lines = game_data->map->lines;
	nbr_lines = game_data->map->map_height;
	game_data = get_objects_images(game_data);
	while (y < (nbr_lines - 1))
	{
		x = 0;
		while (lines[y][x] != 0)
		{
			result = draw_all(game_data, lines[y][x], x, y);
			x++;
		}
		y++;
	}
	return (result);
}
