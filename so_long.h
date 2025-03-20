/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:05:25 by srioboo-          #+#    #+#             */
/*   Updated: 2025/03/20 15:48:39 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx_linux/mlx.h"

// TODO - delete
# include <stdio.h>

# define W_HEIGHT	1080
# define W_WIDTH	1920

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

#endif