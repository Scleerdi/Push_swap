/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 15:35:33 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/02 16:29:18 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// please dont look directly at this function, it is very shy

void	convert_disorder(double d)
{
	if (d == 1)
		return (ft_putendl_fd("disorder : 1.000000", 1));
	d *= 1000000;
	ft_putstr_fd("disorder : 0.", 1);
	ft_putnbr_fd((int)d, 1);
	ft_putchar_fd('\n', 1);	
	return ;
}

double	compute_disorder(t_stacks *ab)
{
	t_stack	*i;
	t_stack	*j;
	long	mistakes;
	double	d;

	if (ab->size_a < 2)
		return (0);
	mistakes = 0;
	i = ab->a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data > j->data)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	d = (double)mistakes / (ab->size_a * (ab->size_a - 1) / 2);
	convert_disorder(d);
	return (d);
}