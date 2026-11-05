/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_mode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 12:35:31 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/05 17:21:53 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	benchmark(t_stacks *ab, int alg, double d)
{
	t_bench	*bench;

	bench = ft_calloc(1, sizeof(t_bench));
	bench->d = d;
	bench->alg = alg;
	ab->bench = bench;
}
