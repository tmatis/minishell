/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:44:38 by tmatis            #+#    #+#             */
/*   Updated: 2021/04/20 20:26:23 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <termios.h>

/*
** Write a beautifull header O_O
** TODO: COLOR
*/

static	void	write_header(void)
{
	ft_putnl("        _       _     _          _ _");
	ft_putnl("  /\\/\\ (_)_ __ (_)___| |__   ___| | |");
	ft_putnl(" /    \\| | '_ \\| / __| '_ \\ / _ \\ | |");
	ft_putnl("/ /\\/\\ \\ | | | | \\__ \\ | | |  __/ | |");
	ft_putnl("\\/    \\/_|_| |_|_|___/_| |_|\\___|_|_|");
	ft_putnl("");
}

void			mute_unused(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

t_list			*build_env(char **envp)
{
	t_env	*env;

	env = ft_calloc(1, sizeof(t_env));
	if (!env)
		return (NULL);
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
	return (NULL);
}

int				main(int argc, char **argv, char **envp)
{
	t_list	*history;
	char	*line;
	int		ret;

	(void)envp;
	mute_unused(argc, argv);
	history = NULL;
	write_header();
	ret = 1;
	while (1)
	{
		ft_putstr("Minishell $>");
		if (!get_input_line(&line, true, &history))
			break ;
		parse_line(line);
		if (!ft_strcmp(line, "exit"))
			break ;
		free(line);
	}
	ft_lstclear(&history, free);
	free(line);
}
