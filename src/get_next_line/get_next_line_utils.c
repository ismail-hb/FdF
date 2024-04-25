/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:14:36 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/23 02:30:59 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlenn(char *str)
{
	ssize_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	i++;
	return (i);
}

void	ft_bzeroo(char *str, ssize_t size)
{
	ssize_t	i;

	i = 0;
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
}

void	ft_strcpy(char *src, char *dest, ssize_t i)
{
	ssize_t	j;

	j = 0;
	while (src[i])
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
}

char	*ft_strcpy_memmove(char *src, char *dest, ssize_t i)
{
	ssize_t	j;

	j = 0;
	while (j < i && src[j])
	{
		if (i == 1)
		{
			dest[j] = src[j];
			j++;
			break ;
		}
		dest[j] = src[j];
		j++;
	}
	j = 0;
	while (src[i])
	{
		src[j] = src[i];
		src[i] = '\0';
		j++;
		i++;
	}
	src[j] = '\0';
	return (dest);
}

char	*return_line(char *saved_buffer, char *buffer, char **final, ssize_t i)
{
	ssize_t	n;

	n = ft_strlenn(saved_buffer) - 1;
	if (!buffer)
		return (NULL);
	if (i == -1 || i == 0)
	{
		*final = ft_callocc(ft_strlenn(buffer) + n - 1);
		if (!*final)
			return (NULL);
		ft_strcpy_memmove(saved_buffer, *final, n);
		ft_strcpy(buffer, *final + n, 0);
	}
	else if (i != -1)
	{
		*final = ft_callocc(i + n);
		if (!*final)
			return (NULL);
		ft_strcpy(saved_buffer, *final, 0);
		ft_strcpy(buffer, saved_buffer, i);
		ft_strcpy_memmove(buffer, *final + n, i);
	}
	return (*final);
}
