/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmita <mmita@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:35:55 by mmita             #+#    #+#             */
/*   Updated: 2023/08/02 19:45:14 by mmita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*src;

	i = 0;
	if (start >= ft_strlen(s))
	{
		src = (char *)malloc(sizeof(*s));
		*src = 0;
		return (src);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	src = (char *)malloc(sizeof(*s) * (len + 1));
	if (!src)
		return (NULL);
	while (s[start + i] && i < len)
	{
		src[i] = s[start + i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

size_t	ft_count_word(const char *str, char c)
{
	size_t	i;
	size_t	trigger;

	i = 0;
	trigger = 0;
	while (str[i] != '\0')
	{
		if (str[i++] != c && (str[i] == c || str[i] == '\0'))
			trigger++;
	}
	return (trigger);
}

char	**ft_split(char const *s, char c)
{
	size_t	len;
	size_t	n;
	char	**split;

	split = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			split[n++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	split[n] = 0;
	return (split);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}
