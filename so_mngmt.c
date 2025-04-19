/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/19 08:48:14 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	win_close(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}
