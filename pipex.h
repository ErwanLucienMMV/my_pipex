/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:50:59 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/09 15:29:09 by emaigne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdbool.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
//# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
//# include "get_next_line/get_next_line.h"

typedef struct s_data
{
	char	*command1;
	char	*command2;
}	t_data;

void	clearmatrix(char **tab);
char	*find_path_line(char **env);
char	*test_all_paths(char *command, char *pathline);
char	*does_command_exists(char *command, char **env);

#endif