/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:33:17 by exam              #+#    #+#             */
/*   Updated: 2019/10/02 12:43:29 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H
# include <stdlib.h>
# include <stdio.h>
# define ERROR	{printf("Error\n"); return (1);}

typedef struct		s_stack
{
	int				op;
	struct s_stack	*next;
}					t_stack;

int					ft_add(int a, int b);
int					ft_sub(int a, int b);
int					ft_mul(int a, int b);
int					ft_div(int a, int b);
int					ft_mod(int a, int b);
void				free_stack(t_stack *a, t_stack *b);
int					is_op(char c);
int					is_digit(char c);
int					check_arg(char *s);
int					do_op(char op, int a, int b);
int					push(t_stack **stack, int op);
t_stack				*pop(t_stack **stack);

char				**split(char *s);
char				*cpywd(char *s, int *i);
int					is_space(char c);
int					check_digit(char *s);
void				free_strtab(char **s);
int					countwd(char *s);
int					ft_strlen(char *s);

#endif
