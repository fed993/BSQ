/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_valid_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolyans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 21:53:49 by fpolyans          #+#    #+#             */
/*   Updated: 2017/07/19 22:58:10 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void    assign_valid_chars(int *i, int *j)
{
	*i = 0;
	while (map[*i] != '\n')
		*i++;
	*j = *i - 3;
	while (*j < *i)
	{
		g_vbf[*j - *i + 3] = map[*j];
		*j++;
	}
}