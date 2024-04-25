/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 02:24:09 by ishouche          #+#    #+#             */
/*   Updated: 2024/04/25 03:04:24 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v2	get_map_size(ssize_t **points)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (points[y])
		y++;
	while (points[0][x] != INT_MAX)
		x++;
	return ((t_v2){x, y});
}

int	lerp(int from, int to, double alpha)
{
	return (from + (to - from) * alpha);
}

t_v2	lerp_v2(t_v2 p1, t_v2 p2, double alpha)
{
	t_v2	v;

	v.x = lerp(p1.x, p2.x, alpha);
	v.y = lerp(p1.y, p2.y, alpha);
	return (v);
}

double	get_dist(t_v2 p1, t_v2 p2)
{
	return (sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)));
}
