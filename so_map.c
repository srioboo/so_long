/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/01 09:02:51 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// TODO - control not existent path

/*
int	validate_map_size(char *line, int h)
{
	int	len;
	int len_ini;

	len = 0;
	len_ini = 0;
	if (line != NULL h == 0)
	{
		len_ini = ft_strlen()
	}
	return (h);
}*/

int	validate_map(char *game_map)
{
	int		fd;
	char	*line;
	int		height;
	size_t	len;

	fd = open(game_map, O_RDONLY);
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

static void	fill(char **tab, t_map_pos map_size, char target, int row, int col)
{
	// TODO - delete ft_printf("FILLING target %c row %d, col %d size(%d, %d)\n", target, row, col, map_size.x, map_size.y);
	char c = tab[row][col];
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
	fill(tab, map_size, target, row - 1, col);
	fill(tab, map_size, target, row + 1, col);
	fill(tab, map_size, target, row, col - 1);
	fill(tab, map_size, target, row, col + 1);
}

void	validate_data(char **tab, t_map_pos map_size, t_map_pos player_pos)
{
	char	target;

	target = tab[player_pos.y][player_pos.x];
	fill(tab, map_size, target, player_pos.y, player_pos.x);
}
