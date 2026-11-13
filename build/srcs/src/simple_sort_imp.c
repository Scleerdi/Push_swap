/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort_imp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 18:01:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/12 15:01:38 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	**sort exactly 3 numbers in stack A
	** compares thier values and uses swaps or rotations
	** to put them in asc order
*/

void	sort_three(t_stacks *ab)
{
	int	a;
	int	b;
	int	c;

	if (!ab || !ab->a || ab->size_a != 3)
		return ;
	a = ab->a->data;
	b = ab->a->next->data;
	c = ab->a->next->next->data;
	if (a > b && b < c && a < c)
		execute(ab, e_sa);
	else if (a > b && b > c)
	{
		execute(ab, e_sa);
		execute(ab, e_rra);
	}
	else if (a > b && b < c && a > c)
		execute(ab, e_ra);
	else if (a < b && b > c && a < c)
	{
		execute(ab, e_sa);
		execute(ab, e_ra);
	}
	else if (a < b && b > c && a > c)
		execute(ab, e_rra);
}
/*
**sorts small stacks using swaps,rotations and pushes
**handles 2 numbers directly, or reduce stack A to 3 numbers
**sorts them, then pushes the remaining back from B
*/
void	sort_simple(t_stacks *ab)
{
	if (ab->size_a == 2)
	{
		if (ab->a->data > ab->a->next->data)
			execute(ab, e_sa);
		return;
	}
	while (ab->size_a > 3)
	{
		move_min_to_top(ab);
		execute(ab, e_pb);
	}
	sort_three(ab);
	while (ab->size_b > 0)
		execute(ab, e_pa);
}
