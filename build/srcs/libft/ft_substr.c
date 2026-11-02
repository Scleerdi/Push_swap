/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 14:57:10 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/07 17:49:28 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_str;
	size_t			si;
	size_t			i;

	if (!s)
		return (NULL);
	si = ft_strlen(s);
	if (start >= si)
		return (ft_strdup(""));
	if (len > si - start)
		len = si - start;
	s_str = malloc(len + 1);
	if (!s_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s_str[i] = s[start + i];
		i++;
	}
	s_str[i] = '\0';
	return (s_str);
}
