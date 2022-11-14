/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:23:11 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 20:50:13 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	len_three_sort(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(a))
		return ;
	top = a->head->rank;
	mid = a->head->next->rank;
	bot = a->head->next->next->rank;
	if (top < bot && top < mid)
	{
		operation(a, NULL, SA);
		operation(a, NULL, RA);
	}
	else if (mid < top && top < bot && mid < bot)
		operation(a, NULL, SA);
	else if (bot < top && top < mid && bot < mid)
		operation(a, NULL, RRA);
	else
	{
		operation(a, NULL, RA);
		if (bot < mid)
			operation(a, NULL, SA);
	}
}

void	len_four_sort(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		if (a->head->rank == 0)
			break ;
		else
			operation(a, b, RA);
	}
	operation(a, b, PB);
	len_three_sort(a);
	operation(a, b, PA);
}

void	len_five_sort(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	{
		if (a->head->rank < 2)
			operation(a, b, PB);
		else
			operation(a, b, RA);
	}
	len_three_sort(a);
	operation(a, b, PA);
	operation(a, b, PA);
	if (a->head->rank != 0)
		operation(a, b, SA);
}

void	do_algorithm(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		operation(a, b, SA);
	else if (a->len == 3)
		len_three_sort(a);
	else if (a->len == 4)
		len_four_sort(a, b);
	else if (a->len == 5)
		len_five_sort(a, b);
	else
		len_any_sort(a, b);
}
