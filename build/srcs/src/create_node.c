/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_node.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/11/16 10:33:18 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/11/16 12:16:41 by gshabait      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	Creates linked list node and assigns it Data
**	sets next to NULL
*/

t_stack	*create_node(int data)
{
	t_stack	*node;

	node = ft_calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
