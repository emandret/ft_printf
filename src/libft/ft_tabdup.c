/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 03:23:09 by emandret          #+#    #+#             */
/*   Updated: 2017/07/28 03:23:46 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i++]);
	return (i);
}

char		**ft_tabdup(char **tab)
{
	unsigned int	i;
	char			**new;

	if (!(new = (char**)ft_memalloc(sizeof(char*) * size(tab))))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
