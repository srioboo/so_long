/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/01 11:40:38 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_path(char *map_path)
{
	int	fd;

	fd = 0;
	// TODO - control not existent path	ft_printf("ERRORRRRRRR");
	fd = open(map_path, O_RDONLY);
	close(fd);
	return (fd);
}

int	validate_map_size(char *map_path)
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

static void	fill(char **tab, t_map_pos map_size,
			char target, t_map_pos player_pos)
{
	int		row;
	int		col;
	char	c;

	row = player_pos.x;
	col = player_pos.y;
	// TODO - delete ft_printf("FILLING target %c row %d, col %d size(%d, %d)\n", target, row, col, map_size.x, map_size.y);
	c = tab[row][col];
	if (row < 0 || col < 0 || row >= map_size.y || col >= map_size.x)
		return ;
	if ((tab[row][col] == 'X' || tab[row][col] != target) && (c != '0' && c != 'C')) // TODO - C comprobation is really necesary
		return ;
	tab[row][col] = 'X';
	// TODO - DELETE
	ft_printf("x:%d y:%d\n", row - 1, col);
	ft_printf("x:%d y:%d\n", row + 1, col);
	ft_printf("x:%d y:%d\n", row, col - 1);
	ft_printf("x:%d y:%d\n", row, col + 1);
	ft_printf("=======\n");
	fill(tab, map_size, target, (t_map_pos){row - 1, col, '\0'});
	fill(tab, map_size, target, (t_map_pos){row + 1, col, '\0'});
	fill(tab, map_size, target, (t_map_pos){row, col - 1, '\0'});
	fill(tab, map_size, target, (t_map_pos){row, col + 1, '\0'});
}

void	validate_data(t_map *map)
{
	char	target;

	target = map->lines[map->player_y][map->player_x];
	fill(map->lines, (t_map_pos){map->map_with - 1, map->map_height - 1, '\0'},
		target, (t_map_pos){map->player_x, map->player_y, '\0'});
}
