/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:45:08 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/13 10:25:41 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clearmatrix(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

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
	execve(new_cmd, splited_cmd, env);
	perror("execve:");
	clearmatrix(splited_cmd);
	free(new_cmd);
	exit(1);
}

void	handle_the_child(int pipe_fd[2],char *infile, char *cmd, char **env)
{
	int		fd;

	close(pipe_fd[0]);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		return (perror("open"), exit(1));
	dup2(fd, STDIN_FILENO);
	close(fd);
	do_command(cmd, env);
}
