/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bench_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/06 16:33:53 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/11 17:41:24 by sicleerd      ########   odam.nl         */
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
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd(scaled / 100, fd);
	ft_putchar_fd('.', fd);
	if (scaled % 100 < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(scaled % 100, fd);
	ft_putendl_fd("%", fd);
}

void	total_ops(int *ops, int fd)
{
	int	total_ops;
	int	i;

	i = 11;
	total_ops = 0;
	while (i >= 0)
	{
		total_ops += ops[i];
		i--;
	}
	ft_putstr_fd("\n[bench] total_ops: ", fd);
	ft_putnbr_fd(total_ops, fd);
	ft_putchar_fd('\n', fd);
}

void	print_ops_2(int *ops, int fd)
{
	ft_putstr_fd("[bench] ra: ", fd);
	ft_putnbr_fd(ops[4], fd);
	ft_putstr_fd(" rb: ", fd);
	ft_putnbr_fd(ops[5], fd);
	ft_putstr_fd(" rr: ", fd);
	ft_putnbr_fd(ops[6], fd);
	ft_putstr_fd(" rra: ", fd);
	ft_putnbr_fd(ops[7], fd);
	ft_putstr_fd(" rrb: ", fd);
	ft_putnbr_fd(ops[8], fd);
	ft_putstr_fd(" rrr: ", fd);
	ft_putnbr_fd(ops[9], fd);
	ft_putchar_fd('\n', fd);
}

void	print_ops(int *ops, int fd)
{
	total_ops(ops, fd);
	ft_putstr_fd("[bench] sa: ", fd);
	ft_putnbr_fd(ops[0], fd);
	ft_putstr_fd(" sb: ", fd);
	ft_putnbr_fd(ops[1], fd);
	ft_putstr_fd(" ss: ", fd);
	ft_putnbr_fd(ops[2], fd);
	ft_putstr_fd(" pa: ", fd);
	ft_putnbr_fd(ops[10], fd);
	ft_putstr_fd(" pb: ", fd);
	ft_putnbr_fd(ops[11], fd);
	ft_putchar_fd('\n', fd);
	print_ops_2(ops, fd);
}
