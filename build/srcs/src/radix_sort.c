/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/04 14:40:08 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/13 13:01:20 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculates how many binary bits we need to represent
   the larget normalized index (size -1) 
*/
static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	return (bits);
}
/*
** Processes one binary bit of every index in Stack A.
** Pushes 0 bits to B and rotates 1 bits in A.
** Then pushes everything from B back to A.
*/
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
/* 
** Sorts Stack A by processing each binary bit,
** starting from the least significant bit.
** Repeats until all required bits are processed. 
*/
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
