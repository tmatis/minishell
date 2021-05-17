/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:39:08 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/16 20:28:17 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H

# define PARSER_H

# include "../minishell.h"

int			is_special(char *str);
t_list		*tokenize(char **str, int *error, t_list *env_var,
				t_bool just_pipes);
t_list		*tokenize_all(char *str, int *error, t_list *env_var);
t_command	*get_command(t_list **word_list, t_list *env_var);
void		free_command(void *mem);
char		*special(char **str);
int			exec_line(char *str, t_list **env_var);
int			escape_control(char *str);
void		free_command_list(void *mem);
void		display_commands(t_list *commands_list);
char		*make_double_quote(char **str, int *error,
				t_list *env_var);
char		*dolar(char **str, t_list *env_var);
t_list		*dolar_tokenize(char **str, t_append *append, t_list *env_var);
char		*cat_list(t_list *to_cat);
char		*single_quote(char **str, int *error);
char		*backslash_double_quote(char **str);
char		*backslash(char **str);
char		*double_quote(char **str);
char		*make_double_quote(char **str, int *error, t_list *env_var);
char		*word(char **str);
t_list		*make_word(char **str, int *error, t_list *env_var);
void		error_detector(t_list *tokens, int *error);
void		free_table(char ***table);
#endif
