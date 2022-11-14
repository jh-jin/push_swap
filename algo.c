/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_any_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:48:50 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 20:49:48 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	len_any_sort(t_stack *a, t_stack *b)
{
	make_sand_clock(a, b);
	sort_b_to_a(a, b);
}

void	make_sand_clock(t_stack *a, t_stack *b)
{
	int		threshold;
	int		num;

	num = 0;
	threshold = 0.000000053 * a->len * a->len + 0.03 * a->len + 14.5;
	while (a->len)
	{
		if (a->head->rank <= num)
		{
			operation(a, b, PB);
			num++;
		}
		else if (a->head->rank <= num + threshold)
		{
			operation(a, b, PB);
			operation(a, b, RB);
			num++;
		}
		else if (a->tail->rank <= num + threshold)
			operation(a, b, RRA);
		else
			operation(a, b, RA);
	}
}

void	sort_b_to_a(t_stack *a, t_stack *b)
{
	int	target;

	target = b->len - 1;
	while (b->len > 0)
	{
		if (b->head->rank == target)
		{
			operation(a, b, PA);
			target--;
		}
		else
		{
			if (is_target_in_top_exactly(b, target) < \
			is_target_in_bot_exactly(b, target))
				rotate_stack_exactly(b, target, RB);
			else
				rotate_stack_exactly(b, target, RRB);
		}
	}
}
