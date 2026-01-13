/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaigne <emaigne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 08:50:59 by emaigne           #+#    #+#             */
/*   Updated: 2026/01/13 10:02:11 by emaigne          ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
//# include "get_next_line/get_next_line.h"

void	clearmatrix(char **tab);
void	do_command(char *cmd, char **env);
void	handle_the_child(int pipe_fd[2], char *infile, char *cmd, char **env);
char	*find_path_line(char **env);
char	*test_all_paths(char *command, char *pathline);
char	*find_command(char *command, char **env);

#endif