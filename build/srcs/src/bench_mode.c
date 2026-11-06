/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_mode.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/05 12:35:31 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/06 16:25:01 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_strat(int alg, int path, int fd)
{
	ft_putstr_fd("[bench] strategy: ", fd);
	if (alg == 1)
		ft_putendl_fd("simple / O(n^2)", fd);
	if (alg == 2)
		ft_putendl_fd("medium / O(n√n)", fd);
	if (alg == 3)
		ft_putendl_fd("complex / O(n log n)", fd);
	if (alg == 0)
	{
		ft_putstr_fd("adaptive / ", fd);
		if (path == 1)
			ft_putendl_fd("O(n^2)", fd);
		if (path == 2)
			ft_putendl_fd("O(n√n)", fd);
		if (path == 3)
			ft_putendl_fd("O(nlogn)", fd);
	}
}

void	print_percent(double disorder, int fd)
{
	int	scaled;

	scaled = (int)(disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 1);
	ft_putnbr_fd(scaled / 100, fd);
	ft_putchar_fd('.', fd);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(scaled % 100, fd);
	ft_putendl_fd("%", fd);
}

void	print_ops(int *ops, int fd)
{
	int total_ops;
}

void	print_b(t_stacks *ab)
{
	print_percent(ab->bench->d, ab->bench->fd);
	print_strat(ab->bench->alg, ab->bench->path ,ab->bench->fd);
	print_ops(ab->bench->ops, ab->bench->fd);
}

void	benchmark(t_stacks *ab, int alg, double d)
{
	t_bench	*bench;

	bench = ft_calloc(1, sizeof(t_bench));
	bench->d = d;
	bench->alg = alg;
	ab->bench = bench;
}
