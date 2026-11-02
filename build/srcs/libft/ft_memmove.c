/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 10:24:32 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/05 18:02:17 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		x;
	size_t	i;

	i = n - 1;
	x = -1;
	if (!src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	if (d < s)
	{
		i = 0;
		x = 1;
	}
	while (n > 0)
	{
		d[i] = s[i];
		i += x;
		n--;
	}
	return (dest);
}
