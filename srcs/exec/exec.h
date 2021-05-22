/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:12:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/22 13:25:16 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H

# define EXEC_H

#include "../minishell.h"

int		exec_pipes(t_list *pipes_list, t_list **env_vars);
int		exec(t_list *pipes_list, t_list **env_var);
void 	execution_error_write(char *cmd, char *error);
int		redirect_fd(t_command command, int backup[2]);
void	file_error(char *file, char *error);
void 	restore_in_out(int backup[2]);
int		redir_dup_fail(char *file, int backup[2]);
void	restore_in_out(int backup[2]);
int		get_open_flags(int type);

#endif
