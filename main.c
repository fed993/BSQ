/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:04:56 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 23:01:24 by fpolyans         ###   ########.fr       */
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
	int i;
	int j;
	int min;
	int max;
	int *pos;

	assign_valid_chars(&i, &j);
	build_pregird(&i, &j, &map);

	// new parts
	// counting lines and cols
	count_lns_cls(&i);
	// CHANGE EMPTY AND BOMBS TO 1 & 0
	parse_chars_to_nums(&min, &i);
	algorithm(&min, *i);
	find_max_num(&max, &)
	fin_max_num(&max, &i);
	pos = (int*)malloc(sizeof(int) * 3);
	overwrite_grids(&max, &pos, &map);

	ft_putstr(g_pre_grid);
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

