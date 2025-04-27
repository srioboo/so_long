/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/27 11:59:24 by srioboo-         ###   ########.fr       */
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


// int	validate_path(char *path)
// {

// }

int	validate_map(void)
{
	int	is_valid;
	int	fd;

	fd = 0;


	is_valid = TRUE;

	close(fd);
	return (is_valid);
}
