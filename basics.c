/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 19:57:44 by laube             #+#    #+#             */
/*   Updated: 2017/07/19 20:09:11 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_atoi(char *str)
{
	int		n_mark;
	int		i;
	long	rs;

	rs = 0;
	i = 0;
	n_mark = 0;
	str = trim_space(str);
	if (str[i] == '-')
	{
		n_mark = 1;
		i++;
	}
	if (str[0] == '+')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rs *= 10;
		rs += str[i] - 48;
		i++;
	}
	if (n_mark)
		rs = -rs;
	return (rs);
}
