/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/21 12:41:52 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	test_hooks(int keycode, t_vars *vars)
{
	printf("keycode: %d %p\n", keycode, vars->win);
	return (0);
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
	/** image pixel */
	img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);


	/** image */
	// void 	*test_img;
	char	*relative_path = "./img/xmark-white.xpm";
	int		img_width;
	int		img_height;
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	// lx_put_image_to_window(vars.mlx, vars.win, img.img, 800, 800);
	/** /image */


	draw_pixel(&img, 50, 5, C_RED);
	draw_pixel(&img, 60, 5, C_GREEN);
	draw_pixel(&img, 70, 5, C_BLUE);
	draw_line(&img, 50, 50, 500, 500, C_BLUE);
	/** /image pixel */

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);




	// mlx_hook(vars.win, 4, 1L<<2, test_hooks, &vars);
	// mlx_key_hook(vars.win, close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}