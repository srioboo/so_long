/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mngmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/20 18:00:46 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	win_close(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if ((keydata.key == MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path)
{
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	return (img);
}
