/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:00:22 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/16 01:47:01 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			return_elem(t_elem **list)
{
	t_elem  *tmp;
	int	 i;
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
	exit_term();
}

int			 calc_term_larg(t_elem **list, struct winsize ws)
{
	int		i;
	t_elem	*tmp;
	int		count;

	tmp = *list;
	i = 0;
	count = 0;
	while (tmp)
	{
		i = i + ft_strlen(tmp->name) + 5;
		count++;
		if (ft_strlen(tmp->name) + 5 > ws.ws_col)
		{
			ft_putstr("i am too small");
			return (-1);
		}
		if (i > ws.ws_col)
			return (count);
	}
	return (1);
}

void			print_list(t_elem **alst, struct winsize ws)
{
	t_elem  *tmp;
	int i = 0;

	tmp = *alst;
	while (tmp)
	{
		i++;
		if (calc_term_larg(alst, ws) == -1)
			return ;
		else if (i == calc_term_larg(alst, ws))
		{
			ft_putchar('\n');
			i = 0;
		}
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