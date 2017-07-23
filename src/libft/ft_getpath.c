/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:08:19 by emandret          #+#    #+#             */
/*   Updated: 2017/07/23 15:09:33 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getpath(char *path, char *file)
{
	if ('/' != path[ft_strlen(path) - 1])
		path = ft_strjoin(path, "/");
	if (file)
		return (ft_strjoin(path, file));
	return (NULL);
}
