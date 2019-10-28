/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:58:39 by exam              #+#    #+#             */
/*   Updated: 2019/07/25 17:01:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

void	free_stack(t_stack *a, t_stack *b)
{

	if (a)
		free(a);
	if (b)
		free(b);
}

int		push(t_stack **stack, int op)
{
	t_stack		*new;

	new = NULL;
	if (!*stack)
	{
		if (!(*stack = (t_stack *)malloc(sizeof(t_stack))))
			return (0);
		(*stack)->op = op;
		(*stack)->next = NULL;
		return (1);
	}
	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (0);
	new->op = op;
	new->next = *stack;
	*stack = new;
	return ((int)new);
}

t_stack	*pop(t_stack **stack)
{
	t_stack		*top;

	if (*stack)
	{
		top = *stack;	
		*stack = top->next;
		return (top);
	}
	return (NULL);
}
