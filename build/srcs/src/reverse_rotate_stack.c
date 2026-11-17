/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_stack.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:02 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/17 15:34:14 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Moves the bottom node to the top
*/

static	void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*current;

	current = *stack;
	previous = NULL;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
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
	ab->bench->ops[e_rra]--;
	ab->bench->ops[e_rrb]--;
	ab->bench->ops[e_rrr]++;
	reverse_rotate_a(ab);
	reverse_rotate_b(ab);
}

/*
**	Moves the bottom node of A to the top
**	Increments the rra counter.
*/

void	reverse_rotate_a(t_stacks *ab)
{
	ab->bench->ops[e_rra]++;
	reverse_rotate_stack(&ab->a);
}

/*
**	Moves the bottom node of B to the top
**	Increment the rb counter
*/

void	reverse_rotate_b(t_stacks *ab)
{
	ab->bench->ops[e_rrb]++;
	reverse_rotate_stack(&ab->b);
}
