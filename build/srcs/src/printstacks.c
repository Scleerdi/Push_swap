/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printstacks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:34:04 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:06:35 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
**	Prints each number in a linked list on a separate line
**	Used to diplay the contents of a stack for debugging
*/
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
**	Print stacks for debug purposes
*/

void	printstacks(t_stacks *ab)
{
	ft_putstr_fd("\nstack A:\n", 1);
	print_list(ab->a);
	ft_putstr_fd("\nstack B:\n", 1);
	print_list(ab->b);
}
