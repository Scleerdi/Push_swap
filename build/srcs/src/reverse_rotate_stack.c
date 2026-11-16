/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_stack.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:02 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:18:00 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Moves the bottom node to the top 
*/

static	void	reverse_rotate_stack(t_stack **stack, int size)
{
	t_stack	*previous;
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	if (current == NULL || size == 1)
		return ;
	while (i < size && current->next != NULL)
	{
		previous = current;
		current = current->next;
		i++;
	}
	previous->next = NULL;
	current->next = *stack;
	*stack = current;
}

/*
**	Reverse rotate both stacks A and B
**	Updates the op counters
*/

void	rrr(t_stacks *ab)
{
	ab->bench->ops[7]--;
	ab->bench->ops[8]--;
	ab->bench->ops[9]++;
	reverse_rotate_a(ab);
	reverse_rotate_b(ab);
}

/*
**	Moves the bottom node of A to the top
**	Increment the ra counter
*/

void	reverse_rotate_a(t_stacks *ab)
{
	ab->bench->ops[7]++;
	reverse_rotate_stack(&ab->a, ab->size_a);
}

/*
**	Moves the bottom node of B to the top
**	Increment the rb counter
*/

void	reverse_rotate_b(t_stacks *ab)
{
	ab->bench->ops[8]++;
	reverse_rotate_stack(&ab->b, ab->size_b);
}
