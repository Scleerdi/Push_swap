/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 12:20:34 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/03 14:37:24 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack *b, int index)
{
	int i;
	
	i = 0;
	while (b != NULL && b->index != index)
	{
		b = b->next;
		i++;
	}
	return (i);
}

static void push_chunks(t_stacks *ab, int chunk)
{
	int pushed;

	pushed = 0;
	while (ab->a != NULL)
	{
		if (ab->a->index < pushed + chunk)
		{
			execute(ab, e_pb);
			if (ab->b->index < pushed)
				execute(ab, e_rb);
			pushed++;
		}
		else
			execute(ab, e_ra);
	}
}

static void pull_back(t_stacks *ab)
{
	int pos;

	while (ab->b != NULL)
	{
		pos = get_position(ab->b, ab->size_b - 1);
		if (pos <= ab->size_b / 2)
		{
			while (pos > 0)
			{
				execute(ab, e_rb);
				pos--;
			}
		}
		else
		{
			while (pos < ab->size_b)
			{
				execute(ab, e_rrb);
				pos++;
			}
		}
		execute(ab, e_pa);
	}
}

void	chunk_sort(t_stacks *ab)
{
	push_chunks(ab, 2 * ft_sqrt(ab->size_a));
	pull_back(ab);
}
