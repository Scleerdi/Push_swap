/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sorted.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:25 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:11:54 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if the stack its fed is sorted in ascending order
**	Returns 1 if sorted or empty, otherwise 0
*/

int	stack_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	if (current == NULL)
		return (1);
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
