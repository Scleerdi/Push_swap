/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/04 14:40:08 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/10 14:52:40 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}

static void	sort_bit(t_stacks *ab, int bit)
{
	int	count;

	count = ab->size_a;
	while (count > 0)
	{
		if (((ab->a->index >> bit) & 1) == 0)
			execute(ab, e_pb);
		else
			execute(ab, e_ra);
		count--;
	}
	while (ab->b != NULL)
		execute(ab, e_pa);
}

void	radix_sort(t_stacks *ab)
{
	int	bit;
	int	size;

	size = max_bits(ab->size_a);
	bit = 0;
	while (bit < size)
	{
		sort_bit(ab, bit);
		bit++;
	}
}
