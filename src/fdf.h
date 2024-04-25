/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:42 by ismail            #+#    #+#             */
/*   Updated: 2024/04/25 02:54:47 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <math.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TODO TEMP

# define ON_KEYDOWN	2
# define ON_DESTROY	17

# define WIN_W 1920
# define WIN_H 1080

typedef struct s_v2
{
	int	x;
	int	y;
}	t_v2;

typedef struct s_v3
{
	int	x;
	int	y;
	int	z;
}	t_v3;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	d_img;
	ssize_t	**points;
}	t_data;

void	ft_free(char *str);
void	free_2d(char **arr);
void	init_data(t_data *d);
void	print_2d(char **arr);
void	render(ssize_t **points, t_data *d);
void	draw_pixel(int x, int y, t_img *d_img);
void	cleanup_and_exit(int status, t_data *d);
void	draw_line(t_v2 p1, t_v2 p2, t_img *d_img);
void	draw_line_3d(t_v3 p1, t_v3 p2, t_img *d_img, t_v2 map_size);
int		on_win_destroy(t_data *d);
int		ft_count_line(char *file);
int		ft_count_split(char **line_len);
int		on_keydown(int keycode, t_data *d);
int		lerp(int from, int to, double alpha);
double	get_dist(t_v2 p1, t_v2 p2);
ssize_t	**parse(char *file);
t_v2	get_map_size(ssize_t **points);
t_v2	lerp_v2(t_v2 p1, t_v2 p2, double alpha);

#endif
