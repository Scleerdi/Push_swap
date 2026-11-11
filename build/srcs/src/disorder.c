/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 15:35:33 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/11 14:02:55 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// please dont look directly at this function, it is very shy

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
	return (d);
}
