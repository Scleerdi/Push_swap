/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: scleerdi <scleerdi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/06 16:31:25 by scleerdi      #+#    #+#                 */
/*   Updated: 2026/11/03 17:57:06 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Converts the written commands to executable commands
**	Executes those commands on the stacks
*/

int	convert_to_command(t_stacks *ab, char *line)
{
	if (!ft_strncmp(line, "sa", 4))
		execute_c(ab, e_sa);
	else if (!ft_strncmp(line, "sb", 4))
		execute_c(ab, e_sb);
	else if (!ft_strncmp(line, "ra", 4))
		execute_c(ab, e_ra);
	else if (!ft_strncmp(line, "rb", 4))
		execute_c(ab, e_rb);
	else if (!ft_strncmp(line, "rra", 4))
		execute_c(ab, e_rra);
	else if (!ft_strncmp(line, "rrb", 4))
		execute_c(ab, e_rrb);
	else if (!ft_strncmp(line, "pa", 4))
		execute_c(ab, e_pa);
	else if (!ft_strncmp(line, "pb", 4))
		execute_c(ab, e_pb);
	else if (!ft_strncmp(line, "ss", 4))
		execute_c(ab, e_ss);
	else if (!ft_strncmp(line, "rr", 4))
		execute_c(ab, e_rr);
	else if (!ft_strncmp(line, "rrr", 4))
		execute_c(ab, e_rrr);
	else
		return (0);
	return (1);
}

/*
**	Calls convert_to_command and reads the input supplied by the user
**	Returns -1 on an invalid instruction, else 1 if sorted and 0 if not
*/

int	checker(t_stacks *ab)
{
	char	*line;

	line = read_line(0);
	while (line)
	{
		if (convert_to_command(ab, line) == 0)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = read_line(0);
	}
	return (sorted(ab));
}

/*
**	Assists the Main
**	Errors if appropriate
*/

static	int	loop(t_stacks *ab, char *str)
{
	t_stack		*current;

	if (arg_check(ab->a, str))
		return (error_delete_all(ab));
	current = create_node(ft_atoi(str));
	if (!current)
		return (error_delete_all(ab));
	if (ab->a == NULL)
		ab->a = current;
	else
	{
		current->next = ab->a;
		ab->a = current;
	}
	return (0);
}

/*
**	Calls checker
**	Checks the conditions of the stacks after checker has returned
*/

int	declare(t_stacks *ab)
{
	int	ret;
	
	if (ab->size_a == 0)
   		return (0);
	ret = checker(ab);
	if (ret == -1)
		return (error_delete_all(ab));
	if (ret == 0)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	return (0);
}

/*
**	Initiates the struct that holds stacks A and B
**	Checks for duplicate input and non numerical imput
**	Calls Declare
*/

int	main(int argc, char **argv)
{
	int			i;
	int			ret;
	t_stacks	ab;

	ft_bzero(&ab, sizeof(t_stacks));
	i = argc - 1;
	ab.size_a = argc - 1;
	while (i > 0)
	{
		if (loop(&ab, argv[i]) == 1)
		{
			del_stacks(&ab.a, &ab.b);
			return (1);
		}
		i--;
	}
	printstacks(&ab);
	ret = declare(&ab);
	del_stacks(&ab.a, &ab.b);
	return (ret);
}
