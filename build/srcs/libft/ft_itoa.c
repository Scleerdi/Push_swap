/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 11:12:58 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/12 11:57:43 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int x)
{
	int		i;
	long	nb;

	i = 1;
	nb = x;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		l;
	long	nb;
	char	*r;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	l = ft_numlen(n);
	r = malloc((l + 1) * sizeof(char));
	if (!r)
		return (NULL);
	r[l] = '\0';
	if (nb < 0)
	{
		r[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		l--;
		r[l] = (nb % 10) + '0';
		nb /= 10;
	}
	return (r);
}
