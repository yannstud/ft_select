/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:35:29 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/12 17:06:06 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_list(t_list **alst)
{
	t_list *tmp;

	tmp = *alst;
	if (tmp == NULL)
		ft_putstr("No list");
	while (tmp != NULL)
	{
		ft_putstr((char*)tmp->content);
		ft_putchar('\n');
		ft_putnbr(tmp->content_size);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
