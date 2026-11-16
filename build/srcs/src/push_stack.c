/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:34:16 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:17:20 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	pushes list item from head of src to head of dst
*/

void	push_stack(t_stack **dst, t_stack **src)
{
	t_stack	*temp;

	temp = NULL;
	if ((*src) == NULL)
		return ;
	else if (*dst == NULL)
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		temp = *dst;
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = temp;
	}
}

/*
**	Move the top node from stack B to stack A
**	increment the pa op counter
*/

void	push_a(t_stacks *ab)
{
	ab->bench->ops[10]++;
	push_stack(&ab->a, &ab->b);
}

/*
**	Move the top node from stack A to stack B
**	increment the pb op counter
*/

void	push_b(t_stacks *ab)
{
	ab->bench->ops[11]++;
	push_stack(&ab->b, &ab->a);
}
