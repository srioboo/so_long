/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/23 20:57:15 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_scene(t_vars vars)
{
	t_data	img;
	int		result;
	char	*relative_path;
	int		img_width;
	int		img_height;

	relative_path = "./img/xmark-white.xpm";
	// relative_path = "./img/world_tilset.png";
	// TODO - texture to image require OPENGL
	//img.img = mlx_texture_to_image(vars.mlx, relative_path, 
	//	&img_width, &img_height);
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path,
		&img_width, &img_height);
	result = mlx_put_image_to_window(vars.mlx, vars.win, img.img,
			0, 0);
	return (result);
}

int	draw_scene_test(t_vars vars)
{
	t_data	img;
	int		result;

	img.img = mlx_new_image(vars.mlx, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_pixel(&img, 50, 5, C_RED);
	draw_pixel(&img, 60, 5, C_GREEN);
	draw_pixel(&img, 70, 5, C_BLUE);
	draw_line(&img, 50, 50, 500, 500, C_BLUE);
	result = mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	return (result);
}
