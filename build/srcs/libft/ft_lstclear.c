/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 15:50:48 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/06 15:21:10 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = *lst;
		if (del)
			del((*lst)->content);
		*lst = (*lst)->next;
		free (temp);
	}
	*lst = NULL;
}
