/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:25 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 22:06:14 by srioboo-         ###   ########.fr       */
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

// HD size 1920×1080
# define HD_WIDTH	1920

// Image size
# define IMG_SIZE 64

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

// TODO - is this usefull?
typedef struct s_map_pos
{
	int		x;
	int		y;
	char	type;
}	t_map_pos;

typedef struct s_player
{
	int			x_ini;
	int			y_ini;
	int			x;
	int			y;
	mlx_image_t	*player_img;
}	t_player;

typedef struct s_map
{
	//struct s_map_pos	*positions;
	char	**lines;
	int		map_height;
	int		map_with;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_game_data
{
	void			*mlx;
	mlx_image_t		*player_img;
	struct s_player	*player;
	struct s_map	*map;
}	t_game_data;

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
 * @brief Get the map
 */
t_map		*get_map(void);

/**
 * @brief Draw the scene
 * 
 * @details Draw the scene with the images
 */
int			draw_scene(mlx_t *mlx, t_map *map);

/* ************************************************************************** */
/* PLAYER                                                                     */
/* ************************************************************************** */

/**
 * @brief Draw the player
 * 
 * @details Draw the player with the images
 */
mlx_image_t	*draw_player(mlx_t *mlx, t_game_data *data);

void		move(mlx_image_t *img, int amount_x, int amount_y);

/* ************************************************************************** */
/* GAME MANAGEMENT                                                            */
/* ************************************************************************** */

/**
 * @brief Error management
 */
void		error(void);

void		win_close(mlx_key_data_t keydata, void *param);

mlx_image_t	*get_image(mlx_t *mlx, char *relative_path);

/**
 * @brief Move the player
 */
void		process_moves(mlx_key_data_t keydata, void *param);

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