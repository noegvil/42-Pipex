/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 11:28:00 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/16 14:02:55 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	pipex_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_pipex(char **argv, char **envp, t_pipex pipex)
{
	if (pipe(pipex.tube) == -1)
		pipex_error("Error creating pipe\n");
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		pipex_error("Error in first child process\n");
	else if (pipex.pid1 == 0)
		first_command(argv, envp, pipex);
	else
	{
		close(pipex.tube[WRITE_END]);
		pipex.pid2 = fork();
		if (pipex.pid2 == -1)
			pipex_error("Error in second child process\n");
		else if (pipex.pid2 == 0)
			second_command(argv, envp, pipex);
		close(pipex.tube[READ_END]);
	}
	waitpid(pipex.pid1, &pipex.status, 0);
	waitpid(pipex.pid2, &pipex.status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		pipex_error("Invalid number of arguments\n");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		pipex_error("No such file or directory\n");
	pipex.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		pipex_error("No such file or directory\n");
	ft_pipex(argv, envp, pipex);
	close(pipex.infile);
	close(pipex.outfile);
	return (0);
}
