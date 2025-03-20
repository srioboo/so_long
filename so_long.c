/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/20 16:54:06 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_so_long(int keycode, t_vars *vars)
{
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
	{
		printf("exit: %d\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "So long");
	if (!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}

	img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);

	mlx_hook(vars.win, 2, 1L<<0, close_so_long, &vars);
	// mlx_key_hook(vars.win, close_so_long, &vars);

	mlx_loop(vars.mlx);
	return (0);
}