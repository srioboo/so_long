/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srioboo- <srioboo-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:01:11 by srioboo-          #+#    #+#             */
/*   Updated: 2025/04/22 10:02:00 by srioboo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

/**
 * @brief get the next line
 *
 * @param the file descriptor id
 * @return the next line
 */
char	*get_next_line(int fd);
char	*ft_free(char **str);

// functions auxlilar from libft
char	*ft_strchr_nxl(const char *s, int c);
char	*ft_strdup_nxl(const char *s);
size_t	ft_strlen_nxl(const char *s);
char	*ft_substr_nxl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_nxl(char const *s1, char const *s2);

#endif
