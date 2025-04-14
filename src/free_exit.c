/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:12:40 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/29 17:53:20 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **a)
{
	t_stack	*current;

	if (!a || !*a)
		return ;
	current = *a;
	while (current)
	{
		current = current->next;
		free(*a);
		*a = current;
	}
}

void	free_exit(t_stack **a)
{
	free_stack(a);
	exit(0);
}

void	free_exit_error(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(19);
}
