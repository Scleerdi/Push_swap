/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/04 14:40:08 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/10 12:59:32 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int bits;
	int max;
	
	bits	= 0;
	max 	= size - 1;  
	while ( max > 0)
	 {
		max = max >> 1;	
		bits++;
	 }
	return (bits);	
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
	int i;
	int bit;
	int size;

	size	= max_bits(ab->size_a);
	bit		= 0;
	while(bit < 3)
	{
		i = 0;
		while(i < size)
		{
			if(((ab->a->index >> bit) & 1) == 0)
				execute(ab, e_pb);
			else
				execute(ab, e_ra);
			i++;
		}
		while (ab->size_b > 0)
			execute(ab, e_pa);
		bit++;		
	}
}
