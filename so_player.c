/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/23 20:19:35 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_player(t_vars vars)
{
	t_data	img;
	int		result;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./resources/img/xmark-white.png";
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path,
			&img_width, &img_height);
	result = mlx_put_image_to_window(vars.mlx, vars.win, img.img,
			800, 100);
	return (result);
}

int	move_character(int keycode, t_vars *vars)
{
	printf("keycode: %d %p\n", keycode, vars->win);
	if (keycode == KEY_RIGHT)
		printf("move: %d\n", keycode);
	if (keycode == KEY_LEFT)
		printf("move: %d\n", keycode);
	if (keycode == KEY_UP)
		printf("move: %d\n", keycode);
	if (keycode == KEY_DOWN)
		printf("move: %d\n", keycode);
	return (0);
}