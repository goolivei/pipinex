/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:42:49 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/20 14:42:51 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	imlc;
	int	strsize;

	imlc = 0;
	strsize = 0;
	while (s[imlc])
	{
		while (s[imlc] == c)
			imlc++;
		if (s[imlc])
		{
			strsize++;
			while (s[imlc] && s[imlc] != c)
			{
				imlc++;
			}
		}
	}
	return (strsize);
}

char	**ft_clean(char **array, int imlc)
{
	if (!array[imlc])
	{
		while (imlc >= 0)
		{
			free(array[imlc]);
			imlc--;
		}
		free(array);
	}
	return (NULL);
}

int	ft_sj(char const *s, char c, int j)
{
	while (s[j] == c)
		j++;
	return (j);
}

int	ft_si(char const *s, char c, int j, int i)
{
	while (s[j + i] != c && s[j + i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		imlc;
	int		j;
	int		i;

	imlc = 0;
	rtn = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!rtn)
		return (NULL);
	j = 0;
	while (s[j])
	{
		j = ft_sj(s, c, j);
		i = 0;
		i = ft_si(s, c, j, i);
		if (i > 0)
		{
			rtn[imlc] = ft_substr(s, j, i);
			if (!rtn[imlc])
				return (ft_clean(rtn, imlc));
			imlc++;
		}
		j += i;
	}
	return (rtn);
}
