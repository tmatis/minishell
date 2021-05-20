/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:13:21 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/21 00:35:22 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_manager.h"

void	handle_eot_error(t_buffer *buffer)
{
	if (!buffer->buff)
		return (eot_error(buffer));
	buffer->size = ft_strlen(buffer->buff);
	ft_putstr(buffer->buff);
}

void	eot_error(t_buffer *buffer)
{
	ft_log_error(strerror(errno));
	buffer->escape_id = EOT_ID;
	buffer->size = 0;
}

/*
** This is called when user type ctrl-c
*/

void	handle_ctrl_c(t_buffer *buffer)
{
	char	*dst;

	dst = calloc(1, sizeof(char));
	if (!dst)
		return (eot_error(buffer));
	free(buffer->buff);
	buffer->buff = dst;
	buffer->size = 0;
	buffer->pos_before_cursor = 0;
	ft_putstr("^C\n");
	print_prompt(buffer->status);
}

/*
** This is called when user type ctrl-d
*/

int	handle_ctrl_d(t_buffer *buffer)
{
	free(buffer->buff);
	buffer->buff = NULL;
	buffer->size = 0;
	buffer->pos_before_cursor = 0;
	buffer->error = true;
	return (EOT);
}

/*
** This is called when user type delete
*/

void	erase_char(t_buffer *buffer)
{
	int		i;

	if (buffer->size <= buffer->pos_before_cursor)
		return ;
	i = 0;
	while (i++ < buffer->pos_before_cursor)
		ft_putstr(CURSOR_RIGHT);
	erase_x_chars(buffer->pos_before_cursor + 1);
	ft_putstr(buffer->buff + (buffer->size - buffer->pos_before_cursor));
	i = 0;
	while (i++ < buffer->pos_before_cursor)
		ft_putstr(CURSOR_LEFT);
	buffer_delete(buffer->size - buffer->pos_before_cursor, buffer);
}
