/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/01 15:47:24 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/27 16:40:42 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitword(char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static int	splitcount(char const *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') && s[i] != c)
			x++;
		i++;
	}
	return (x);
}

static char	**err_free_all(char **y_ax, int y)
{
	while (y > 0)
	{
		if (y_ax[y])
			free(y_ax[y]);
		y--;
	}
	free (y_ax);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			y;
	char		**y_ax;

	i = 0;
	y = 0;
	y_ax = (char **)malloc((splitcount(s, c) + 1) * sizeof(char *));
	if (!y_ax)
		return (NULL);
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
		{
			y_ax[y] = ft_substr(s, i, splitword(s, c, i));
			if (!y_ax[y])
				return (err_free_all(y_ax, y));
			y++;
		}
		i++;
	}
	y_ax[y] = NULL;
	return (y_ax);
}
