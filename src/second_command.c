/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:58:46 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/15 19:17:35 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	second_command(char **argv, char **envp, t_pipex pipex)
{
	dup2(pipex.tube[READ_END], STDIN_FILENO);
	close(pipex.tube[WRITE_END]);
	dup2(pipex.outfile, STDOUT_FILENO);
	close(pipex.tube[READ_END]);
	execute(&argv[3], envp);
}
