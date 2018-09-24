/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 09:27:48 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/17 09:35:05 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

char **g_env;
void    ft_env();
void    ft_echo(char **command);
void    ft_print_env_value(int index, int n);
int	    ft_envlen(char **envp);
void    ft_setenv(char **command);
int ft_isenv(char *str, int n);
void    ft_unsetenv(char **command);

#endif
