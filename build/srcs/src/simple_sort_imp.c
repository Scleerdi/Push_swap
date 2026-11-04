/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort_imp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 18:01:29 by gshabait      #+#    #+#                 */
/*   Updated: 2026/11/04 15:04:23 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	sort_three(ab);
	while (ab->size_b > 0)
		execute(ab, e_pa);
}
