/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_mode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 12:35:31 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/06 13:59:20 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_percent(double disorder, int fd)
{
	int	scaled;

	scaled = (int)(disorder * 10000 + 0.5);
	ft_putnbr_fd(scaled / 100, fd);
	ft_putchar_fd('.', fd);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(scaled % 100, fd);
	ft_putchar_fd('%', fd);
}

void	print_b(t_stacks *ab)
{
	ft_putstr_fd("[bench] disorder:", 1);
	print_percent(ab->bench->d, 1);
}

void	benchmark(t_stacks *ab, int alg, double d)
{
	t_bench	*bench;

	bench = ft_calloc(1, sizeof(t_bench));
	bench->d = d;
	bench->alg = alg;
	ab->bench = bench;
}
