/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/28 16:49:44 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/12 11:45:32 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int x)
{
	return (x >= 'A' && x <= 'Z');
}

static int	ft_islower(int x)
{
	return (x >= 'a' && x <= 'z');
}

int	ft_isalpha(int x)
{
	return (ft_islower(x) || ft_isupper(x));
}
