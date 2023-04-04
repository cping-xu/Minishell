/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_pipe_wait_child.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:29:27 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/03/30 16:43:43 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_pipe_wait_child(t_mini *mini, int i)
{
	int	j;

	j = -1;
	while (++j != mini->here_count)
	{
		close(mini->here_fd[j][0]);
		close(mini->here_fd[j][1]);
	}
	j = -1;
	while (++j < i)
	{
		close(mini->fd[j][0]);
		close(mini->fd[j][1]);
	}
	j = -1;
	while (++j <= i)
		waitpid(-1, NULL, 0);
}
