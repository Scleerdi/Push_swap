/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 12:35:11 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/11 12:40:39 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 Normalizes Stack A by assigning each number an index based on its
position in ascending order, starting from 0.
The smallest number gets index 0, the next smallest gets index 1,
and so on, up to size - 1.
The original values remain unchanged.
*/
void	normalize(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;

	i = a;
	while (i)
	{
		i->index = 0;
		j = a;
		while (j)
		{
			if (j->data < i->data)
				i->index++;
			j = j->next;
		}
		i = i->next;
	}
}
