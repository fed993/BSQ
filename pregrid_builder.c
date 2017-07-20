/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pregrid_builder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:58:31 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 22:58:11 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	build_pregrid(int *i, int *j, char **map)
{
	int		k;

	g_pre_grid = (char*)malloc((sizeof(char))*(sizeof(*map) - *i));
	while (*map[*i] != '\0')
		*i++;
	*i = *i - *j;
	k = 0;
	while (k < *i)
	{
		*j++;
		g_pre_grid[k] = *map[*j];
		k++;
	}
}
