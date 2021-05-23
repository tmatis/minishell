/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:39:53 by tmatis            #+#    #+#             */
/*   Updated: 2021/05/23 13:13:04 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_bool	is_str_numeric(char *str)
{
	while (*str)
	{
		if (!ft_isnum(*str))
			return (false);
		str++;
	}
	return (true);
}

static int	exit_not_numeric(char *argv_1, int offset)
{
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(argv_1, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	return (2 + offset);
}

static int	exit_value(int argc, char **argv, t_list **env_var, int offset)
{
	int		ret;

	if (argc == 2)
		ret = ft_atoi(argv[1]);
	else
		ret = ft_atoi(search_var(*env_var, "?"));
	if (ret >= 0 && ret <= 255)
		return (ret + offset);
	else
		return (255 + offset);
}

int	ft_exit(int argc, char **argv, t_list **env_var, t_bool in_pipes)
{
	int		offset;

	if (in_pipes)
		offset = 0;
	else
		offset = 2;
	if (isatty(STDIN_FILENO))
		ft_putstr("exit\n");
	if (argc >= 2 && !is_str_numeric(argv[1]))
		return (exit_not_numeric(argv[1], offset));
	if (argc > 2)
	{
		ft_putstr_fd("Minishell: exit: too many arguments\n", 2);
		edit_var(env_var, "?", "1");
		return (1);
	}
	else
		return (exit_value(argc, argv, env_var, offset));
}
