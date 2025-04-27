/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/27 10:55:54 by srioboo-         ###   ########.fr       */
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
		}
		y++;
	}
	return (map);
}

t_map	*get_map(char *game_map)
{
	char	*line;
	int		fd;
	int		y;
	t_map	*map;
	char	**lines;

	if (!game_map)
		fd = open("map.ber", O_RDONLY);
	else
		fd = open(game_map, O_RDONLY);
	lines = (char **)ft_calloc(8, sizeof(char *)); // TODO - this is wrong
	y = 0;
	line = get_next_line(fd);
	lines[y++] = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		lines[y++] = line;
	}
	lines[y] = NULL;
	map = ft_calloc(8, sizeof(t_map));
	map->map_with = ft_strlen(lines[0]) - 1;
	map->lines = lines;
	map->map_height = y;
	map = fill_map_data(map);
	close(fd);
	return (map);
}

int	draw_scene(t_game_data *game_data)
{
	int		result;
	int		y;
	char	**lines;
	int		nbr_lines;
	mlx_t	*mlx;

	mlx = game_data->mlx;
	result = 0;
	y = 0;
	lines = game_data->map->lines;
	nbr_lines = game_data->map->map_height;
	while (y < (nbr_lines - 1))
	{
		result += draw_ocean(mlx, lines[y], y);
		result += draw_wall(mlx, lines[y], y);
		result += draw_exit(mlx, lines[y], y);
		result += draw_fish(game_data, lines[y], y);
		y++;
	}
	return (result);
}

int	redraw_scene(t_game_data *game_data)
{
	int		result;
	int		y;
	// char	**lines;
	int		nbr_lines;

	result = 0;
	y = 0;
	// lines = game_data->map->lines;
	nbr_lines = game_data->map->map_height;
	while (y < (nbr_lines - 1))
	{
		// result += redraw_fish(game_data, lines[y], y);
		y++;
	}
	return (result);
}