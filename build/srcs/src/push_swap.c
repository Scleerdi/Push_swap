/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:26:55 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/10 17:04:44 by sicleerd      ########   odam.nl         */
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
	ab->size_a++;
	return (0);
}

/*
** Picks an algorithim based on alg or disorder
*/

static int	adaptive_pick(double d)
{
	if (d <= 0.2)
		return (1);
	if (d <= 0.5)
		return (2);
	return (3);
}

int	push_swap(t_stacks *ab, double d)
{
	int	alg;

	ab->bench->d = d;
	alg = ab->bench->alg;
	if (alg == 0)
		alg = adaptive_pick(d);
	ab->bench->path = alg;
	normalize(ab->a);
	if (alg == 1)
		sort_simple(ab);
	else if (alg == 2)
		chunk_sort(ab);
	else
		radix_sort(ab);
	if (ab->bench->on)
		print_b(ab);
	return (0);
}

static int	parse_args(t_stacks *ab, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		if (!alg_check(ab, argv[i])
			&& (arg_check(ab->a, argv[i]) || loop(ab, argv[i])))
			return (1);
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	ab.bench = ft_calloc(1, sizeof(t_bench));
	if (!ab.bench || parse_args(&ab, argc, argv))
		return (error_delete_all(&ab));
	ab.bench->fd = 2;
	if (ab.size_a != 0 && sorted(&ab) == 0)
		push_swap(&ab, compute_disorder(&ab));
	del_stacks(&ab);
	return (0);
}
