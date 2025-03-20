/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/20 23:51:33 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_rectangle(int keycode)
{
	printf("draw rectable: %d\n", keycode);
}

void	draw_square(int keycode)
{
	printf("draw square: %d\n", keycode);
}

void	draw_line(t_data *data, int x, int y, int x1, int y1, int color)
{
	while (x < x1 && y < y1)
		draw_pixel(data, x++, y++, color);
}

void	draw_circle(int keycode)
{
	printf("draw circle: %d\n", keycode);
}