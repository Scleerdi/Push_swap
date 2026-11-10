/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normalize.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 12:35:11 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/09 16:04:59 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steve(t_stack *a)
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
