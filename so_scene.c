/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:27:53 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/18 17:52:37 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*get_ocean(mlx_t *mlx)
{
	char			*relative_path;
	mlx_image_t		*img_ocean;
	mlx_texture_t	*texture;

	relative_path = "./img/png/ocean_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img_ocean = mlx_texture_to_image(mlx, texture);
	if (!img_ocean)
		error();
	return (img_ocean);
}

static int	draw_ocean(mlx_t *mlx, mlx_image_t *img_ocean, char *line, int y)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == '0')
			result = mlx_image_to_window(mlx, img_ocean, count * 64, y * 64);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}

static mlx_image_t	*get_wall(mlx_t *mlx)
{
	char			*relative_path;
	mlx_image_t		*img_wall;
	mlx_texture_t	*texture;

	relative_path = "./img/png/wall_64x64.png";
	texture = mlx_load_png(relative_path);
	if (!texture)
		error();
	img_wall = mlx_texture_to_image(mlx, texture);
	if (!img_wall)
		error();
	return (img_wall);
}

static int	draw_wall(mlx_t *mlx, mlx_image_t *img_wall, char *line, int y)
{
	int	result;
	int	count;

	result = 0;
	count = 0;
	while (line[count] != 0)
	{
		if (line[count] == '1')
			result = mlx_image_to_window(mlx, img_wall, count * 64, y * 64);
		count++;
	}
	if (result < 0)
		error();
	return (result);
}

int	draw_scene(mlx_t *mlx)
{
	int			result;
	char		*line;
	int			fd;
	int			end;
	mlx_image_t	*mlx_wall;
	mlx_image_t	*mlx_ocean;
	int			y;

	end = 1;
	mlx_wall = get_wall(mlx);
	mlx_ocean = get_ocean(mlx);
	fd = open("map.ber", O_RDONLY);
	y = 0;
	while (end == 1)
	{
		line = get_next_line(fd);
		// TODO if y > 6 fail, because the file ends there, need to fix this
		if (line == NULL || y == 5)
			end = 0;
		printf("%s", line);
		result = draw_wall(mlx, mlx_wall, line, y);
		result = draw_ocean(mlx, mlx_ocean, line, y);
		free(line);
		line = NULL;
		y++;
	}
	close(fd);
	return (result);
}

// int	draw_scene_test(mlx_t *mlx)
// {
// 	mlx_image_t	*img;
// 	int			result;

// 	// TODO - not working
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	draw_pixel(img, 50, 5, C_RED);
// 	draw_pixel(img, 60, 5, C_GREEN);
// 	draw_pixel(img, 70, 5, C_BLUE);
// 	// TODO - throw an error
// 	// draw_line(img, 50, 50, 500, 500, C_BLUE);
// 	// for (uint32_t x = 0; x < img->width; x++)
// 	// 	for(uint32_t y= 0; y < img->height; y++)
// 	// 		mlx_put_pixel(img, x, y, rand() % RAND_MAX);

// 	result = mlx_image_to_window(mlx, img, 100, 100);
// 	return (result);
// }
