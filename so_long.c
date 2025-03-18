/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:07:39 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/18 13:07:40 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void *mlx_conn;
	void *mlx_window;
	
	mlx_conn = mlx_init();
	if (!mlx_conn)
		return (1);
	mlx_window = mlx_new_window(mlx_conn, 200, 200, "so long");
	if (mlx_window)
	{
		mlx_destroy_display(mlx_conn);
		free(mlx_conn);
		return (1);
	}
	mlx_loop(mlx_conn);
	mlx_destroy_window(mlx_conn, mlx_window);

	mlx_destroy_display(mlx_conn);
	free(mlx_conn);
	return (0);
}