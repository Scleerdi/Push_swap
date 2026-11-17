/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:34:56 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/17 15:27:55 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	1. converts args into int and creates a new node
**	2. adds the node to the top of stack A and updates its size
**	3. return 1 if allocation fails, otherwise 0
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
**	Picks an algorithm based on alg or disorder
*/

static int	adaptive_pick(double d)
{
	if (d < 0.2)
		return (1);
	if (d >= 0.2 && d < 0.5)
		return (2);
	return (3);
}

/*
**	1. select and run the alg based on the chosen option or disorder value
**	2. normalize the stack
**	3. print benchmark if on
*/

int	push_swap(t_stacks *ab, double d)
{
	int	alg;

	ab->bench->d = d;
	alg = ab->bench->alg;
	if (alg == 0)
		alg = adaptive_pick(d);
	ab->bench->path = alg;
	normalize(ab->a);
	if (alg == 1 && d != 0)
		sort_simple(ab);
	else if (alg == 2 && d != 0)
		chunk_sort(ab);
	else if (alg == 3 && d != 0)
		radix_sort(ab);
	if (ab->bench->on)
		print_b(ab);
	return (0);
}

/*
**	1. check & process the arguments from last to first
**	2. add valid numbers to stack A
**	3. return 1 if error; otherwise 0
*/

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

/*
**	Initialize the stacks, parse the input and check if sorting is needed.
**	Runs the selected algorithm and frees memory.
*/

int	main(int argc, char **argv)
{
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	ab.bench = ft_calloc(1, sizeof(t_bench));
	if (!ab.bench || parse_args(&ab, argc, argv))
		return (error_delete_all(&ab));
	ab.bench->fd = 2;
	if (ab.size_a != 0)
		push_swap(&ab, compute_disorder(&ab));
	del_stacks(&ab);
	return (0);
}
