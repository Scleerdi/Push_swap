/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/09/30 13:53:39 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/06 15:14:08 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
	{
		c = ((n % 10) + 48);
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(c, fd);
	}
	else
	{
		c = n + 48;
		ft_putchar_fd(c, fd);
	}
}
