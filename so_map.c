/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/27 17:09:41 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_map(char *game_map)
{
	int	fd;

	fd = 0;
	if (!game_map)
		fd = open("map.ber", O_RDONLY);
	else
		fd = open(game_map, O_RDONLY);
	return (fd);
}

int	validate_map(char *game_map)
{
	int		fd;
	char	*line;
	int		height;

	fd = load_map(game_map);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		height++;
	}
	close(fd);
	return (height);
}
