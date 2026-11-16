/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_delete_all.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:33:38 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:05:35 by sicleerd      ########   odam.nl         */
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
