/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:41:11 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/13 08:03:14 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_command(char *cmd, char **env)
{
	char	**splited_cmd;
	char	*new_cmd;

	splited_cmd = ft_split(cmd, ' ');
	if (!splited_cmd)
	{
		perror("Splitting for command:");
		exit (1);
	}
	new_cmd = find_command(splited_cmd[0], env);
	if (!new_cmd)
	{
		perror("Getting the path cmd:");
		clearmatrix(splited_cmd);
		exit (1);
	}
	if (execve(new_cmd, splited_cmd, env))
	{
		perror("execve:");
		clearmatrix(splited_cmd);
		free(new_cmd);
		exit(1);
	}
}


int	main(int argc, char **argv, char **env)
{
	int		i;

	i = 2;
	if (argc != 5)
		return (1);
	while (i < argc)
	{
		if (i == 2)
			first_exec(argv[1], argv[2], env);
		else if (i == argc - 1)
			last_exec(argv[argc - 1], argv[argc - 2], env);
		else
			middle_exec(argv[i], env);
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (1);
}

//extern char	**environ;
//todo modifier structure data pour accueillir les args de chaque commande
// une commande invalide ne bloque pas l'execution de l'autre
// int	main(int argc, char **argv , char **env)
// {
// 	t_data	data;
// 	int		pipefd[2];
// 	int		pid[2];

// 	if (argc != 5)
// 		return (1);
// 	pipe(pipefd); //initialise mes deux fd Entree/sortie DU pipe
// 	//if (load_valid_input(argv, &data, env))
// 	//{
// 		pid[0] = fork(); //a partir de maintenant l'enfant possede un duplicata du pipe
// 		if (pid[0] == 0) //on est dans l'enfant
// 		{
// 			//dprintf(2, "here\n");
// 			close(pipefd[0]);
// 			dup2(pipefd[1], 1); //redirige sur pipefd de l'index correspondant
// 			close(pipefd[1]);

// 			char *arg[] = {"ls", "-la", (char*)0};
// 			execve("/bin/ls", arg, env);
// 			perror("");
// 			exit(0);
// 		}
// 		else
// 		{
// 			close(pipefd[1]);
// 			dup2(pipefd[0], 0);
// 			close(pipefd[0]);
			
// 			// char *arg[] = {"cat", "-e", (char*)0};
// 			// execve("/bin/cat", arg, env);
// 			// perror("");
// 			// exit(0);
// 		}
// 		pid[1] = fork();
// 		if (pid[1] == 0)
// 		{
// 			int fd = open("out", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 			dup2(fd, 1);

// 			char *arg[] = {"cat", "-e", (char*)0};
// 			execve("/bin/cat", arg, env);
// 			perror("");
// 			exit(0);
// 		}
// 		printf("salut\n");
// 		waitpid(-1, NULL, 0);
// 	//}
// 	return (0);
// }
