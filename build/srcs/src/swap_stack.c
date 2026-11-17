/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:38 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/17 11:48:15 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swaps the first two nodes of a stack
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

/*
**	Swaps the first two nodes of both stacks A & B
**	Updates the op counters
*/

void	ss(t_stacks *ab)
{
	ab->bench->ops[e_sa]--;
	ab->bench->ops[e_sb]--;
	ab->bench->ops[e_ss]++;
	swap_a(ab);
	swap_b(ab);
}

/*
**	Swaps the first two nodes of both stacks A
**	Updates the op counters
*/

void	swap_a(t_stacks *ab)
{
	ab->bench->ops[e_sa]++;
	swap_stack(&ab->a);
}

/*
**	Swaps the first two nodes of both stacks B
**	Updates the op counters
*/

void	swap_b(t_stacks *ab)
{
	ab->bench->ops[e_sb]++;
	swap_stack(&ab->b);
}
