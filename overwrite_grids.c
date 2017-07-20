/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overwrite_grids.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:46:24 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 22:58:21 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	overwrite_grids(int *max, int **pos, char **map)
{
	*pos[0] = 0;
	while (g_grid[*pos[0]] != *max)
		*pos[0]++;

	ft_putstr(*map);

	*pos[1] = 0;
	*pos[2] = 0;
	while (*pos[1] < *max)
	{
		while (*pos[2] < *max)
		{
			g_pre_grid[*pos[0] - ((g_cls + 1) * (*pos[1])) - *pos[2]] = vbf[2];
			pos[2]++;
		}
		*pos[2] = 0;
		*pos[1]++;
	}

}
