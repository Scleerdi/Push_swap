/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:42 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/03 14:41:01 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_list(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack)
		return ;
	while (current != NULL)
	{
		ft_putnbr_fd(current->data, 1);
		ft_putchar_fd('\n', 1);
		current = current->next;
	}
	ft_putchar_fd('\n', 1);
}

/*
** Print stacks for debug purposes
*/

void	printstacks(t_stacks *ab)
{
	ft_putstr_fd("\nstack A:\n", 1);
	print_list(ab->a);
	ft_putstr_fd("\nstack B:\n", 1);
	print_list(ab->b);
}
