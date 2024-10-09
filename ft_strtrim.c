/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znicola <znicola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 12:28:40 by znicola           #+#    #+#             */
/*   Updated: 2024/10/09 21:12:31 by znicola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_chars_in_set(const char *s1, const char *set)
{
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			return (0);
		s1++;
	}
	return (1);
}

static void	strt_end(size_t *st, size_t *en, char const *s1, char const *set)
{
	while (*st < *en && (ft_strchr(set, s1[*st]) || ft_strchr(set, s1[*en])))
	{
		if (ft_strchr(set, s1[*st]))
			(*st)++;
		if (ft_strchr(set, s1[*en]))
			(*en)--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	en;
	char	*arr;

	if (all_chars_in_set(s1, set))
	{
		arr = malloc(1);
		if (!arr)
			return (NULL);
		arr[0] = '\0';
		return (arr);
	}
	en = ft_strlen(s1);
	st = 0;
	if (en > 0)
		en--;
	strt_end(&st, &en, s1, set);
	arr = ft_substr(s1, st, en - st + 1);
	return (arr);
}
