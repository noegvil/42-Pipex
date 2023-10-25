/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathname2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 09:35:51 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/16 13:30:20 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*search_envp(char **envp)
{
	int				i;
	const char		*search;

	if (!envp)
		return (NULL);
	search = "PATH=";
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp((const char *)envp[i], search, 5) == 0)
			break ;
		i++;
	}
	return (envp[i] + 5);
}

char	*get_pathname(char *paths, char *command)
{
	char	*almost_path;
	char	*pathname;

	almost_path = ft_strjoin(paths, "/");
	if (!almost_path)
		return (NULL);
	pathname = ft_strjoin(almost_path, command);
	free (almost_path);
	if (!pathname)
		return (NULL);
	return (pathname);
}

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free (paths);
}

char	*iterate_pathname(char *path_env, char *command)
{
	char	**paths;
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		if (access(get_pathname(paths[i], command), X_OK) == 0)
		{
			result = get_pathname(paths[i], command);
			break ;
		}
		i++;
	}
	free_paths(paths);
	return (result);
}

char	*find_path(char *path_envp, char *command)
{
	char	*pathname;

	pathname = NULL;
	if (!command)
		return (NULL);
	pathname = iterate_pathname(path_envp, command);
	return (pathname);
}

/*
int main(int argc, char **argv, char **envp)
{
	char	**command_table;
	char	*pathname;
	int		i;
	
	if (argc > 1)
	{	
		i = 1;
		while (i < argc)
		{
			command_table = get_command(argv[i]);
			pathname = find_path(search_envp(envp), command_table[0]);
			printf("Este es el pathname: %s\n", pathname);
			i++;
		}
	}
    return(0);
}*/
