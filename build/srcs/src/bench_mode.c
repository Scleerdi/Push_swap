/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_mode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 12:35:31 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/06 18:04:28 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_b(t_stacks *ab)
{
	print_percent(ab->bench->d, ab->bench->fd);
	print_strat(ab->bench->alg, ab->bench->path ,ab->bench->fd);
	print_ops(ab->bench->ops, ab->bench->fd);
}

void	benchmark(t_stacks *ab, int alg, double d)
{
	t_bench		*bench;
	int			i;

	bench = ft_calloc(1, sizeof(t_bench));
	bench->fd = 2;
	bench->d = d;
	bench->alg = alg;
	i = 0;
	while (i < 11)
	{
		bench->ops[i] = 0;
		i++;
	}
	ab->bench = bench;
}
