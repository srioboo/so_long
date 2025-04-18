/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/18 18:08:09 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(mlx_image_t *img, int x, int y, int color)
{
	mlx_put_pixel(img, x, y, color);
}

void	draw_rectangle(int keycode)
{
	printf("draw rectable: %d\n", keycode);
}

void	draw_square(int keycode)
{
	printf("draw square: %d\n", keycode);
}

void	draw_line(mlx_image_t *img, int x, int y, int x1, int y1, int color)
{
	while (x < x1 && y < y1)
		mlx_put_pixel(img, x, y, color);
}

void	draw_circle(int keycode)
{
	printf("draw circle: %d\n", keycode);
}
