/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomajeru <lomajeru@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:53:34 by lmajerus          #+#    #+#             */
/*   Updated: 2023/11/14 15:14:46 by lomajeru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi_ps(char *str, t_stack **a)
{
	long	ans;
	int		i;
	int		signe;

	ans = 0;
	i = 0;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			free_exit_error(a);
		ans *= 10;
		ans += (int)(str[i] - 48);
		i++;
	}
	ans *= signe;
	if (ans > 2147483647 || ans < -2147483648)
		free_exit_error(a);
	return (ans);
}

static t_stack	*ft_lstnew_ps(int content, t_stack **a)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		free_exit_error(a);
	new->num = content;
	new->next = NULL;
	return (new);
}

static	t_stack	*ft_lstlast_ps(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast_ps(*lst)->next = new;
}

void	create_stack(long ac, char **av, t_stack **a)
{
	int		i;
	t_stack	*begin1;
	t_stack	*begin2;
	int		num;

	i = 1;
	while (i < ac)
		ft_lstadd_back_ps(a, ft_lstnew_ps(ft_atoi_ps(av[i++], a), a));
	begin1 = *a;
	while (begin1)
	{
		num = begin1->num;
		begin2 = begin1->next;
		while (begin2)
		{
			if (num == begin2->num)
				free_exit_error(a);
			begin2 = begin2->next;
		}
		begin1 = begin1->next;
	}
}
