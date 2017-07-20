/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:04:56 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 20:24:33 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void bsq(char *map)
{
	int *line_num;
	char vbf[3];
	int i;
	int j;

	i = 0;
	while (map[i] != '\n')
		i++;
	j = i - 3;
	while (j < i)
	{
		vbf[j - i + 3] = map[j];
		j++;
	}
//	printf("%s", vbf);
	char *grid;
	grid = malloc((sizeof(char))*(sizeof(map)-i));
	while (map[i] != '\0')
		i++;
	i = i - j;
	int k;
	k = 0;
	//printf("%c",map[j]);
	while (k < i)
	{
		j++;
		grid[k] = map[j];
		k++;
	}
	printf("%s\n", grid);
	
	// new parts
	// counting lines and cols
	int line;
	int col;

	i = 0;
	while (grid[i++])
		if (grid[i] == '\n')
			line++;
	i = 0;
	while (grid[i++] != '\n')
		col++;
	// CHANGE EMPTY AND BOMBS TO 1 & 0
	
	char min = 0;
	i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == vbf[0])
			grid[i] = '1';
		else if (grid[i] == vbf[1])
			grid[i] = '0';
		i++;
	}
	printf("%s\n", grid);												// TRANSFER GRID TO INT
	i = 0;
	while(grid[i] != '\0')
	
	{

		if (i % col+1 == 0)
			i++;
		else if (grid[i] == '\n')
			i++;
		else if (i <= col)
			i++;
		else if (i % (col + 1 ) == 0)
			i++;
		else if (grid[i] == '0')
			i++;
	//else 
	//{
	//	grid[i] = '.';
	//	i++;
	//}
		else
		{
		//	 printf("i =%d\ngrid[i] =%c\ngrid[i - 1] =%c\ngrid[i - col - 1] =%c\ngrid[i - col - 2] =%c\n", i,  grid[i], grid[i - 1], grid[i - col - 1], grid[i - col - 2]);
			min = grid[i - 1];
			if (grid[i - col - 1] <= min)
				min = grid[i - col - 1];
			if (grid[i - col - 2] <= min)
				min = grid[i - col - 2];
			grid[i] = min + 1;
			i++;
		}

	}
	printf("%s", grid);
}

