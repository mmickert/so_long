/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:04:20 by mickert           #+#    #+#             */
/*   Updated: 2024/01/02 11:45:16 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*ptr;

// 	ptr = malloc(count * size);
// 	if (ptr == NULL)
// 		return (NULL);
// 	ft_bzero(ptr, size * count);
// 	return (ptr);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	strlen;
	char			*star;
	size_t			i;

	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup_gnl("\0"));
	if (strlen - start < len)
		len = strlen - start;
	star = (char *)ft_calloc((len + 1), sizeof(char));
	if (star == NULL)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		star[i] = s[start + i];
		i++;
	}
	star[i] = '\0';
	return (star);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*joinedstr;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (!s1 || !s2)
		return (s2);
	joinedstr = (char *)ft_calloc((s1len + s2len + 1), sizeof(char));
	if (joinedstr == NULL)
		return (free(joinedstr), NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		joinedstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		joinedstr[i++] = s2[j++];
	return (joinedstr[i] = 0, joinedstr);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = (char *)ft_calloc((i + 1), sizeof(char));
	if (dest == NULL)
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
