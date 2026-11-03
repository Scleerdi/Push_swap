/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 16:05:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/02 18:23:34 by gshabait      ########   odam.nl         */
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

int	find_min_position(t_stack *stack)
{
	int min;
	int position;
	int i;
	
	if (!stack)
		return (-1); //not index?
	position	= 0;
	i			= 0;
	min			= stack->data;
	while (stack != NULL)
	{
		if (stack->data < min)
		{
			min = stack->data;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}

void	move_min_to_top(t_stack *stack)
{
	int p;
	
	p = find_min_position()
}