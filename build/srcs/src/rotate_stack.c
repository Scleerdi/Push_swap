/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_stack.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:13 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:20:31 by gshabait      ########   odam.nl         */
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
** Rotate both stacks A and B
** Updates the op counters
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
** Increament the ra counter
*/
void	rotate_a(t_stacks *ab)
{
	ab->bench->ops[4]++;
	rotate_stack(&ab->a, ab->size_a);
}
/*
**	Moves the top node of B to the bottom
** Increament the rb counter
*/
void	rotate_b(t_stacks *ab)
{
	ab->bench->ops[5]++;
	rotate_stack(&ab->b, ab->size_b);
}
