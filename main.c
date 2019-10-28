/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:02:52 by exam              #+#    #+#             */
/*   Updated: 2019/10/02 13:08:49 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		main(int ac, char **av)
{
	int			i;
	int			nb;
	char		*s;
	t_stack		*stk;
	t_stack		*a;
	t_stack		*b;

	if (ac != 2)
		ERROR
	stk = NULL;
	s = av[1];
	if (!check_arg(s))
		ERROR
	i = 0;
	while (s[i])
	{
		nb = 0;
		if (is_digit(s[i]) || (is_op(s[i]) && is_digit(s[i + 1])))
		{
			nb = atoi(&s[i]);
			if (!push(&stk, nb))
				ERROR
			while (s[i+ 1] && is_digit(s[i + 1]))
				i++;
		}
		else if (is_op(s[i]))
		{
			if (!(b = pop(&stk)) || !(a = pop(&stk)))
			{
				free_stack(a, b);
				ERROR
			}
			if ((s[i] == '/' || s[i] == '%') && b->op == 0)
			{
				free_stack(stk, NULL);
				ERROR
			}
			nb = do_op(s[i], a->op, b->op);
			if (!(push(&stk, nb)))
			{
				ERROR
			}
			i++;
		}
		else if ( s[i] && s[i] != ' ')
			ERROR
		else
			i++;
	}
	a = pop(&stk);
	b = pop(&stk);
	if (!a || b)
	{
		free_stack(a, b);
		ERROR
	}
	free_stack(a, NULL);
	printf("%d\n", a->op);
	return (0);
}
