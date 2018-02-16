/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:07:39 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/12 14:37:27 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_double_tab(char **my_tab)
{
	int i;
	int j;

	i = 0;
	while (my_tab[i])
	{
		j = 0;
		while (my_tab[i][j])
		{
			ft_putchar(my_tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
