/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:13:21 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/25 03:00:18 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
}

void	free_2d(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		ft_free(arr[i]);
		i++;
	}
	free(arr);
}

void	init_data(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
}

void	cleanup_and_exit(int status, t_data *d)
{
	if (d->win)
	{
		mlx_destroy_window(d->mlx, d->win);
	}
	if (d->d_img.img)
	{
		mlx_destroy_image(d->mlx, d->d_img.img);
	}
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
	}
	free_2d((char **)d->points);
	exit(status);
}

int	on_win_destroy(t_data *d)
{
	cleanup_and_exit(0, d);
	return (0);
}
