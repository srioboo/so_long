/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/07 12:28:27 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_scene(mlx_t *mlx)
{
	int				result;
	char			*relative_path;
	mlx_image_t		*img;
	mlx_texture_t	*texture;

	// TODO - add map to draw the complete map
	relative_path = "./img/png/wall_32x32.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	result = mlx_image_to_window(mlx, img, 0, 0);
	if (result < 0)
		error();
	return (result);
}

int	draw_scene_test(mlx_t *mlx)
{
	mlx_image_t	*img;
	int			result;

	// TODO - not working
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	draw_pixel(img, 50, 5, C_RED);
	draw_pixel(img, 60, 5, C_GREEN);
	draw_pixel(img, 70, 5, C_BLUE);
	// TODO - throw an error
	// draw_line(img, 50, 50, 500, 500, C_BLUE);
	for (uint32_t x = 0; x < img->width; x++)
		for(uint32_t y= 0; y < img->height; y++)
			mlx_put_pixel(img, x, y, rand() % RAND_MAX);

	result = mlx_image_to_window(mlx, img, 100, 100);
	return (result);
}
