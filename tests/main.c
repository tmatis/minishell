/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 19:48:57 by tmatis            #+#    #+#             */
/*   Updated: 2021/03/25 20:24:10 by tmatis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int		log_level = 1;
	t_tests	tests;

	if (argc > 1)
		log_level = ft_atoi(argv[1]);
	else
		printf("No log level specified, set to 1\n");
	tests = init_tester("Minishell tester", log_level);
	tests_header(&tests);
	tests_result(&tests);
	return (0);
}
