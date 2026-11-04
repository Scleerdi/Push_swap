/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   chunk_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 12:20:34 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/04 14:56:03 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

	/*
	**	start counting at 0
	**	walk down the list until you find the node whose index matches
	**	count each node you walk past
	**	return the count (its position from the top)
	*/

static int	get_position(t_stack *b, int index)
{
	int	i;

	i = 0;
	while (b != NULL && b->index != index)
	{
		b = b->next;
		i++;
	}
	return (i);
}

	/* 
	**	pushed = 0
	**	while A is not empty:
	**	if the top of A has an index below (pushed + chunk):
	**	pb it
	**	if the node now on top of B has an index below pushed: rb it
	**	pushed goes up by one
	**	otherwise:
	**	ra
	*/

static void	push_chunks(t_stacks *ab, int chunk)
{
	int	pushed;

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

	/* 
	**	while B is not empty:
	**	the biggest index left in B is always (size_b - 1)
	**	find its position in B (get_position)
	**	if it is in the top half: rb until it reaches the top
	**	otherwise: rrb until it reaches the top
	**	pa it
	*/

static void	pull_back(t_stacks *ab)
{
	int	pos;

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

	/*	
	**	chunk size = 2 times the square root of size_a
	**	push_chunks with that size
	**	pull_back
	*/

void	chunk_sort(t_stacks *ab)
{
	push_chunks(ab, 2 * ft_sqrt(ab->size_a));
	pull_back(ab);
}
