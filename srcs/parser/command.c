/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:28:01 by tmatis            #+#    #+#             */
/*   Updated: 2021/04/28 16:54:51 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Init the command structure
*/

static t_command	*init_command(void)
{
	t_command	*command;

	command = calloc(1, sizeof(t_command));
	if (!command)
		return (NULL);
	return (command);
}

/*
** Parse a potential redirection, iter on word_list
*/

static t_redir	*get_redir(t_list **word_list)
{
	t_redir		*redir;
	int			special_id;

	redir = ft_calloc(1, sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->type = escape_control((*word_list)->content);
	*word_list = (*word_list)->next;
	if (*word_list)
	{
		special_id = escape_control((*word_list)->content);
		if (special_id != 5 && special_id != 3)
		{
			redir->file = ft_strdup((*word_list)->content);
			*word_list = (*word_list)->next;
		}
	}
	else
		redir->file = NULL;
	return (redir);
}

/*
** Set the command in the struct
*/

static void	set_command(t_list	**word_list, t_command *command)
{
	command->cmd = ft_strdup((*word_list)->content);
	*word_list = (*word_list)->next;
}

/*
** Retourne l'argument et passe au suivant
*/

static char	*get_arg(t_list **word_list)
{
	char	*dst;

	dst = ft_strdup((*word_list)->content);
	*word_list = (*word_list)->next;
	return (dst);
}

/*
** retourne l'objet t_command en utilisant les tokens
** jusqu'a rencontrer un token | ou ;
** le premier token a ne pas etre une redirection est considerer
** comme la commande
*/

t_command	*get_command(t_list **word_list)
{
	t_command	*command;
	t_bool		command_set;
	int			special_id;

	command = init_command();
	command_set = false;
	if (!command)
		return (NULL);
	while (*word_list)
	{
		special_id = escape_control((*word_list)->content);
		if (special_id == 5 || special_id == 3)
			break ;
		if (special_id == 1 || special_id == 2 || special_id == 4)
			ft_lstadd_back(&command->redirs, ft_lstnew(get_redir(word_list)));
		else if (!command_set)
		{
			command_set = true;
			set_command(word_list, command);
		}
		else
			ft_lstadd_back(&command->args, ft_lstnew(get_arg(word_list)));
	}
	return (command);
}
