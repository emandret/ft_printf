/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:08:08 by emandret          #+#    #+#             */
/*   Updated: 2017/07/23 15:09:06 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char **env, char *key)
{
	unsigned int	i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if ('=' == ft_strcmp(env[i], key))
			return (&env[i][ft_strlen(key) + 1]);
		i++;
	}
	return (NULL);
}
