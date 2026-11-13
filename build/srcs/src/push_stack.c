/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:48 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:15:31 by gshabait      ########   odam.nl         */
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
**move the top node from stack B to stack A
**Increament the pa op counter
*/
void	push_a(t_stacks *ab)
{
	ab->bench->ops[10]++;
	push_stack(&ab->a, &ab->b);
}
/*
**move the top node from stack A to stack B
**Increament the pb op counter
*/
void	push_b(t_stacks *ab)
{
	ab->bench->ops[11]++;
	push_stack(&ab->b, &ab->a);
}
