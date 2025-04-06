/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:25 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/06 19:47:23 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
// # include <MLX42/MLX42.h>
# include "MLX42/MLX42.h"

# include "so_colors.h"
# include "so_keys.h"

// TODO - delete or NOT?
# include <stdio.h>

# define WIDTH	512
# define HEIGHT	512
// # define WIDTH 256
// # define HEIGHT 256

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/**
 * @brief Draw a pixel
 */
void	draw_pixel(t_data *data, int x, int y, int color);

// TODO - create struct tipe vector to store x and y
void	draw_line(t_data *data, int x, int y, int x1, int y1, int color);

/**
 * @brief Close the window
 * 
 * @details Close the window when the ESC key is pressed
 */
int		close_window(int keycode, t_vars *vars);


/** 
 * SCENE
*/

/**
 * @brief Draw the scene
 * 
 * @details Draw the scene with the images
 */
int		draw_scene(mlx_t *mlx);

// TODO - Create with main test
// int		draw_scene_test(t_vars vars);

/**
 * @brief Draw the player
 * 
 * @details Draw the player with the images
 */
int		draw_player(mlx_t *mlx);

/**
 * @brief Move the player
 */
int		move_player(int keycode, t_vars *vars, t_data *img);

#endif