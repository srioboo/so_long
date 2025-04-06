/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/06 19:51:40 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	draw_player(mlx_t *mlx)
{
	int				result;
	char			*relative_path;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	relative_path = "./img/png/dolphin_32x32.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(mlx, img, 30, 30);
	if (result < 0)
		error();
	return (result);
}

/* TODO - enable moviment
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
*/