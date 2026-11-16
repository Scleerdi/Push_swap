/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:35:15 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:11:49 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Checks if B is empty and A is sorted
**	Returns 1 if both conditions are true, otherwise 0 
*/

int	sorted(t_stacks *ab)
{
	if (ab->b != NULL || stack_sorted(&ab->a) == 0)
		return (0);
	return (1);
}
