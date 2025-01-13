/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 09:05:07 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/10 02:08:59 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

	if (!s1)
		return (NULL);
	i = 0;
	len = ft_strlen (s1);
	dup = malloc ((size_t)(len + 1) * sizeof (char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		j;
	char	*dup;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	dup = malloc((size_t)(len1 + len2 + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		dup[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len1 + len2)
		dup[i++] = s2[j++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*d;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	d = malloc ((size_t)(len + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[i] && i != start)
		i++;
	j = 0;
	while (s[i] && j < len)
	{
		d[j] = s[i];
		j++;
		i++;
	}
	d[j] = '\0';
	return (d);
}

void	cleanup(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
