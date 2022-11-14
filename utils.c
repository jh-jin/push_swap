/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:49:45 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 23:43:29 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_target_in_top_exactly(t_stack *a, int target)
{
	t_node	*stack;
	int		index;
	int		half_len;

	stack = a->head;
	half_len = a->len / 2;
	index = 0;
	while (stack && index <= half_len)
	{
		if (stack->rank == target)
			return (index - 1);
		index++;
		stack = stack->next;
	}
	return (index - 1);
}

int	is_target_in_bot_exactly(t_stack *a, int target)
{
	t_node	*stack;
	int		index;
	int		half_len;

	stack = a->tail;
	half_len = a->len / 2;
	index = 0;
	while (stack && index < half_len)
	{
		if (stack->rank == target)
			return (index);
		index++;
		stack = stack->prev;
	}
	return (index);
}

void	rotate_stack_exactly(t_stack *s, int target, int command)
{
	while (s->head->rank != target)
		operation(s, s, command);
}

void	printf_command(int command)
{
	if (command == SA)
		write(1, "sa\n", 3);
	if (command == SB)
		write(1, "sb\n", 3);
	if (command == PA)
		write(1, "pa\n", 3);
	if (command == PB)
		write(1, "pb\n", 3);
	if (command == RA)
		write(1, "ra\n", 3);
	if (command == RB)
		write(1, "rb\n", 3);
	if (command == RRA)
		write(1, "rra\n", 4);
	if (command == RRB)
		write(1, "rrb\n", 4);
}
