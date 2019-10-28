/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:59:17 by exam              #+#    #+#             */
/*   Updated: 2019/10/02 13:05:15 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		is_op(char c)
{
	return (c == '+' || c == '-' || c == '*'\
			|| c == '/' || c == '%');
}

int		is_digit(char c)
{
	return (c <= '9' && c >= '0');
}

int		countwd(char *s)
{
	int		i;
	int		wd;

	wd = 0;
	i = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
		{
			wd++;
			while (!is_space(s[i]) && s[i])
				i++;
		}
		else
			i++;
	}
	return (wd);
}

char	**split(char *s)
{
	char	**sp;
	int		wd;
	int		i;
	int		j;

	wd = countwd(s);
	if (!(sp = (char **)malloc(sizeof(char *) * (wd + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (!is_space(s[i]))
			sp[j++] = cpywd(s, &i);	
		else
			i++;
	}
	sp[j] = NULL;
	return (sp);
}

char	*cpywd(char *s, int *i)
{
	int		len;
	char	*str;

	len = 0;
	while (s[*i + len] && !is_space(s[*i + len]))
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	len = 0;
	while (s[*i] && !is_space(s[*i]))
	{
		str[len] = s[*i];
		len++;
		(*i)++;
	}
	str[len] = 0;
	return (str);
}

int		is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int		check_arg(char *s)
{
	char	**sp;
	int		i;

	if (!(sp = split(s)))
		return (0);
	i = 0;
	while (sp[i])
	{
		if (is_digit(*(sp[i])) && !check_digit(sp[i]))
			return (0);
		if (*(sp[i]) == '-' && check_digit((sp[i] + 1)))
			return (1);
		if (is_op(*(sp[i])) && ft_strlen(sp[i]) > 1)
			return (0);
		i++;
	}
	return (1);
}

int		check_digit(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		if (!is_digit(s[i++]))
			return (0);	
	return (1);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int		do_op(char op, int a, int b)
{
	if (op == '+')
		return (ft_add(a, b));
	if (op == '-')
		return (ft_sub(a, b));
	if (op == '*')
		return (ft_mul(a, b));
	if (op == '/')
		return (ft_div(a, b));
	if (op == '%')
		return (ft_mod(a, b));
	return (0);
}
