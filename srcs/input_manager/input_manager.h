/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:17:36 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/11 12:28:52 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_MANAGER_H

# define INPUT_MANAGER_H

# include "../minishell.h"

void			buffer_add(char c, t_buffer *buffer);
void			buffer_add_chain(char *src, int size, t_buffer *buffer);
void			buffer_delete(int pos, t_buffer *buffer);
t_buffer		init_buffer(t_bool manage_history, char *status);
void			push_history(char *command, t_list **history);
char			*fetch_history(int i, t_list *history);
struct termios	raw_mode(void);
void			buff_mode(struct termios old);
void			erase_x_chars(int x);
int				get_escape_id(char *buff, int size);
void			display_escape_code(char *buff, int size);
int				get_input_line(char **line, t_bool manage_history,
					t_list **history, char *status);
void			erase_char(t_buffer *buffer);
void			handle_down_key(t_buffer *buffer, int *history_fetch,
					char **temp, t_list *history);
void			handle_up_key(t_buffer *buffer, int *history_fetch,
					char **temp, t_list *history);
void			handle_ctrlc(t_buffer *buffer);
void			handle_ctrld(t_buffer *buffer);
void			handle_left_key(t_buffer *buffer);
void			handle_right_key(t_buffer *buffer);
void			print_prompt(char *status);
void			handle_ctrl_l(t_buffer *buffer);

#endif
