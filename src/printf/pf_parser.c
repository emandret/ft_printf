/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/04/19 23:41:26 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static void	convert_modi(t_format *format);

t_format	*pf_parser(const char **s, t_format *format)
{
	(*s)++;
	pf_parse_flag(s, format);
	pf_parse_numb(s, format);
	pf_parse_modi(s, format);
	pf_parse_conv(s, format);
	convert_modi(format);
	return (format);
}

static void	convert_modi(t_format *format)
{
	if (format->modifier == L && format->conversion == C)
		format->conversion = CC;
	if (format->modifier == L && format->conversion == S)
		format->conversion = SS;
}
