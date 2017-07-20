/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chars_to_nums.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 22:20:53 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 22:58:15 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	parse_chars_to_nums(int *min, int *i)
{
	g_grid = (int*)malloc((sizeof(int))*((g_lns * g_lns) * (g_cls * g_cls)));

	*min = 0;
	while (g_pre_grid[*i] != '\0')
	{
		if (g_pre_grid[*i] == g_vbf[0])
			g_grid[*i] = 1;
		else if (g_pre_grid[*i] == g_vbf[1])
			g_grid[*i] = 0;
		else if (g_pre_grid[*i] == '\n')
			g_grid[*i] = -2;
		*i++;
	}	
}
