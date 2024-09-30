/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <goolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:50:18 by goolivei          #+#    #+#             */
/*   Updated: 2024/09/30 16:50:29 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		error(3);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	close_fds();
	execute(argv[2], envp);
	exit(1);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fileout == -1)
		error(0);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close_fds();
	execute(argv[3], envp);
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc < 5 || argc > 5)
	{
		error(2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error(0);
	pid1 = fork();
	if (pid1 == -1)
		error(0);
	if (pid1 == 0)
		child_process(argv, envp, fd);
	close(fd[1]);
	pid1 = fork();
	if (pid1 == 0)
		parent_process(argv, envp, fd);
	close(fd[0]);
	close_fds();
	waitpid(pid1, NULL, 0);
	return (0);
}
