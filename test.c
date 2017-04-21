/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:24:12 by emandret          #+#    #+#             */
/*   Updated: 2017/04/23 13:49:35 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/printf/inc/ft_printf.h"
#include <locale.h>
#include <stdio.h>

static t_bool	assert_ft_printf(int ret, int ex_ret)
{
	if (ret == ex_ret)
	{
		printf("\e[92m[OK]");
		printf("\e[39m\n");
		return (TRUE);
	}
	printf("\e[91m[ERROR]");
	printf("\e[39m\n");
	printf("Expected return %d, returned %d\n", ex_ret, ret);
	return (FALSE);
}

int				main(void)
{
	int	ret, ex_ret;

	setlocale(LC_ALL, "");
	ret = ft_printf("{%lld}\n", -9223372036854775808);
	ex_ret = printf("{%lld}\n", -9223372036854775808);
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%S}\n", L"Мы хотим больше сиськов");
	ex_ret = printf("{%S}\n", L"Мы хотим больше сиськов");
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%30S}\n", L"我是一只猫");
	ex_ret = printf("{%30S}\n", L"我是一只猫");
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%.d}\n", 0);
	ex_ret = printf("{%.d}\n", 0);
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%#.O}\n", 0);
	ex_ret = printf("{%#.O}\n", 0);
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%4.s}\n", "42");
	ex_ret = printf("{%4.s}\n", "42");
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	ret = ft_printf("{%.c}\n", 0);
	ex_ret = printf("{%.c}\n", 0);
	if (!assert_ft_printf(ret, ex_ret))
		return (-1);
	return (0);
}
