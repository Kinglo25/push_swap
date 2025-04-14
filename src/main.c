/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:00:02 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/29 17:57:01 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	long	size;

	a = NULL;
	b = NULL;
	if (!av[1])
		return (0);
	if (ac >= 2)
	{
		create_stack(ac, av, &a);
		if (is_sorted(a))
			free_exit(&a);
		size = index_stack(&a);
		if (ac == 3)
			sa(&a);
		else if (ac >= 4 && ac <= 6)
			sort_small_stacks(&a, &b, ac);
		else
			radix(&a, &b, size);
	}
	free_exit(&a);
}
