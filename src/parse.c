/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:21:14 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/25 03:03:23 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	**parse(char *file)
{
	ssize_t	**points;
	int		fd;
	int		line_num;
	int		line_len;
	char	*str;
	char	**str2;
	int		y;
	int		x;
	int		first_line_len;

	str2 = NULL;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line_num = ft_count_line(file);
	if (line_num <= 0)
		return (close(fd), NULL);
	points = ft_calloc(line_num + 1, sizeof (ssize_t*));
	str = get_next_line(fd);
	first_line_len = -1;
	while (str)
	{
		free_2d(str2);
		str2 = ft_split(str, ' ');
		line_len = ft_count_split(str2);
		if (first_line_len == -1)
			first_line_len = line_len;
		else if (first_line_len != line_len)
			return (free_2d((char **)points), free_2d(str2),
                    free(str), close(fd), NULL);
		points[y] = malloc(sizeof(ssize_t) * (line_len + 1));
		x = 0;
		while (str2[x])
		{
			points[y][x] = atoi(str2[x]);
			x++;
		}
		points[y][x] = INT_MAX;
		free(str);
		str = get_next_line(fd);
		y++;
	}
	points[y] = NULL;
	close(fd);
	free_2d(str2);
	free(str);
	return (points);
}
