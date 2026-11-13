/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:26 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:43:39 by gshabait      ########   odam.nl         */
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
