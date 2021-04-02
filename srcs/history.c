/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:02:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/04/02 12:11:22 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Add a element in a chained list 
*/

void	push_history(char *command, t_list **history)
{
	t_list	*new;

	new = ft_lstnew((void *)command);
	if (!new)
	{
		ft_log_error(strerror(errno));
		return ;
	}
	ft_lstadd_front(history, new);
}

char	*fetch_history(int i, t_list *history)
{
	if (!history)
		return (NULL);
	while (history->next && i)
	{
		history = history->next;
		i--;
	}
	return (history->content);
}
