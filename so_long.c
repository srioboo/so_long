/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/24 11:50:15 by srioboo-         ###   ########.fr       */
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
	// draw_scene_test(vars);
	draw_scene(vars);
	draw_player(vars);

	// HOOKS
	mlx_hook(vars.win, 2, 1L<<0, close_window, &vars);
	// mlx_hook(vars.win, 4, 1L<<2, test_hooks, &vars);
	// mlx_key_hook(vars.win, close_window, &vars);

	mlx_loop(vars.mlx);
	return (0);
}