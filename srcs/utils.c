/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <goolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:50:25 by goolivei          #+#    #+#             */
/*   Updated: 2024/09/30 17:06:39 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	if (!*envp)
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	if (ft_strncmp(envp[i], "PATH", 4) != 0)
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (path_finder(cmd, paths));
}

char	*path_finder(char *cmd, char **paths)
{
	int		i;
	char	*path;
	char	*part_path;

	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	error(5);
	return (0);
}

void	error(int err_id)
{
	if (err_id == 0)
		ft_putstr_fd("\033[31mError[0m", 2);
	else if (err_id == 1)
		ft_putstr_fd("\033[31mError: non existing enviroment\n\e[0m", 2);
	else if (err_id == 2)
	{
		ft_putstr_fd("\033[31mError: Invalid arguments\n\e[0m", 2);
		ft_putstr_fd("Valid ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	else if (err_id == 3)
		ft_putstr_fd("\033[31mError: non existing file\n\e[0m", 2);
	else if (err_id == 4)
		ft_putstr_fd("\033[31mError: unable to find path\n\e[0m", 2);
	else if (err_id == 5)
		ft_putstr_fd("\033[31mError: invalid command(s)\n\e[0m", 2);
	exit(EXIT_FAILURE);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	if (access(argv, X_OK) == 0)
		execve(argv, cmd, envp);
	path = find_path(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		error(5);
	}
	if (path)
		if (execve(path, cmd, envp) == -1)
			perror("");
}

void	close_fds(void)
{
	int	i;

	i = 3;
	while (i <= FOPEN_MAX)
	{
		close(i);
		i++;
	}
}
