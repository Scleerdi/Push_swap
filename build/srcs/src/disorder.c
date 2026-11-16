/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disorder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 15:35:33 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/12 14:45:23 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
calculate how unsorted stack A is by counting pairs 
of numbers that are in the wront order
returns a disorder value between 0 (sorted) and 1 (reversed)
*/
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
