/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sicleerd <sicleerd@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/10/02 15:59:38 by sicleerd      #+#    #+#                 */
/*   Updated: 2026/10/07 17:44:39 by sicleerd      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*add_link(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	void	*ptr;

	ptr = f(lst->content);
	if (!ptr)
		return (NULL);
	temp = ft_lstnew(ptr);
	if (!temp)
	{
		del(ptr);
		return (NULL);
	}
	return (temp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*hold;
	t_list	*tail;
	t_list	*ret;

	if (!lst || !f || !del)
		return (NULL);
	ret = NULL;
	tail = NULL;
	while (lst)
	{
		hold = add_link(lst, f, del);
		if (!hold)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		if (!ret)
			ret = hold;
		else
			tail->next = hold;
		tail = hold;
		lst = lst->next;
	}
	return (ret);
}
