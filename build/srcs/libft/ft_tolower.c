/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:00:28 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/12 11:58:19 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int x)
{
	return (x >= 'A' && x <= 'Z');
}

char	ft_tolower(int x)
{
	if (ft_isupper(x))
		x += 32;
	return (x);
}
