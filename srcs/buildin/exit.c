/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:39:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/07 16:04:59 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_exit(int argc, char **argv, t_list **env_var, t_bool show_exit)
{
	int		ret;
	if (argc > 2)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		return (1);
	}
	else if (argc == 2)
	{
		if (show_exit)
			ft_putstr("exit\n");
		ret = ft_atoi(argv[1]);
		if (ret >= 0 && ret <= 255)
			return (ret);
		else
			return (255);
	}
	else
	{
		if (show_exit)
			ft_putstr("exit\n");
		return (ft_atoi(search_var(*env_var, "?")));
	}
}