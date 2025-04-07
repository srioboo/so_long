/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/07 12:33:38 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Exit the program as failure.
/*static void ft_error(void)
{
	printf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}*/

// Print the window width and height.
// static void ft_hook(void* param)
// {
//	const mlx_t* mlx = param;

	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

int32_t	main(void)
{
	mlx_t*	mlx;

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(HD_WIDTH, HD_HEIGHT, "So long", true);
	if (!mlx)
		error();

	// TODO - DRAW SCENE AND PLAYER
	draw_scene_test(mlx);
	draw_scene(mlx);
	draw_player(mlx);


	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(img, 0, 0, 0xFF0000FF);


	/* OLD hooks and loops */
		// HOOKS
	// mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	// mlx_hook(vars.win, 4, 1L<<2, test_hooks, &vars);
	mlx_key_hook(mlx, &move_player, NULL);


	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	// mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}