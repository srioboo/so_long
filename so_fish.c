/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_fish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:56:29 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/25 12:58:37 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	find_fish()
// {
// }

int	draw_fish(t_game_data *game_data, char *line, int y)
{
	int			result;
	int			x;
	// mlx_image_t	*img;
	char		*relative_path;

	relative_path = "./img/clown-fish_64.png";
	game_data->fish_img = get_image(game_data->mlx, relative_path);
	result = 0;
	x = 0;
	while (line[x] != 0)
	{
		if (line[x] == 'C')
		{
			// ft_printf("fish: %c\n", line[x], y);
			result = mlx_image_to_window(game_data->mlx, game_data->fish_img,
					x * IMG_SIZE, y * IMG_SIZE);
			// game_data->fish_img
		}
		x++;
	}
	if (result < 0)
		error();
	return (result);
}
