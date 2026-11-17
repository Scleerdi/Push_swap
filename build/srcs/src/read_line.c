/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/03 17:16:34 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/17 12:44:14 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Adds one char to the end of a string
**	frees the old string and returns the new one
*/

static char	*append(char *line, char c)
{
	char	buf[2];
	char	*new;

	buf[0] = c;
	buf[1] = '\0';
	new = ft_strjoin(line, buf);
	free(line);
	return (new);
}

/*
**	Reads one line from fd, without the trailing newline
**	Returns NULL at end of input (or on error)
*/

char	*read_line(int fd, int *error)
{
	char	*line;
	char	c;
	int		ret;

	*error = 0;
	line = ft_strdup("");
	if (!line)
	{
		*error = 1;
		return (NULL);
	}
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n')
	{
		line = append(line, c);
		if (!line)
		{
			*error = 1;
			return (NULL);
		}
		ret = read(fd, &c, 1);
	}
	if (ret == -1 || (ret == 0 && *line != '\0'))
		*error = 1;
	if (ret <= 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
