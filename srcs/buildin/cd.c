/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:07:44 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/06 12:06:10 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_cd(int argc, char **argv, t_list **env_var)
{
	char	actual_dir[BUFFER_SIZE];

	(void)env_var;
	(void)argv;
	(void)argc;


	getcwd(actual_dir, sizeof(actual_dir));
	return (0);
}