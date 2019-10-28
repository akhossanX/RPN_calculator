/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:10:01 by exam              #+#    #+#             */
/*   Updated: 2019/07/25 16:42:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.h"

int		ft_add(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}
