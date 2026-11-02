/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 15:39:09 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/06 16:47:52 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static	int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) == 0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		l_len;
	size_t		i;

	i = 0;
	if (!little)
		return (NULL);
	l_len = ft_strlen((char *)little);
	if ((little[0]) == '\0')
		return ((char *)big);
	while ((i + l_len - 1) < len && big[i] != '\0')
	{
		if (ft_strnequ(&big[i], little, l_len))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
