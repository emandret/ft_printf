/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:53:15 by emandret          #+#    #+#             */
/*   Updated: 2017/08/22 16:55:24 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabfree(void **tab)
{
	unsigned int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		ft_memdel((void**)&tab[i++]);
	ft_memdel((void**)&tab);
}
