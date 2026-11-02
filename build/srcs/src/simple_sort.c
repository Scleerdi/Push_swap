/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 16:05:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/02 16:33:38 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int min;
	
	if (!stack)
		return;
	min	= stack->data;
	while (stack != NULL)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}