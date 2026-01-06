/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 13:41:11 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/06 17:58:26 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "pipex.h"

void	handle_error(char *filepath)
{
	if (errno == ENOENT)
		perror (filepath);
	if (errno == EACCES)
		perror (filepath);
}

void	free_my_mess(t_data *data, int status)
{
	if (status < 1)
	{
		free(data->command1);
		data->command1 = NULL;
	}
	if (status < 2)
	{
		free(data->command2);
		data->command2 = NULL;
	}
}

bool	load_valid_input(char **argv, t_data *data, char **env)
{
	data->command1 = does_command_exists(argv[2], env);
	if (!data->command1)
	{
		free_my_mess(data, 0);
		handle_error(data->command1);
	}
	data->command1 = does_command_exists(argv[3], env);
	if (!data->command2)
	{
		free_my_mess(data, 1);
		handle_error(data->command2);
	}
	if (access(argv[1], F_OK | R_OK) == -1)
		handle_error(argv[1]);
	if (access(argv[4], W_OK) == -1)
		handle_error(argv[4]);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
		return (1);
	load_valid_input(argv, &data, env);
	return (0);
}
