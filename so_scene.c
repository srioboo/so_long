/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/26 20:00:57 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*get_map(char *game_map)
{
	char	*line;
	int		fd;
	int		x;
	int		y;
	t_map	*map;
	char	**lines;
	int		found;

	if (!game_map)
		fd = open("map.ber", O_RDONLY);
	else
		fd = open(game_map, O_RDONLY);
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