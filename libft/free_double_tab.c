/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 23:27:35 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/12 14:37:48 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_double_tab(char **my_tab)
{
	int i;

	i = 0;
	while (my_tab[i])
	{
		ft_memdel((void **)(&my_tab[i]));
		i++;
	}
	ft_memdel((void **)(&my_tab));
}
