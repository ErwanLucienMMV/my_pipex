/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:41:11 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/03 16:12:02 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>

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
			return (env[i]);
		i++;
	}
	return (NULL);
}

void	freetherest(char path_to_test[6], int tosave)
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

char	*test_usuals(char *command)
{
	char	*path_to_test[6];
	int		i;

	i = 0;
	path_to_test[0] = ft_strjoin("/usr/local/sbin/", command);
	path_to_test[1] = ft_strjoin("/usr/local/bin/", command);
	path_to_test[2] = ft_strjoin("/usr/sbin/", command);
	path_to_test[3] = ft_strjoin("/usr/bin/", command);
	path_to_test[4] = ft_strjoin("/sbin/", command);
	path_to_test[5] = ft_strjoin("/bin/", command);
	while (i < 6)
	{
		if (path_to_test[i] && access(path_to_test[i], X_OK) == 0)
			return (freetherest(path_to_test, i), path_to_test[i]);
		i++;
	}
	freetherest(path_to_test, 6);
	return (NULL);
}

char	*test_all_paths(char *command, char *pathline)
{
	char	*res;

	res = NULL;
	if (pathline == NULL)
		res = test_usuals();
}

char	*does_command_exists(char *command, char **env)
{
	char	*pathline;
	char	*findaway;

	pathline = find_path_line(env);
	findaway = test_all_paths(pathline);
	
	return (NULL);
}