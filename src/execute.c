/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:55:34 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/16 14:07:39 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**get_command(char *str)
{
	char	**command_table;

	command_table = ft_split(str, ' ');
	if (!command_table)
		return (NULL);
	if (ft_strncmp(command_table[0], "awk", 3) == 0)
	{
		if (command_table[1][0] == '\'')
			command_table[1] = ft_strtrim(command_table[1], "'");
		else if (command_table[1][0] == '"')
			command_table[1] = ft_strtrim(command_table[1], "\"");
	}
	return (command_table);
}

void	execute(char **argv, char **envp)
{
	char	**command_table;
	char	*pathname;

	command_table = get_command(*argv);
	if (!command_table)
	{
		while (*command_table)
		{
			free(*command_table);
			command_table++;
		}
		free(command_table);
		perror("command not found");
		exit(127);
	}
	pathname = find_path(search_envp(envp), command_table[0]);
	if (!pathname)
	{
		perror("command not found");
		exit(127);
	}
	execve(pathname, command_table, envp);
}
