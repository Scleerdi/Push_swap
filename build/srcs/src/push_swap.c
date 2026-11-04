/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:55 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/04 13:54:25 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	gets fed the arguments from the main
**	converts the arguments into stack A data nodes
*/

static int	loop(t_stacks *ab, char *str)
{
	t_stack		*current;

	current = create_node(ft_atoi(str));
	if (!current)
		return (1);
	current->next = ab->a;
	ab->a = current;
	return (0);
}

/*
** Picks an algorithim based on stack A size
*/

int	push_swap(t_stacks *ab)
{
	//normalize(ab->a);
	sort_simple(ab);
	printstacks(ab);
	return (0);
}

/*
** initiates the struckt that holds stacks A and B
** checks for duplicate input and non numerical imput
*/

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	i = argc - 1;
	ab.size_a = argc - 1;
	while (i > 0)
	{
		if (arg_check(ab.a, argv[i]) || loop(&ab, argv[i]))
			return (error_delete_all(&ab));
		i--;
	}
	if (ab.size_a != 0 && sorted(&ab) == 0)
	{
		compute_disorder(&ab);
		push_swap(&ab);
	}
	del_stacks(&ab.a, &ab.b);
	return (0);
}
