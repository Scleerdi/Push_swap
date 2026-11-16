/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:09 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:11:12 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Moves the top node to the bottom of the stack
*/

static	void	rotate_stack(t_stack **stack, int size)
{
	t_stack	*current;
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	current = *stack;
	if (current == NULL || size == 1 || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	while (i < size && current->next != NULL)
	{
		current = current->next;
		i++;
	}
	current->next = temp;
	temp->next = NULL;
}

/*
**	Rotate both stacks A and B
**	Updates the op counters
*/

void	rr(t_stacks *ab)
{
	ab->bench->ops[4]--;
	ab->bench->ops[5]--;
	ab->bench->ops[6]++;
	rotate_a(ab);
	rotate_b(ab);
}

/*
**	Moves the top node of A to the bottom
**	Increment the ra counter
*/

void	rotate_a(t_stacks *ab)
{
	ab->bench->ops[4]++;
	rotate_stack(&ab->a, ab->size_a);
}

/*
**	Moves the top node of B to the bottom
**	Increment the rb counter
*/

void	rotate_b(t_stacks *ab)
{
	ab->bench->ops[5]++;
	rotate_stack(&ab->b, ab->size_b);
}
