# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/15 13:57:53 by tmatis            #+#    #+#              #
#    Updated: 2021/05/15 17:09:32 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This program is going to test leaks, memory error, fd leaks, and output

printf "\n###MINISHELL UNIT TEST###\n\n"

scripts_list=`ls -t parts/` # liste des scripts

mkdir -p ./outs/ # on cree le repertoire des outputs
mkdir -p ./logs/ # on cree le repertoire des logs

errors=0;

for elem in $scripts_list
do
	printf "\033[0;34mtesting: \033[0;36m$elem\n\033[m"
	bash < parts/$elem > outs/$elem\_bash.out 2> /dev/null
	valgrind --track-fds=yes --leak-check=full --show-reachable=yes --error-exitcode=1 \
	../minishell < parts/$elem > outs/$elem\_minishell.out 2> ./logs/$elem.log
	error_code=$?
	printf "  \033[0;34mleaks: "
	if [ $error_code -eq 0 ]
	then
		printf "\033[0;32m [OK]\033[m\n"
	else
		printf "\033[0;31m [KO]\033[m  (check ./logs/$elem.log)\n"
		error=1
	fi
	diff outs/$elem\_bash.out outs/$elem\_minishell.out
	printf "  \033[0;34moutput: "
	if [ $? -eq 0 ]
	then
		printf "\033[0;32m[OK]\033[m\n"
	else
		printf "\033[0;31m[KO]\033[m  (check ./parts/$elem)\n"
		error=1
	fi
	printf "\n"
done

exit $error

#rm -r ./outs/