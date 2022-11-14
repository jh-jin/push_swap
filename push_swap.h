/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjin <jjin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:26:46 by jjin              #+#    #+#             */
/*   Updated: 2022/11/14 20:21:21 by jjin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				rank;
	int				val;
}t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		len;
}t_stack;

#endif