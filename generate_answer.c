/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_answer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:31:37 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 22:58:16 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	algorithm(int *min, int *i)
{
	*i = 0;
	while(*i < (g_cls + 1) * g_lns)

	{   

		if (*i % g_cls + 1 == 0)
			*i++;
		else if (g_grid[*i] == -2)
			*i++;
		else if (*i <= g_cls)
			*i++;
		else if (*i % (g_cls + 1) == 0)
			*i++;
		else if (g_grid[*i] == 0)
			*i++;
		else
		{   
			*min = g_grid[*i - 1];
			if (g_grid[*i - g_cls - 1] <= *min)
				*min = g_grid[*i - g_cls - 1];
			if (g_grid[*i - g_cls - 2] <= *min)
				*min = g_grid[*i - g_cls - 2];
			g_grid[*i] = *min + 1;
			i++;
		}
	}
}
