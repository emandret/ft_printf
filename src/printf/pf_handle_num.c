/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/04/20 01:20:32 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

void	pf_handle_num(t_buffer *buffer, t_format *format, va_list ap)
{
	intmax_t	n;
	char		*s;

	if (!(n = pf_get_signed(format, ap)))
	{
		if (format->flags.enforce_sign || format->flags.space_left || format->flags.space_right)
			format->min_field--;
		pf_compute_num(format, 0);
		if (format->flags.space_left)
			pf_buffer_putchar(buffer, ' ');
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		if (format->flags.enforce_sign)
			pf_buffer_putchar(buffer, '+');
		pf_buffer_putnchar(buffer, '0', format->precision);
		if (!format->has_precision && !format->flags.zero_padding)
			pf_buffer_putchar(buffer, '0');
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
	else
	{
		s = ft_ltoa_base(ABS(n), 10);
		if (format->flags.enforce_sign || n < 0)
			format->min_field--;
		pf_compute_num(format, ft_strlen(s));
		if (!(format->flags.enforce_sign || n < 0) && (format->flags.zero_padding || format->flags.space_left))
			format->min_field--;
		if (format->flags.space_left && n >= 0)
			pf_buffer_putchar(buffer, ' ');
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		if (format->flags.enforce_sign && n >= 0)
			pf_buffer_putchar(buffer, '+');
		if (n < 0)
			pf_buffer_putchar(buffer, '-');
		pf_buffer_putnchar(buffer, '0', format->precision);
		pf_buffer_putstr(buffer, s);
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
}

void	pf_handle_uns(t_buffer *buffer, t_format *format, va_list ap)
{
	uintmax_t	n;
	char		*s;

	if (!(n = pf_get_unsigned(format, ap)))
	{
		if (format->flags.space_left || format->flags.space_right)
			format->min_field--;
		pf_compute_num(format, 0);
		if (format->flags.space_left)
			pf_buffer_putchar(buffer, ' ');
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		pf_buffer_putnchar(buffer, '0', format->precision);
		if (!format->has_precision && !format->flags.zero_padding)
			pf_buffer_putchar(buffer, '0');
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
	else
	{
		s = ft_ultoa_base(n, 10);
		pf_compute_num(format, ft_strlen(s));
		if (!format->flags.zero_padding && !format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
		pf_buffer_putnchar(buffer, '0', format->precision);
		pf_buffer_putstr(buffer, s);
		if (format->flags.space_right)
			pf_buffer_putnchar(buffer, ' ', format->min_field);
	}
}
