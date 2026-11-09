/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 16:05:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/09 12:16:53 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	1. finding the min value
	2. finding it's position in the linked list
	3. Rotating the min to the top using ra or rra
	4. pushing the min to stack B
*/

int	find_min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->data;
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
	int	min;
	int	position;
	int	i;

	if (!stack)
		return (-1);
	position = 0;
	i = 0;
	min = stack->data;
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

void	move_min_to_top(t_stacks *ab)
{
	int	p;
	int	min;

	if (!ab || !ab->a)
		return ;
	min = find_min(ab->a);
	p = find_min_position(ab->a);
	while (ab->a->data != min)
	{
		if (p <= ab->size_a / 2)
			execute(ab, e_ra);
		else
			execute(ab, e_rra);
	}
}

void	push_min_to_b(t_stacks *ab)
{
	while (ab->size_a > 3)
	{
		move_min_to_top(ab);
		execute(ab, e_pb);
	}
}
