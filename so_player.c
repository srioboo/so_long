/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/01 19:57:52 by srioboo-         ###   ########.fr       */
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

	img_width = 5;
	img_height = 5;
	relative_path = "./img/dolphin_64x64.xpm";
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path,
			&img_width, &img_height);
	result = mlx_put_image_to_window(vars.mlx, vars.win, img.img,
			800, 100);
	return (result);
}

static void	move(t_vars vars, t_data img, int amount_x, int amount_y)
{
	mlx_put_image_to_window(vars.mlx, vars.win, img.img,
		800 + amount_x, 100 + amount_y);
}

int	move_player(int keycode, t_vars *vars, t_data *img)
{
	printf("keycode: %d %p\n", keycode, vars->win);
	if (keycode == KEY_RIGHT)
		move(*vars, *img, 10, 0);//printf("move: %d\n", keycode);
	if (keycode == KEY_LEFT)
		printf("move: %d\n", keycode);
	if (keycode == KEY_UP)
		printf("move: %d\n", keycode);
	if (keycode == KEY_DOWN)
		printf("move: %d\n", keycode);
	return (0);
}
