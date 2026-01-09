/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:41:11 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/09 17:22:03 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_error(char *filepath)
{
	printf("Yup an error was raised, on file: %s\n", filepath);
	if (errno == ENOENT)
		perror (filepath);
	if (errno == EACCES)
		perror (filepath);
}

void	free_my_mess(t_data *data, int status)
{
	if (status >= 1)
	{
		free(data->command1);
		data->command1 = NULL;
	}
	if (status >= 2)
	{
		free(data->command2);
		data->command2 = NULL;
	}
}

bool	load_input(char **argv, t_data *data, char **env)
{
	data->args1 = ft_split(argv[2], ' ');
	printf("Searching for command: %s\n", data->args1[0]);
	if (data->args1)
		data->command1 = find_command(data->args1[0], env);
	printf("%s\n", data->command1);
	if (!(data->command1))
		handle_error(data->command1);
	data->args2 = ft_split(argv[3], ' ');
	if (data->args2)
		data->command2 = find_command(data->args2[0], env);
	if (!(data->command2))
		handle_error(data->command2);
	printf("%s\n", data->command1);
	// if (access(argv[1], F_OK | R_OK) == -1)
	// {
	// 	handle_error(argv[1]);
	// 	res = false;
	// }
	// // if (access(argv[4], W_OK) == -1)
	// // 	handle_error(argv[4]);
	return (true);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		pipefd[2];
	int		pid[2];

	if (argc != 5)
		return (1);
	pipe(pipefd); //initialise mes deux fd Entree/sortie DU pipe qui seront commun a tout les futurs fork tant que je ne close pas dans le principal
	dprintf(2, "here\n");
	if (load_input(argv, &data, env))
	{
		pid[0] = fork(); //a partir de maintenant l'enfant possede un duplicata du pipe
		if (pid[0] == 0) //on est dans l'enfant
		{
			close(pipefd[0]);
			dup2(pipefd[1], 1); //redirige sur pipefd de l'index correspondant
			close(pipefd[1]);

			char *arg[] = {"ls", "-la", (char*)0};
			execve("/bin/ls", arg, env);
			perror("");
			exit(0);
		}
		else
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			
			// char *arg[] = {"cat", "-e", (char*)0};
			// execve("/bin/cat", arg, env);
			// perror("");
			// exit(0);
		}
		pid[1] = fork();
		if (pid[1] == 0)
		{
			int fd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(fd, 1);

			char *arg[] = {"cat", "-e", (char*)0};
			execve("/bin/cat", arg, env);
			perror("");
			close(fd);
			exit(0);
		}
		printf("salut\n");
		waitpid(-1, NULL, 0);
	}
	return (0);
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
