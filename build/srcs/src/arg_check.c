/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_check.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 11:58:40 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/12 12:56:24 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

/*
**	recursively searches stack A for a given num (duplicates)
	return 1 if found, otherwise 0
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
 1. Checks if args is a valid alg option
 2. sets the selected alg or enable bench mode
 3. returns 1 if recognized, otherwise 0
*/

int	alg_check(t_stacks *ab, char *str)
{
	if (!ft_strncmp(str, "--simple", 9))
		ab->bench->alg = 1;
	else if (!ft_strncmp(str, "--medium", 9))
		ab->bench->alg = 2;
	else if (!ft_strncmp(str, "--complex", 10))
		ab->bench->alg = 3;
	else if (!ft_strncmp(str, "--adaptive", 11))
		ab->bench->alg = 0;
	else if (!ft_strncmp(str, "--bench", 8))
		ab->bench->on = 1;
	else
		return (0);
	return (1);
}
/*
 1. checks if args are valid int
 2. and does not already exist in stack A
 3. return 1 if valid, otherwise 0
*/
int	arg_check(t_stack *a, char *str)
{
	if (is_int(str) && value_exists(a, ft_atoi(str)) == 0)
		return (0);
	return (1);
}
