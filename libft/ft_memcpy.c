/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:02:53 by lnieto-m          #+#    #+#             */
/*   Updated: 2015/12/08 13:24:27 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = str1;
	s2 = str2;
	while (n--)
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	return (str1);
}
