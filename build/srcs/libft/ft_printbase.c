/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printbase.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gshabait <gshabait@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/19 17:47:16 by gshabait      #+#    #+#                 */
/*   Updated: 2026/10/20 14:39:52 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_n_len(unsigned long n, unsigned long size)
{
	int	len;

	len = 1;
	while (n >= size)
	{
		n = n / size;
		len++;
	}
	return (len);
}

static	char	*ft_ntoa(unsigned long n, char *base )
{
	char			*str;
	int				len;
	unsigned long	size;

	size = ft_strlen(base);
	len = ft_n_len(n, size);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = base[n % size];
		n = n / size;
	}
	return (str);
}

int	ft_printbase(unsigned long n, char *base)
{
	char	*str;
	int		count;

	str = ft_ntoa(n, base);
	if (!str)
		return (0);
	count = ft_putstr_fd(str, 1);
	free(str);
	return (count);
}
