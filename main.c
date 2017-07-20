/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:04:56 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 18:32:09 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

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
	int *grid;
	char *pre_grid;

	pre_grid = (char*)malloc((sizeof(char))*(sizeof(map) - i));
	while (map[i] != '\0')
		i++;
	i = i - j;
	int k;
	k = 0;
	//printf("%c",map[j]);
	while (k < i)
	{
		j++;
		pre_grid[k] = map[j];
		k++;
	}
	printf("%s\n", pre_grid);
	
	// new parts
	// counting lines and cols
	int line;
	int col;

	i = 0;
	while (pre_grid[i++])
		if (pre_grid[i] == '\n')
			line++;
	i = 0;
	while (pre_grid[i++] != '\n')
		col++;
	// CHANGE EMPTY AND BOMBS TO 1 & 0
	
	grid = (int*)malloc((sizeof(int))*((line * line) * (col * col)));
	int min;

	min	= 0;
	i = 0;
	while (pre_grid[i] != '\0')
	{
		if (pre_grid[i] == vbf[0])
			grid[i] = 1;
		else if (pre_grid[i] == vbf[1])
			grid[i] = 0;
		else if (pre_grid[i] == '\n')
			grid[i] = -2;
		i++;
	}

	// TEST PRINT GRID
//	i = 0;
//	while (i < (col + 1) * line)
//	{
//		printf("%d", grid[i]);
//		i++;
//	}
	i = 0;
	while(i < (col + 1) * line)
	
	{

		if (i % col + 1 == 0)
			i++;
		else if (grid[i] == -2)
			i++;
		else if (i <= col)
			i++;
		else if (i % (col + 1) == 0)
			i++;
		else if (grid[i] == 0)
			i++;
		else
		{
			min = grid[i - 1];
			if (grid[i - col - 1] <= min)
				min = grid[i - col - 1];
			if (grid[i - col - 2] <= min)
				min = grid[i - col - 2];
			grid[i] = min + 1;
			i++;
		}
	}

	i = 0;
	while (i < (col + 1) * line)
	{
		printf("%d", grid[i]);
		i++;
	}
	// CHECK THE MAX MATRIX
	int max;
	i = 0;

	while (i < (col + 1) * line)
	{
		if (grid[i] > max && grid[i] != -2)
			max = grid[i];
		i++;
	}
	printf("\n%d", max);
}

int main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[1];
	int i;
	int count;

	i = 1;
	ret = 0;
	count = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		i++;
		while((ret = read(fd, buf, 1)))
			count++;
		close(fd);
		fd = open(av[i - 1], O_RDWR);
		char buf2[count];
		ret = read(fd, buf2, count);
//		ft_putstr(buf2);
		close(fd);
		bsq(buf2);
	}
	return (0);
}

