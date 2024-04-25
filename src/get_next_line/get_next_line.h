/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:06:30 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/23 02:23:09 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*return_line(char *saved_buffer, char *buffer, char **final, ssize_t i);
void	ft_strcpy(char *src, char *dest, ssize_t i);
void	ft_bzeroo(char *str, ssize_t size);
char	*ft_realoc(char *str, ssize_t j);
char	*ft_callocc(size_t size);
char	*get_next_line(int fd);
char	*ft_strcpy_memmove(char *src, char *dest, ssize_t i);
ssize_t	check_buff(char *buffer);
ssize_t	ft_read(int fd, char **buffer, char *saved_buffer);
ssize_t	ft_strlenn(char *str);

#endif
