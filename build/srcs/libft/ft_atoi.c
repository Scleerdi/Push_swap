/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:11:56 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/13 11:34:34 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == 32);
}

int	ft_atoi(const char *str)
{
	int		s;
	long	r;
	int		i;

	i = 0;
	s = 1;
	r = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return ((int)r * s);
}
