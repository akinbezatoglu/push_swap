/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 20:23:05 by abezatog          #+#    #+#             */
/*   Updated: 2026/08/17 15:39:40 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_alloc_word(char const *s, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	*ft_free_all_and_exit(char **strs, size_t count)
{
	while (count)
	{
		count--;
		free(strs[count]);
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;

	if (!s)
		return (NULL);
	strs = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			strs[i] = ft_alloc_word(s, c);
			if (!strs[i])
				return (ft_free_all_and_exit(strs, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	strs[i] = NULL;
	return (strs);
}
