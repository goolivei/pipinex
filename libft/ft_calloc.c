/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:24:16 by goolivei          #+#    #+#             */
/*   Updated: 2023/10/18 12:24:35 by goolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*tmae;

	tmae = malloc(nitems * size);
	if (!tmae)
		return (NULL);
	ft_bzero(tmae, nitems * size);
	return (tmae);
}
