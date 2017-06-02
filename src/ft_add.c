/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oseng <oseng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 13:26:38 by oseng             #+#    #+#             */
/*   Updated: 2016/07/07 13:33:21 by oseng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*add_link(t_list *list, char *str)
{
	t_list	*tmp;

	tmp = (t_list*)ft_memmalloc(sizeof(t_list));
	if (tmp)
	{
		tmp->data = str;
		tmp->next = list;
	}
	return(tmp);
}
