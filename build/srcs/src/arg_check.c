/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:58:40 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/05 17:20:55 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*
**	Looks for duplicate input
*/

int	value_exists(t_stack *a, int data)
{
	if (a == NULL)
		return (0);
	if (a->data == data)
		return (1);
	return (value_exists(a->next, data));
}

/*
**	Checks that str is a whole number that fits in an int:
**	optional sign, at least one digit, nothing but digits after that
*/

static int	is_int(char *str)
{
	long	nbr;
	int		neg;
	int		i;

	i = 0;
	neg = (str[i] == '-');
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	nbr = 0;
	while (ft_isdigit(str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr - neg > INT_MAX)
			return (0);
		i++;
	}
	return (str[i] == '\0');
}

/*
**	Returns 1 if str is not a valid int or is a duplicate, else 0
*/

int	alg_check(t_stacks *ab, char *str)
{
	if (!ft_strncmp(str, "--simple", ft_strlen(str)))
		return (1);
	else if (!ft_strncmp(str, "--medium", ft_strlen(str)))
		return (2);
	else if (!ft_strncmp(str, "--complex", ft_strlen(str)))
		return (3);
	else if (!ft_strncmp(str, "--bench", ft_strlen(str)))
	{
		ab->bench->fd = 1;
		return (4);
	}
	return (0);
}

int	arg_check(t_stack *a, char *str)
{
	if (is_int(str) && value_exists(a, ft_atoi(str)) == 0)
		return (0);
	return (1);
}
