/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenzaid <tbenzaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 04:36:01 by tbenzaid          #+#    #+#             */
/*   Updated: 2025/01/07 10:51:57 by tbenzaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	*malloc_words(char *s, char c)
{
	int		i;
	char	*world;

	i = 0;
	world = 0;
	while (s[i] && s[i] != c)
		i++;
	world = malloc ((i + 1) * sizeof(char));
	if (!world)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		world[i] = s[i];
		i++;
	}
	world[i] = '\0';
	return (world);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

char	**creat_malloc(char const *s, char c)
{
	int		i;
	char	**r;
	int		j;

	j = 0;
	i = 0;
	r = malloc ((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			r[j] = malloc_words ((char *)s + i, c);
			if (!r[j])
				return (free_split (r), NULL);
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	r[j] = NULL;
	return (r);
}

char	**ft_split(char *s, char c)
{
	if (!s)
		return (NULL);
	return (creat_malloc (s, c));
}
