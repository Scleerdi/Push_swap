/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:26 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/05 12:16:53 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swaps the head of the stack with the item that follows
*/

static	void	swap_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	temp = NULL;
	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	current = (*stack)->next;
	if (current->data == (*stack)->data)
		return ;
	else
	{
		temp = *stack;
		(*stack)->next = current->next;
		current->next = temp;
		*stack = current;
	}
}

void	ss(t_stacks *ab)
{
	swap_a(ab);
	swap_b(ab);
}

void	swap_a(t_stacks *ab)
{
	swap_stack(&ab->a);
	ab->bench->ops[0]++;
}

void	swap_b(t_stacks *ab)
{
	swap_stack(&ab->b);
}
