/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/04 14:40:08 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/10 14:52:20 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculates how many binary bits we need to examine */
static int	max_bits(int size) 
{
	int bits;
	int max; //largest  normalized index
	
	bits	= 0; //counts how many binary positions are needed to represent that index
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

/* use the bits we calculated to sort the numbers in stack A */

void	radix_sort(t_stacks *ab)
{
	int i;
	int bit;
	int size;

	size	= max_bits(ab->size_a);
	bit		= 0;
	while(bit < size)
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
