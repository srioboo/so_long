/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:25 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 08:50:29 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <MLX42/MLX42.h>
// # include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "so_colors.h"

// SD size 1280 x 720
# define WIDTH	1280
# define HEIGHT	720

// HD size 1920×1080
# define HD_WIDTH	1920
# define HD_HEIGHT	1080

# define IMG_SIZE 64

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_map_pos
{
	int		x;
	int		y;
	char	type;
}	t_map_pos;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_map
{
	//struct s_map_pos	*positions;
	char				**lines;
	int					map_height;
	int					map_with;
	struct s_player		player;
}	t_map;

/* ************************************************************************** */
/* DRAW                                                                      */
/* ************************************************************************** */

/**
 * @brief Draw a pixel
 */
void		draw_pixel(mlx_image_t *img, t_map_pos pos, int color);

/**
 * @brief Draw a line
 */
void		draw_line(mlx_image_t *img,
				t_map_pos pos_ini, t_map_pos pos_end, int color);

/* ************************************************************************** */
/* SCENE                                                                      */
/* ************************************************************************** */

/**
 * @brief Draw the scene
 * 
 * @details Draw the scene with the images
 */
int			draw_scene(mlx_t *mlx);

/* ************************************************************************** */
/* PLAYER                                                                     */
/* ************************************************************************** */

/**
 * @brief Draw the player
 * 
 * @details Draw the player with the images
 */
mlx_image_t	*draw_player(mlx_t *mlx);

/**
 * @brief Move the player
 */
void		move_player(mlx_key_data_t keydata, void *param);

/* ************************************************************************** */
/* GAME MANAGEMENT                                                            */
/* ************************************************************************** */

/**
 * @brief Error management
 */
void		error(void);

void		win_close(mlx_key_data_t keydata, void *param);

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path);

/* ************************************************************************** */
/* WALL                                                                       */
/* ************************************************************************** */

int			draw_wall(mlx_t *mlx, char *line, int y);

/* ************************************************************************** */
/* WALL                                                                       */
/* ************************************************************************** */

int			draw_ocean(mlx_t *mlx, char *line, int y);

/* ************************************************************************** */
/* DOOR                                                                       */
/* ************************************************************************** */

int			draw_door(mlx_t *mlx, char *line, int y);

/* ************************************************************************** */
/* FISH                                                                       */
/* ************************************************************************** */

int			draw_fish(mlx_t *mlx, char *line, int y);

#endif