/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort_imp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 18:01:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/11 12:53:16 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
	5. Sorting the remaining three integers
	6. Pushing everything back to stack A
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

void	sort_simple(t_stacks *ab)
{
	while (ab->size_a > 3)
	{
		move_min_to_top(ab);
		execute(ab, e_pb);
	}
	//ft_printf("Size A: %d\n", ab->size_a);
	//ft_printf("Size B: %d\n", ab->size_b);
	//printstacks(ab);
	sort_three(ab);
	while (ab->size_b > 0)
		execute(ab, e_pa);
}
