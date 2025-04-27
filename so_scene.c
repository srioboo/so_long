/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/27 17:08:54 by srioboo-         ###   ########.fr       */
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
	int		height;
	t_map	*map;
	char	**lines;

	height = validate_map(game_map);
	fd = load_map(game_map);
	lines = (char **)ft_calloc(height + 1, sizeof(char *)); // TODO - this is wrong
	height = 0;
	line = get_next_line(fd);
	lines[height++] = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		lines[height++] = line;
	}
	lines[height] = NULL;
	map = ft_calloc(8, sizeof(t_map));
	map->map_with = ft_strlen(lines[0]) - 1;
	map->lines = lines;
	map->map_height = height;
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