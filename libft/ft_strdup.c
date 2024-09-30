/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:46:39 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/18 13:46:56 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*anotherone;

	anotherone = malloc(ft_strlen(str) + 1);
	if (!anotherone)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		anotherone[i] = str[i];
		i++;
	}
	anotherone[i] = '\0';
	return (anotherone);
}
