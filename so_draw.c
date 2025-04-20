/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/20 17:02:20 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(mlx_image_t *img, t_map_pos pos, int color)
{
	mlx_put_pixel(img, pos.x, pos.y, color);
}

void	draw_rectangle(int keycode)
{
	ft_printf("draw rectable: %d\n", keycode);
}

void	draw_square(int keycode)
{
	ft_printf("draw square: %d\n", keycode);
}

void	draw_line(mlx_image_t *img,
	t_map_pos pos_ini, t_map_pos pos_end, int color)
{
	while (pos_ini.x < pos_end.x && pos_ini.x < pos_end.y)
		mlx_put_pixel(img, pos_ini.x, pos_end.y, color);
}

void	draw_circle(int keycode)
{
	ft_printf("draw circle: %d\n", keycode);
}
