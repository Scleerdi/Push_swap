/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:38 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 10:35:40 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	swaps the firt two nodes of a stack
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
**	swaps the firt two nodes of both stacks A & B
** Updates the op counters
*/

void	ss(t_stacks *ab)
{
	ab->bench->ops[0]--;
	ab->bench->ops[1]--;
	ab->bench->ops[2]++;
	swap_a(ab);
	swap_b(ab);
}
/*
** swaps the firt two nodes of both stacks A 
** Updates the op counters
*/
void	swap_a(t_stacks *ab)
{
	ab->bench->ops[0]++;
	swap_stack(&ab->a);
}
/*
** swaps the firt two nodes of both stacks B
** Updates the op counters
*/
void	swap_b(t_stacks *ab)
{
	ab->bench->ops[1]++;
	swap_stack(&ab->b);
}
