/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:04:56 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 11:47:33 by jostraye         ###   ########.fr       */
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
	char vide_bomb_full[3];
	int i;
	int j;

	i = 0;
	while (map[i] != '\n')
		i++;
	j = i - 3;
	while (j < i)
	{
		vide_bomb_full[j - i + 3] = map[j];
		j++;
	}
//	printf("%s", vide_bomb_full);
	char *grid;
	grid = malloc((sizeof(char))*(sizeof(map)-i));
	while (map[i] != '\0')
		i++;
	i = i - j;
	int k;
	k = 0;
	printf("%c",map[j]);
	while (k < i)
	{
		j++;
		grid[k] = map[j];
		k++;
	}
//	printf("%d", j);
	printf("%s", grid);
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

