/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/29 14:08:18 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/06 17:59:15 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen((char *)src));
	j = ft_strnlen(dst, size);
	if (j == size)
		return (size + ft_strlen((char *)src));
	i = 0;
	while (src[i] != '\0' && (j + i + 1) < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (size > j)
		dst[i + j] = '\0';
	return (j + ft_strlen((char *)src));
}
