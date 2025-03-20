/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/20 10:56:32 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx_linux/mlx.h"

int	close_so_long(int keycode, t_vars *vars)
{
	printf("key");

	if (keycode == 9)
		return (mlx_destroy_window(vars->mlx, vars->win));
	return (0);
}

int	test_events(int keycode, t_vars *vars)
{
	printf("key: %d %p %p", keycode, vars->mlx, vars->win);

	//if (keycode == 9)
	//	return (mlx_destroy_window(vars->mlx, vars->win));
	return (0);
}

int	main(void)
{
	t_vars	vars;
	// void	*mlx_conn;
	// void	*mlx_window;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, W_WIDTH, W_HEIGHT, "So long");
	printf("win: %d %d", W_HEIGHT, W_WIDTH);
	// if (!vars.win)
	// {
	// 	mlx_destroy_display(vars.mlx);
	// 	free(vars.mlx);
	// 	return (1);
	// }

	mlx_hook(vars.win, 2, 1L<<0, close_so_long, &vars);
	mlx_hook(vars.win, 6, 1L<<4, test_events, &vars);

	mlx_loop(vars.mlx);

	// mlx_destroy_window(vars.mlx, vars.win);
	// mlx_destroy_display(vars.mlx);
	// free(vars.mlx);

	// return (0);
}