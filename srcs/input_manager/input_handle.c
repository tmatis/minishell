/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 12:42:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/04/08 11:07:08 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_manager.h"
#include <termios.h>

void		 handle_up_key(t_buffer *buffer, int *history_fetch, char **temp, t_list *history)
{
	erase_x_chars(buffer->size);
	if (*history_fetch == -1)
		*temp = buffer->buff;
	else
		free(buffer->buff);
	if (*history_fetch < ft_lstsize(history) - 1)
		(*history_fetch)++;
	buffer->buff = ft_strdup(fetch_history(*history_fetch, history));
	buffer->size = ft_strlen(buffer->buff);
	ft_putstr(buffer->buff);
}

void		handle_down_key(t_buffer *buffer, int *history_fetch, char **temp, t_list *history)
{
	if (*history_fetch > -1)
		(*history_fetch)--;
	erase_x_chars(buffer->size);
	free(buffer->buff);
	if (*history_fetch == -1 && temp)
	{
		buffer->buff = *temp;
		*temp = NULL;
	}
	else if (*history_fetch != -1)
		buffer->buff = ft_strdup(fetch_history(*history_fetch, history));
	buffer->size = ft_strlen(buffer->buff);
	ft_putstr(buffer->buff);
}

void		handle_left_key(t_buffer *buffer)
{
	if (buffer->position < buffer->size)
	{
		ft_putstr("\033[1D");
		buffer->position++;
	}
}

void		handle_right_key(t_buffer *buffer)
{
	if (buffer->position)
	{
		ft_putstr("\033[1C");
		buffer->position--;
	}
}

void		handle_ctrlc(t_buffer *buffer)
{
	char	*dst;

	dst = calloc(1, sizeof(char));
	if (!dst)
	{
		ft_log_error(strerror(errno));
		return ;
	}
	free(buffer->buff);
	buffer->buff = dst;
	buffer->size = 0;
	buffer->position = 0;
	ft_putstr("^C\n");
	ft_putstr("Minishell $>");
}

void		handle_ctrld(t_buffer *buffer)
{
	ft_putstr("\nexit\n");
	free(buffer->buff);
	buffer->buff = ft_strdup("");
	buffer->size = ft_strlen(buffer->buff);
	buffer->position = 0;
}

void		erase_char(t_buffer *buffer)
{
	int		i;

	i = 0;
	while (i++ < buffer->position)
		ft_putstr("\033[1C");
	erase_x_chars(buffer->position + 1);
	ft_putstr(buffer->buff + (buffer->size - buffer->position));
	i = 0;
	while (i++ < buffer->position)
		ft_putstr("\033[1D");
	buffer_delete(buffer->size - buffer->position, buffer);
}
