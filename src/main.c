/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ishouche <ishouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:37 by ismail            #+#    #+#             */
/*   Updated: 2024/04/26 02:04:55 by ishouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	d;

	init_data(&d);
	if (ac != 2)
		return (write(2, "Usage: ./fdf <map>\n", 19), 1);
	d.mlx = mlx_init(); // a proteger
	d.win = mlx_new_window(d.mlx, WIN_W, WIN_H, "fdf"); // a proteger
	d.d_img.img = mlx_new_image(d.mlx, WIN_W, WIN_H); // a proteger
	d.d_img.addr = mlx_get_data_addr(d.d_img.img, &d.d_img.bits_per_pixel,
			&d.d_img.line_length, &d.d_img.endian);
	mlx_hook(d.win, ON_KEYDOWN, 1 << 0, on_keydown, &d);
	mlx_hook(d.win, ON_DESTROY, 0, on_win_destroy, &d);
	d.points = parse(av[1]);
	if (!d.points)
	{
		write(2, "Invalid map\n", 12);
		cleanup_and_exit(1, &d);
	}
	render(d.points, &d);
	mlx_loop(d.mlx);
	return (0);
}
