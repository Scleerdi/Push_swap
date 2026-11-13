/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_stack.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:01 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:40:33 by gshabait      ########   odam.nl         */
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
** Reverse rotate both stacks A and B
** Updates the op counters
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
** Increament the ra counter
*/
void	reverse_rotate_a(t_stacks *ab)
{
	ab->bench->ops[7]++;
	reverse_rotate_stack(&ab->a, ab->size_a);
}
/*
**	Moves the bottom node of B to the top
** Increament the rb counter
*/
void	reverse_rotate_b(t_stacks *ab)
{
	ab->bench->ops[8]++;
	reverse_rotate_stack(&ab->b, ab->size_b);
}
