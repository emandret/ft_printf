/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:08:19 by emandret          #+#    #+#             */
/*   Updated: 2017/08/24 22:47:20 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getpath(char *path, char *file)
{
	if (file && '/' != path[ft_strlen(path) - 1])
		return (ft_strjoin_free(ft_strjoin(path, "/"), file));
	if (file)
		return (ft_strjoin(path, file));
	return (NULL);
}
