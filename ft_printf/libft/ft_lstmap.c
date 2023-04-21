/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bogunlan <bogunlan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:18:21 by bogunlan          #+#    #+#             */
/*   Updated: 2022/06/12 20:17:30 by bogunlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*current;
	t_list	*head;

	if (!lst)
		return (NULL);
	current = lst;
	new = ft_lstnew(f(lst->content));
	head = new;
	while (current)
	{
		current = current->next;
		if (!current)
			break ;
		new->next = ft_lstnew(f(current->content));
		if (!new->next)
			ft_lstclear(&lst, del);
		new = new->next;
	}
	return (head);
}
