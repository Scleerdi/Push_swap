/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_delete_all.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 17:53:19 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/11 12:04:19 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Frees allocated memory and prints error in case of invalid input
*/

int	error_delete_all(t_stacks *ab)
{
	del_stacks(ab);
	ft_putendl_fd("Error", 2);
	return (1);
}
