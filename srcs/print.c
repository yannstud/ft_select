/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:53:52 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/15 01:49:28 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			return_elem(t_elem **list)
{
	t_elem	*tmp;
	int		i;
	char	**my_tab;

	i = 0;
	tmp = *list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	tmp = *list;
	my_tab = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tmp)
	{
		if (tmp->select == 1)
			my_tab[i++] = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	print_end(my_tab, i);
	exit_term();
}

void			print_end(char **my_tab, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		ft_putstr(my_tab[j]);
		j++;
		if (j < i)
			ft_putchar(' ');
	}
	if (j > 0)
		ft_putchar('\n');
}

void			print_list(t_elem **alst)
{
	t_elem	*tmp;

	tmp = *alst;
	while (tmp)
	{
		if (tmp->select == 1)
			ft_putstr("\033[41;30m");
		else
			ft_putstr(RED);
		ft_putchar('[');
		if (tmp->cursor == 1)
		{
			ft_putstr("\033[4m");
			ft_putchar('>');
		}
		else if (tmp->cursor != 1)
			ft_putchar(' ');
		ft_putstr(tmp->name);
		ft_putstr(" ]");
		ft_putstr(NORMAL);
		tmp = tmp->next;
	}
}

