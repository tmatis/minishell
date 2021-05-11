/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:12:28 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/11 22:45:24 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H

# define EXEC_H

#include "../minishell.h"

int	exec_pipes(t_list *pipes_list, t_list **env_vars);
int	exec(t_list *pipes_list, t_list **env_var);

#endif
