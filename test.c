void ft_exec(char *cmd, char **env)
{
	char 	**splited_cmd;
	char 	*new_cmd;

	splited_cmd = ft_split(cmd, ' ');
	if (!splited_cmd)
	{
		perror("split");
		exit (1);
	}
	new_cmd = get_path_cmd(splited_cmd[0], env);
	if (!new_cmd)
	{
		perror("Get path cmd");
		ft_free_tab(splited_cmd);
		exit (1);
	}
	
	if (execve(new_cmd, splited_cmd, env))
	{
		perror("execve");
		ft_free_tab(splited_cmd);
		free(new_cmd);
		exit(1);
	}
}
void end_exec(char *outfile , char *cmd, char **env)
{
	pid_t 	pid;
	int 	fd;

	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		exit(1);
	}
	if (pid) // parent
	{
		return ;
	}
	else // child
	{
		fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
		{
			perror("open");
			exit(1);
		}
		dup2(STDOUT_FILENO, fd);
		close(fd);
		ft_exec(cmd, env);
	}
}

void middle_exec(char *cmd, char **env)
{
	pid_t 	pid;
	int 	pipe_fd[2];

	if (pipe(pipe_fd) != 0)
	{
		perror("pipe");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(2);
	}
	if (pid) // parent
	{
		close(pipe_fd[1]);
		dup2(STDIN_FILENO, pipe_fd[0]);
		close(pipe_fd[0]);
	}
	else // child
	{
		close(pipe_fd[0]);
		dup2(STDOUT_FILENO, pipe_fd[1]);
		close(pipe_fd[1]);
		ft_exec(cmd, env);
	}
}

void first_exec(char *infile , char *cmd, char **env)
{
	pid_t 	pid;
	int 	fd;
	int 	pipe_fd[2];

	if (pipe(pipe_fd) != 0)
	{
		perror("pipe");
		exit (1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("pid");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exit(1);
	}
	if (pid) // parent
	{
		close(pipe_fd[1]);
		dup2(STDIN_FILENO, pipe_fd[0]);
		close(pipe_fd[0]);
	}
	else // child
	{
		close(pipe_fd[0]);
		dup2(STDOUT_FILENO, pipe_fd[1]);
		close(pipe_fd[1]);
		fd = open(inflie, O_RONLY);
		if (fd < 0)
		{
			perror("open");
			exit(1);
		}
		dup2(STDIN_FILENO, fd);
		close(fd);
		ft_exec(cmd, env);
	}
}

int check_args(int ac)
{
	if (ac < 5)
	{
		write(2, "Pipex need 5 args\n", 19);
		return (0);
	}
	return (1)
}

int main(int ac, char **av, char **env)
{
	int 	i;
	int 	pipe_fd[2];
	pid_t 	pid;

	i = 2;
	if (check_args(ac))
		return (1);
	while (i < ac)
	{
		if (i == 2)
			first_exec(av[1] , av[2], env);
		else if (i == ac - 1)
			end_exec(av[ac], av[ac - 1], env);
		else
			middle_exec(av[i], env);
		i++;
	}
	wait(-1);
	return (1);
}
