/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:55 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/06 16:31:28 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
** Picks an algorithim based on alg or disorder
*/

int	push_swap(t_stacks *ab, int alg, double d)
{
	benchmark(ab, alg, d);
	normalize(ab->a);
	if (alg == 1 || d <= 0.2)
	{
		ab->bench->path = 1;
		sort_simple(ab);
	}
	else if (alg == 2 || (d > 0.2 && d <= 0.5))
	{
		ab->bench->path = 2;
		chunk_sort(ab);
	}
	else if (alg == 3 || d > 0.5)
	{
		ab->bench->path = 3;
		//radix_sort(ab);
	}
	print_b(ab);
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
	int			alg;
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	i = argc - 1;
	ab.size_a = argc - 1;
	alg = 0;
	while (i > 0)
	{
		if (alg == 0 && alg_check(&ab, argv[i]) != 0)
		{
			alg = alg_check(&ab, argv[i]);
			i--;
		}
		if (alg == 0 && (arg_check(ab.a, argv[i]) || loop(&ab, argv[i])))
			return (error_delete_all(&ab));
		i--;
	}
	if (ab.size_a != 0 && sorted(&ab) == 0)
		push_swap(&ab, alg, compute_disorder(&ab));
	del_stacks(&ab);
	return (0);
}
