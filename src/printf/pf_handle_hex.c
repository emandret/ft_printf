/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/04/20 01:03:32 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void	pf_handle_hex(t_buffer *buffer, t_format *format, va_list ap)
{
	uintmax_t	n;
	char		*s;

	if (!(n = pf_get_unsigned(format, ap)))
	{
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		if (!format->has_precision)
			pf_buffer_putchar(buffer, '0');
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
	else
	{
		s = ft_ultoa_base(n, 16);
		if (format->conversion == X)
			s = ft_strtolower(s);
		if (format->flags.convert)
			format->min_field -= 2;
		pf_compute_num(format, ft_strlen(s));
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		if (format->flags.convert && format->conversion == X)
			pf_buffer_putstr(buffer, "0x");
		if (format->flags.convert && format->conversion != X)
			pf_buffer_putstr(buffer, "0X");
		pf_buffer_putnchar(buffer, '0', format->precision);
		pf_buffer_putstr(buffer, s);
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
}
