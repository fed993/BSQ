/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:19:23 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 22:58:13 by fpolyans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_FILE_H
#define MY_FILE_H

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	assign_valid_chars(int *i, int *j);
void	build_pregird(int *i, int *j, char **map);
void	count_lns_cls(int *i);
void	alorithm(int *min, int *i);
void	overwrite_grids(int *max, int **pos, char **map);

char	g_vbf[3];
int		*g_line_num;
char	*g_pregrid;
int		*g_grid;
int		g_lns;
int		g_cls;


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#endif
