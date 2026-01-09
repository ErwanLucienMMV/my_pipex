/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:44:23 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/09 15:39:02 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path_line(char **env)
{
	char	*pathline;
	char	*searched;
	int		i;
	int		j;

	searched = "PATH=";
	i = 0;
	while (env && env[i])
	{
		j = 0;
		while (env[i][j] && searched[j])
		{
			if (env[i][j] != searched[j])
				break ;
			j++;
		}
		if (searched[j] == '\0')
			return (env[i] + j);
		i++;
	}
	return (NULL);
}

static void	freetherest(char path_to_test[6], int tosave)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (i != tosave && path_to_test[i])
			free(path_to_test);
		i++;
	}
}

static char	*test_usuals(char *command)
{
	char	*path_to_test[6];
	int		i;

	i = 0;
	path_to_test[0] = ft_strjoin("/usr/local/sbin", command);
	path_to_test[1] = ft_strjoin("/usr/local/bin", command);
	path_to_test[2] = ft_strjoin("/usr/sbin", command);
	path_to_test[3] = ft_strjoin("/usr/bin", command);
	path_to_test[4] = ft_strjoin("/sbin", command);
	path_to_test[5] = ft_strjoin("/bin", command);
	while (i < 6)
	{
		if (path_to_test[i] && access(path_to_test[i], X_OK) == 0)
			return (freetherest(path_to_test, i), path_to_test[i]);
		i++;
	}
	freetherest(path_to_test, -1);
	return (NULL);
}

char	*test_all_paths(char *command, char *pathline)
{
	char	*res;
	char	*pathtested;
	char	**possiblepaths;
	int		i;

	i = 0;
	res = NULL;
	if (pathline == NULL)
		res = test_usuals(command);
	else
	{
		possiblepaths = ft_split(pathline, ':');
		while (possiblepaths && possiblepaths[i])
		{
			pathtested = ft_strjoin(possiblepaths[i], command);
			if (pathtested && access(pathtested[i], X_OK) == 0)
			{
				res = pathtested;
				clearmatrix(possiblepaths);
				break ;
			}
			free(pathtested);
			i++;
		}
	}
	return (res);
}

char	*does_command_exists(char *command, char **env)
{
	char	*pathline;
	char	*findaway;
	char	*pathcommand;

	pathcommand = ft_strjoin("/", command);
	if (!pathcommand)
		return (NULL);
	pathline = find_path_line(env);
	findaway = test_all_paths(pathcommand, pathline);
	dprintf(2, "here2\n");
	free(pathcommand);
	dprintf(2, "here3\n");
	return (findaway);
}
