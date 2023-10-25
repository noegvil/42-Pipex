/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:15:59 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/16 13:38:10 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	first_command(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.infile, STDIN_FILENO);
	close(pipex.tube[READ_END]);
	dup2(pipex.tube[WRITE_END], STDOUT_FILENO);
	close(pipex.tube[WRITE_END]);
	execute(&argv[2], envp);
}
