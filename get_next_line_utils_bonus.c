/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:16:30 by madorna-          #+#    #+#             */
/*   Updated: 2020/08/10 18:47:25 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	size_t	h;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	i = 0;
	h = -1;
	if (!(str = malloc(sizeof(char) * (s1_size + s2_size + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[++h] != '\0')
		str[i + h] = s2[h];
	str[i + h] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*subst;
	size_t		maxl;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	maxl = ft_strlen(s);
	if (start >= maxl)
		return (ft_strdup(""));
	if (!(subst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i] != '\0')
	{
		subst[j] = s[i];
		j++;
		i++;
	}
	subst[j] = '\0';
	return (subst);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	void	*mal;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	if (!(mal = malloc(i + 1)))
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		((char *)mal)[i] = s1[i];
		i++;
	}
	((char *)mal)[i] = '\0';
	return (void *)mal;
}

char		*ft_strchr(const char *s, int c)
{
	char *string;

	string = (char *)s;
	while (*string != c)
	{
		if (*string == '\0')
		{
			return (NULL);
		}
		string++;
	}
	return (string);
}
