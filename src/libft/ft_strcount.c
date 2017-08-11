/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 13:37:49 by emandret          #+#    #+#             */
/*   Updated: 2017/08/11 14:30:52 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcount(const char *s, const char *in)
{
	int	count;

	if (!s || !in)
		return (0);
	count = 0;
	while (s)
	{
		if ((s = ft_strstr(s, in)))
		{
			count++;
			s += ft_strlen(in);
		}
	}
	return (count);
}
