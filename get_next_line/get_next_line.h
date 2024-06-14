/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeshko <mpeshko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:06:34 by mpeshko           #+#    #+#             */
/*   Updated: 2024/04/08 13:54:33 by mpeshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h> // malloc(), free()
# include <unistd.h> // read()
# include <stddef.h> // size_t
# include <fcntl.h>
# include "../libft/libft.h"

void	*ft_calloc_bzero(size_t count, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
char	*ft_storage_plus_buffer(char *storage, char *buff);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*read_until_newline_or_eof(int fd, char *storage);
char	*ft_extract_line(char *storage);
char	*ft_trim_until_newline(char *storage);
char	*get_next_line(int fd);

#endif
