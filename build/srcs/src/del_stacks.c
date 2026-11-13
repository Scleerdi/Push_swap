/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_stacks.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:05 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:49:17 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Frees every node in the linked list
** Sets th stack pointer to NULL
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
/*
** Frees all nodes in stacks A & B
** Frees the benchmakr structure
*/
void	del_stacks(t_stacks *ab)
{
	del_stack(&ab->a);
	del_stack(&ab->b);
	free(ab->bench);
	ab->bench = NULL;
}
