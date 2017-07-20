/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jostraye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:56:22 by jostraye          #+#    #+#             */
/*   Updated: 2017/07/19 20:32:14 by jostraye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_file.h"
void bsq(char *map);

int sort_map(char *map)
{
	int map_len;
	int first_line;
	int i;
	int bolean;
	int line_len;

	map_len = 0;	
	while (map[map_len])
		map_len++;

	first_line = 0;
	while (map[first_line] != '\n' || map[first_line] == '\0')
		first_line ++;

/* condition sur la taille minimale de map */
	if (map[first_line] != '\n' || map_len <= first_line + 1)
		return (1);
	else
	{
/* condition sur les fins de ligne */	
		line_len = first_line + 1;
		while (map[line_len + first_line] != '\n')
			line_len++;
		i = line_len;
		while (map[i])
		{
			if (map[i] == '\n')
				return (0);
			i = i + line_len;
		}


/* la premiere ligne compte un nombre suivi de 3 caracteres */
	
		i = 0;
		bolean = 0;
		while (i + 3 < first_line)
		{
			if (map[i] > 57 || map[i] < 48)
				bolean = 1;
			i++;
		}
		if (first_line <= 3 || bolean == 1)
			return (1);
/* trois caracteres pareil c'est pas possible */ 
		else if (map[first_line - 1] == map[first_line - 2]
				&& map[first_line - 2] == map[first_line - 3])
			return (1);
		else
		{
/*le nombre de ligne indique doit etre le vrai*/
//			i = 0;
//			int lin_count;
//
//			lin_count = 0;
//			while (map[i])
//			{
//				if (map[i] == '\n')
//					lin_count++;
//				i++;
//			}
//			printf("%d", lin_count);
//			int line_declared;
//			char *number;
//			i = 0;
//			while (i < first_line - 3)
//			{
//				number[i] = map[i];
//				i++;
//			}
			/* last check is here */
//			line_declared = ft_atoi(number);
//printf("%d", line_declared);
//			if (line_count == line_declared)
//				return (0);
//			else
//			{
				

/* 2 caracteres dans la map cest tout */
				i = 0;
				while (map[i])
				{
					if (map[i] == map[first_line - 1] || map[i] == map[first_line - 2])
						return (0);
					i++;
				}
//			}

		}
		return (0);
	}
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
		if (sort_map(buf2) == 0)
			bsq(buf2);
		else
			printf("map error\n");
	}
	return (0);
}
