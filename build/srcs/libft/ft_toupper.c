/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:03:42 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/12 11:58:39 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int x)
{
	return (x >= 'a' && x <= 'z');
}

char	ft_toupper(int x)
{
	if (ft_islower(x))
		x -= 32;
	return (x);
}
