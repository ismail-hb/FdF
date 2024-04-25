/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 03:44:55 by ismail            #+#    #+#             */
/*   Updated: 2024/04/25 02:59:15 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(ssize_t **points, t_data *d)
{
	int		y;
	int		x;
	t_v2	map_size;

	y = -1;
	map_size = get_map_size(d->points);
	while (points[++y])
	{
		x = -1;
		while (points[y][++x] != INT_MAX)
		{
			if (points[y][x + 1] != INT_MAX)
				draw_line_3d(
					(t_v3){x, y, points[y][x]},
					(t_v3){x + 1, y, points[y][x + 1]},
					&d->d_img, map_size);
			if (points[y + 1] != NULL)
				draw_line_3d(
					(t_v3){x, y, points[y][x]},
					(t_v3){x, y + 1, points[y + 1][x]},
					&d->d_img, map_size);
		}
	}
	mlx_put_image_to_window(d->mlx, d->win, d->d_img.img, 0, 0);
}

void	draw_line_3d(t_v3 p1, t_v3 p2, t_img *d_img, t_v2 map_size)
{
	double	mult;

	mult = 500 / map_size.x;
	p1.x -= map_size.x / 2;
	p2.x -= map_size.x / 2;
	p1.y -= map_size.y / 2;
	p2.y -= map_size.y / 2;
	p1.x *= mult;
	p1.y *= mult;
	p1.z *= mult;
	p2.x *= mult;
	p2.y *= mult;
	p2.z *= mult;
	draw_line(
		(t_v2){
		WIN_W / 2 + p1.x - p1.y * 1.73,
		WIN_H / 2 + p1.y + p1.x * 0.82 - p1.z
	},
		(t_v2){
		WIN_W / 2 + p2.x - p2.y * 1.73,
		WIN_H / 2 + p2.y + p2.x * 0.82 - p2.z
	},
		d_img);
}

void	draw_line(t_v2 p1, t_v2 p2, t_img *d_img)
{
	double	dist;
	double	curr;
	t_v2	pixel;

	dist = get_dist(p1, p2);
	curr = 0;
	while (curr < dist)
	{
		pixel = lerp_v2(p1, p2, curr / dist);
		draw_pixel(pixel.x, pixel.y, d_img);
		curr++;
	}
}

void	draw_pixel(int x, int y, t_img *d_img)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_W || y > WIN_H)
		return ;
	dst = d_img->addr + (y * d_img->line_length)
		+ (x * d_img->bits_per_pixel / 8);
	*(unsigned int *)dst = 0xFFFFFF;
}
