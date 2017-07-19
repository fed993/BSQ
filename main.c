/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:04:56 by laube             #+#    #+#             */
/*   Updated: 2017/07/18 21:19:54 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

char	ft_putchar(char c)
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


typedef	s_definer	t_definer;

struct s_definer 
{
	int line;
	char vide;
	char bomb;
	char plein;
}

void bsq(char *map)
{
	int i;
	t_definer line_one;

	i = 0;
	while (map[i] != '\n')
		i++;
	line_one->plein = map[i];
	line_one->bomb = map[i - 1];
	line_one->vide = map[i - 2];
	while (i >= 0)
		line_one->line = map[i - 3]
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
		{
			count++;
			write (1, &buf, 1);
		}
		close(fd);
		fd = open(av[i - 1], O_RDWR);
		char buf2[count];
		ret = read(fd, buf2, count);
		ft_putstr(buf2);
		close(fd);
	}
	return (0);
}

