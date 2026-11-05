/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/04 14:40:08 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/04 15:04:52 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int n)
{
	// start with bits = 0
	// while the largest rank (n - 1) still has bits left when shifted right by "bits":
	//     bits goes up by one
	// return bits
}

static void	sort_bit(t_stacks *ab, int bit)
{
	// remember how many nodes A has right now (count)
	// repeat count times:
	//     look at the top of A and check this bit of its index
	//     if the bit is 0: pb it
	//     if the bit is 1: ra it
	// while B is not empty: pa
}

void	radix_sort(t_stacks *ab)
{
	// work out how many bits we need (max_bits of size_a)
	// for each bit, from 0 up to that number:
	//     sort_bit on that bit
}
