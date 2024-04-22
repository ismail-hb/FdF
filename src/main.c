/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:37 by ismail            #+#    #+#             */
/*   Updated: 2024/04/23 00:01:07 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	cleanup_and_exit(int status, t_data *d)
{
	if (d->mlx)
		free(d->mlx);
	if (d->win)
		free(d->win);
	exit(status);
}

int	on_win_destroy(t_data *d)
{
	cleanup_and_exit(0, d);
	return (0);
}

int	on_keydown(int keycode, t_data *d)
{
	if (keycode == 53)
		cleanup_and_exit(0, d);
	return (0);
}

void	init_data(t_data *d)
{
	d->mlx = NULL;
	d->win = NULL;
}

int	main(int ac, char **av)
{
	t_data	d;

	init_data(&d);
	(void)av;
	if (ac != 2)
		return (write(2, "Usage: ./fdf <map>\n", 19), 1);
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, 1000, 500, "fdf");
	mlx_hook(d.win, ON_KEYDOWN, 1 << 0, on_keydown, &d);
	mlx_hook(d.win, ON_DESTROY, 0, on_win_destroy, &d);

	// lire argument ../test_maps/42.fdf

	mlx_loop(d.mlx);
	return (0);
}
