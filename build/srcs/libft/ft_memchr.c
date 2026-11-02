/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 17:39:02 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/05 17:59:21 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)s;
	while (n > 0)
	{
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
		i++;
		n--;
	}
	return (NULL);
}
