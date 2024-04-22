/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismail <ismail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 23:25:42 by ismail            #+#    #+#             */
/*   Updated: 2024/04/22 23:53:56 by ismail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TODO TEMP

# define ON_KEYDOWN	2
# define ON_DESTROY	17

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

#endif
