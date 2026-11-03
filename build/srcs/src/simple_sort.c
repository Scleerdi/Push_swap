/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/02 16:05:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/03 17:55:56 by gshabait      ########   odam.nl         */
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

void	move_min_to_top(t_stacks *ab)
{
	int p;
	int	min;

	if (!ab || !ab->a)
		return;
	
	min = find_min(&ab->a);
	p = find_min_position(&ab->a);
	while (ab->a->data != min)
	{
		if (p <= ab->size_a / 2)
				execute(ab, e_ra);	
		else 
				execute(ab, e_rra);
	}
	push_stack(&ab->b , &ab->a);
}

void	push_min_to_b(t_stacks *ab)
{
	while (ab->size_a > 3)
	{
		move_min_to_top(ab);
		execute(ab, e_pb);
	}
}

void	sort_three(t_stacks *ab)
{
	int a;
	int b;
	int c;

		if (!ab || !ab->a || ab->size_a != 3)
		return;
	a = ab->a->data;
	b = ab->a->next->data;
	c = ab->a->next->next->data;
	if (a > b && b < c && a < c)
		execute(ab, e_sa);
	else if (a > b && b > c)
	{
		execute(ab, e_sa);
		execute(ab, e_rra);
	}
	else if (a > b && b < c && a > c)
		execute(ab, e_ra);
	else if (a < b && b > c && a < c)
	{
		execute(ab, e_sa);
		execute(ab, e_ra);
	}
	else if (a < b && b > c && a > c)
		execute(ab, e_rra);	
}

