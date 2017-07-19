/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 19:33:50 by laube             #+#    #+#             */
/*   Updated: 2017/07/18 19:34:24 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (0);
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

char	**matrix(char **buff)
{
	int i;
	int k;
	int p;
	char matr[256][256];

	i = 0;
	k = 0;
	p = 0;

	while (*buff[i] != '\0')
	{
		while (*buff[i] != '\n')
		{
			matr[p][k] = *buff[i];
			k++;
			i++;
		}
		p++;
		i++;
		k = 0;
	}
	printf("%s", matr[1]);
	return (matr);
}

int main(int ac, char **av)
{
	int fd;
	int ret;
	char buf[1];
	int i;
	i = 1;
	int count;
	char *buf2;

	ret = 0;
	count = 0;
	while (i < ac)
	{
		fd = open(av[i], O_RDWR);
		i++;
		while((ret = read(fd, buf, 1)))
		{
			count++;
		}
		char buf2[count + 1];
		close(fd);
		fd = open(av[i - 1], O_RDWR);
		ret = read(fd, buf2, count);
		printf("%s", buf2);
		close(fd);
	}
	matrix(&buf2);
	return (0);
}


