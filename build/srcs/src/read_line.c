/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/13 15:27:26 by scleerdi      #+#    #+#                 */
/*   Updated: 2022/07/20 13:38:33 by scleerdi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*read_line(int fd)
{
	char	*line;
	char	c;
	int		ret;

	line = ft_strdup("");
	if (!line)
		return (NULL);
	ret = read(fd, &c, 1);
	while (ret > 0 && c != '\n')
	{
		line = append(line, c);
		if (!line)
			return (NULL);
		ret = read(fd, &c, 1);
	}
	if (ret <= 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
