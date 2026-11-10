/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_stack.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:01 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/06 16:51:20 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Rotates the stack in reverse
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

void	rrr(t_stacks *ab)
{
	ab->bench->ops[7]--;
	ab->bench->ops[8]--;
	ab->bench->ops[9]++;
	reverse_rotate_a(ab);
	reverse_rotate_b(ab);
}

void	reverse_rotate_a(t_stacks *ab)
{
	ab->bench->ops[7]++;
	reverse_rotate_stack(&ab->a, ab->size_a);
}

void	reverse_rotate_b(t_stacks *ab)
{
	ab->bench->ops[8]++;
	reverse_rotate_stack(&ab->b, ab->size_b);
}
