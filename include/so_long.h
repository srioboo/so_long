/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:25 by srioboo-          #+#    #+#             */
/*   Updated: 2025/05/02 15:32:18 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <MLX42/MLX42.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "so_colors.h"
// # include <stdio.h>

// HD size 1920×1080
# define HD_WIDTH	1920

// Image size
# define IMG_SIZE 64

# define TRUE 1
# define FALSE 0

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
	char	**lines;
	int		map_height;
	int		map_with;
	int		player_x;
	int		player_y;
	int		nbr_player;
	int		nbr_exit;
	int		nbr_ocean;
	int		nbr_fish;
}	t_map;

typedef struct s_game_data
{
	void			*mlx;
	mlx_image_t		*player_img;
	mlx_image_t		*fish_img;
	mlx_image_t		*ocean_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*exit_img;
	struct s_player	*player;
	struct s_map	*map;
	int				moves;
	int				redraw;
}	t_game_data;

/* ************************************************************************** */
/* MAP                                                                      */
/* ************************************************************************** */

/**
 * @brief Validate map is correct
 * 
 * @param map_path string with map path
 * @return if correct return true
 */
int			is_valid_map_path(char *map_path);

/**
 * @brief Validate map is correct
 * 
 * @details Validate map and, if correct, return height
 * @param map_path string with map path
 * @return if correct return height of the map
 */
int			is_valid_map_size(char *map_path);

/**
 * @brief Validate map data
 * @param map structure with map data
 * @return 0 if cant validate, 1 if data are ok
 */
int			is_valid_data(t_map *map);

/**
 * @brief load a map
 * 
 * @param game_map struct with game data
 * @return file descriptor of the map
 */
// int			load_map(char *game_map);

/* ************************************************************************** */
/* SCENE                                                                      */
/* ************************************************************************** */

/**
 * @brief Get the map
 * 
 * @param game_map struct with game data
 * @return the map struct with player data
 */
t_map		*get_map(char *game_map);

/**
 * @brief Draw the scene
 * 
 * @details Draw the scene with the images
 * @param game_map struct with game data
 * @return 0 or 1 if the scene has or not errors
 */
int			draw_scene(t_game_data *game_data);

/* ************************************************************************** */
/* PLAYER                                                                     */
/* ************************************************************************** */

/**
 * @brief Draw the player
 * 
 * @details Draw the player with the images
 * @param game_map struct with game data
 * @return the player img
 */
mlx_image_t	*draw_player(t_game_data *game_data);

/**
 * @brief Move the player
 * 
 * @param game_map struct with game data
 * @param steps_x steps moving in x
 * @param steps_y steps moving in y
 */
void		move_player(t_game_data *game_data,
				int steps_x, int steps_y);

/* ************************************************************************** */
/* GAME MANAGEMENT                                                            */
/* ************************************************************************** */

/**
 * @brief close clean the windows
 * 
 * @param game_data
 */
void		close_window(t_game_data *game_data);

/**
 * @brief Error management
 */
void		error(void);

/**
 * @brief get a texture from path
 * 
 * @param relative_path the path to the texture
 * @return a texture
 */
mlx_texture_t *get_texture(char *relative_path);

/**
 * @brief get a image
 * 
 * @param mlx
 * @param relative_path in witch the image can be found
 * 
 * @return and image
 */
mlx_image_t	*get_image(mlx_t *mlx, char *relative_path);

/**
 * @brief Move the player
 * 
 * @param keydata with
 * @param param, generally game data
 */
void		process_moves(mlx_key_data_t keydata, void *param);

/* ************************************************************************** */
/* OBJECTS                                                                    */
/* ************************************************************************** */

/**
 * @brief draw fish
 * 
 * @param game_data
 * @param type 1, 0, E, C, P
 * @param x position
 * @param y position
 * 
 * @return 1 if is draw 0 if wasn't posible for son error
 */
int			draw_fish(t_game_data *game_data, char type, int x, int y);

/**
 * @brief delete fish
 * 
 * @param game_data
 * @param x position
 * @param y position
 * 
 */
void		delete_fish_instance(t_game_data *game_data, int x, int y);

/* ************************************************************************** */
/* OBJECTS                                                                    */
/* ************************************************************************** */

/**
 * @brief draw wall
 * 
 * @param game_data
 * @param type 1, 0, E, C, P
 * @param x position
 * @param y position
 * 
 * @return 1 if is draw 0 if wasn't posible for son error
 */
int			draw_wall(t_game_data *game_data, char type, int x, int y);

/**
 * @brief draw ocean
 * 
 * @param game_data
 * @param type 1, 0, E, C, P
 * @param x position
 * @param y position
 * 
 * @return 1 if is draw 0 if wasn't posible for son error
 */
int			draw_ocean(t_game_data *game_data, char type, int x, int y);

/**
 * @brief draw exit
 * 
 * @param game_data
 * @param type 1, 0, E, C, P
 * @param x position
 * @param y position
 * 
 * @return 1 if is draw 0 if wasn't posible for son error
 */
int			draw_exit(t_game_data *game_data, char type, int x, int y);

/**
 * @brief get all images
 * 
 * @param game_data
 * 
 * @return game_data
 */
t_game_data	*get_objects_images(t_game_data *game_data);

#endif