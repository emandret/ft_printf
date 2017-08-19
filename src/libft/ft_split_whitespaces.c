/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:56:40 by emandret          #+#    #+#             */
/*   Updated: 2017/08/19 16:27:31 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip(const char *s, unsigned int *i)
{
	while (s[*i] && ft_isblanks(s[*i]))
		(*i)++;
}

static int	count_words(const char *s)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 1;
	while (s[i])
	{
		skip(s, &i);
		if (s[i] && !ft_isblanks(s[i]))
		{
			while (s[i] && !ft_isblanks(s[i]))
				i++;
			words++;
		}
	}
	return (words);
}

static void	add(char **s, char c)
{
	char	*new;
	char	*tmp;
	size_t	size;

	if (s)
	{
		if (*s)
		{
			size = ft_strlen(*s);
			new = ft_strnew(size + 1);
			new = ft_strcpy(new, *s);
			new[size] = c;
			tmp = *s;
			*s = new;
			ft_memdel((void**)&tmp);
		}
		else
		{
			*s = ft_strnew(1);
			**s = c;
		}
	}
}

char		**ft_split_whitespaces(const char *s)
{
	unsigned int	i;
	unsigned int	j;
	char			**t;

	t = NULL;
	if ((t = (char**)ft_memalloc(sizeof(char*) * (count_words(s) + 1))))
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			skip(s, &i);
			if (s[i] && !ft_isblanks(s[i]))
			{
				while (s[i] && !ft_isblanks(s[i]))
				{
					add(t + j, s[i]);
					i++;
				}
				j++;
				t[j] = NULL;
			}
		}
	}
	return (t);
}
