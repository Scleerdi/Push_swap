/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 10:48:47 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/07 13:26:50 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	r = malloc(size * nmemb);
	if (!r)
		return (NULL);
	ft_bzero(r, (size * nmemb));
	return (r);
}
