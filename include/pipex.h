/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noelgarc <noelgarc@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 19:25:09 by noelgarc          #+#    #+#             */
/*   Updated: 2023/05/15 19:29:29 by noelgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

/* write, read, close, access, pipe, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* open */
# include <fcntl.h>

/* malloc, free, exit */
# include <stdlib.h>

/* waitpid */
# include <sys/wait.h>

/* perror */
# include <stdio.h>

/* index pipe extremos lectura y escritura */
# define READ_END    0
# define WRITE_END   1  

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	int		status;
}	t_pipex;

/* error function */
void	pipex_error(char *str);

/* path functions */
char	*search_envp(char **envp);
char	*iterate_pathname(char *path_env, char *command);
char	*get_pathname(char *paths, char *command);
char	*find_path(char *path_envp, char *command);
void	free_paths(char **paths);

/* command functions */
char	**get_command(char *str);
void	execute(char **argv, char **envp);
void	first_command(char **argv, char **envp, t_pipex pipex);
void	second_command(char **argv, char **envp, t_pipex pipex);
void	ft_pipex(char **argv, char **envp, t_pipex pipex);

#endif