/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 01:47:15 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/26 02:45:34 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	**parse(char *file)
{
	ssize_t	**points;
	t_prs	*parse;

	parse = malloc(sizeof(t_prs));
	points = NULL;
	parse->fd = open(file, O_RDONLY);
	if (parse->fd == -1)
		return (NULL);
	parse->line_num = ft_count_line(file);
	if (parse->line_num <= 0)
		return (close(parse->fd), NULL);
	points = make_parse_small(points, parse);
	close(parse->fd);
	free(parse);
	return (points);
}

ssize_t	**make_parse_small(ssize_t **points, t_prs *parse)
{
	char	**str2;
	char	*str;

	parse->y = 0;
	str2 = NULL;
	points = ft_calloc(parse->line_num + 1, sizeof(ssize_t *));
	str = get_next_line(parse->fd);
	parse->first_line_len = -1;
	make_it_smaller(str, str2, parse, points);
	return (points);
}

ssize_t	**make_it_smaller(char *str, char **str2,
			t_prs *parse, ssize_t **points)
{
	while (str)
	{
		str2 = ft_split(str, ' ');
		parse->line_len = ft_count_split(str2);
		if (parse->first_line_len == -1)
			parse->first_line_len = parse->line_len;
		points[parse->y] = malloc(sizeof(ssize_t) * (parse->line_len + 1));
		if (parse->first_line_len != parse->line_len || !points[parse->y])
			return (free_2d((char **)points), free_2d(str2),
				free(str), close(parse->fd), NULL);
		parse->x = 0;
		while (str2[parse->x])
		{
			points[parse->y][parse->x] = atoi(str2[parse->x]);
			parse->x++;
		}
		points[parse->y][parse->x] = INT_MAX;
		free(str);
		str = get_next_line(parse->fd);
		parse->y++;
		free_2d(str2);
	}
	points[parse->y] = NULL;
	return (free(str), points);
}
