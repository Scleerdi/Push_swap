/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 14:08:31 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/13 13:51:43 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks if B is empty and A is sorted
** Returns 1 if both conditions are true, otherwise 0 
*/

int	sorted(t_stacks *ab)
{
	if (ab->b != NULL || stack_sorted(&ab->a) == 0)
		return (0);
	return (1);
}
