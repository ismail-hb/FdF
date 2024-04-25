/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:15:20 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/25 03:00:41 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	on_keydown(int keycode, t_data *d)
{
	if (keycode == 65307)
		cleanup_and_exit(0, d);
	return (0);
}

int	ft_count_line(char *file)
{
	char	*str;
	int		line_num;
	int		fd;

	line_num = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	str = get_next_line(fd);
	while (str)
	{
		line_num++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (line_num);
}

int	ft_count_split(char **line_len)
{
	int	y;

	y = 0;
	while (line_len[y])
		y++;
	return (y);
}

// void	print_2d(char **arr)
// {
// 	size_t	i;

// 	if (!arr)
// 		return ;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }