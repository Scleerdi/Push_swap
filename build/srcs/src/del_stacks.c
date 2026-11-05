/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_stacks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:05 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/05 14:31:23 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Deletes and frees stacks A and B
*/

static	void	del_stack(t_stack **astack)
{
	t_stack	*trail;

	if (!astack)
		return ;
	while (*astack)
	{
		trail = *astack;
		*astack = (*astack)->next;
		ft_bzero(trail, sizeof(t_stack));
		free(trail);
	}
}

void	del_stacks(t_stacks *ab)
{
	del_stack(&ab->a);
	del_stack(&ab->b);
	free(ab->bench);
}
