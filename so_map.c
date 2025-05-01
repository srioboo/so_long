/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/02 12:13:19 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_map_path(char *map_path)
{
	int	fd;
	int is_valid;

	is_valid = TRUE;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		is_valid = FALSE;
	close(fd);
	return (is_valid);
}

int	is_valid_map_size(char *map_path)
{
	int		fd;
	char	*line;
	int		height;
	size_t	len;

	fd = open(map_path, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL && height > 0)
			break ;
		if (ft_strlen(line) != len)
		{
			line = ft_free(&line);
			close(fd);
			return (0);
		}
		height++;
	}
	close(fd);
	return (height);
}

static t_map	*test_data(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (map->lines[y] != NULL)
	{
		x = 0;
		while (map->lines[y][x] != '\0')
		{
			if (map->lines[y][x] == 'E')
				map->nbr_exit++;
			if (map->lines[y][x] == 'C')
				map->nbr_fish++;
			if (map->lines[y][x] == '0')
				map->nbr_ocean++;
			x++;
		}
		y++;
	}
	return (map);
}

static void	fill(char **tab, t_map_pos map_size,
			char target, t_map_pos player_pos)
{
	int		row;
	int		col;
	char	c;

	row = player_pos.y;
	col = player_pos.x;
	c = tab[row][col];
	if (row < 0 || col < 0 || row >= map_size.y || col >= map_size.x)
		return ;
	if ((tab[row][col] == 'X' || tab[row][col] != target) && (c != '0'))
		return ;
	tab[row][col] = 'X';
	fill(tab, map_size, target, (t_map_pos){col - 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col + 1, row, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row - 1, '\0'});
	fill(tab, map_size, target, (t_map_pos){col, row + 1, '\0'});
}

int	is_valid_data(t_map *map)
{
	int		result;
	char	target;

	result = TRUE;
	target = map->lines[map->player_y][map->player_x];
	fill(map->lines, (t_map_pos){map->map_with - 1, map->map_height - 1, '\0'},
		target, (t_map_pos){map->player_x, map->player_y, '\0'});
	map = test_data(map);
	if (map->nbr_player != 1 || map->nbr_exit != 1 || map->nbr_ocean > 1 || map->nbr_fish == 0)
		result = FALSE;
	if (map->nbr_player != 1)
		ft_printf("No player or two much players P: %d!!\n", map->nbr_player);
	else if (map->nbr_fish == 0)
		ft_printf("No fish C:%d \n", map->nbr_fish); 
	else if (map->nbr_exit != 1 || map->nbr_ocean > 1)
		ft_printf("No exit or exit not accesible!!\n", map->nbr_exit);
	return (result);
}
