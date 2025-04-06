/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/06 19:49:37 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// Written by Bruh

// #include <stdlib.h>
// #include <stdio.h>
// #include <unistd.h>
// #include "MLX42/MLX42.h"
// #define WIDTH 256
// #define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	mlx_t* mlx;
	/* OLD_INIT
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "So long");
	*/

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	/* OLD WINDOWS MNGMT
		vars.win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "So long");
	if (!vars.win)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	*/


	// Create and display the image.
	// mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	//if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
	//	ft_error();

	// TODO - DRAW SCENE AND PLAYER
	// draw_scene_test(vars);
	draw_scene(mlx);
	draw_player(mlx);


	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);
	//mlx_load_xpm42()
	// mlx_put_

	/* OLD hooks and loops
		// HOOKS
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	// mlx_hook(vars.win, 4, 1L<<2, test_hooks, &vars);
	mlx_key_hook(vars.win, move_player, &vars);
	mlx_loop(vars.mlx);
	*/

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}