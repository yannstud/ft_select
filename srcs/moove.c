/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 10:50:28 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/14 23:07:38 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		moove_curs_right(t_elem **list)
{
	t_elem *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->next && tmp->cursor == 1)
		{
			tmp->cursor = 0;
			tmp = tmp->next;
			tmp->cursor = 1;
			return ;
		}
		else if (!tmp->next && tmp->cursor == 1)
		{
			tmp->cursor = 0;
			tmp = *list;
			tmp->cursor = 1;
			return ;
		}
		else
			tmp = tmp->next;
	}
}

void		moove_curs_left(t_elem **list)
{
	t_elem *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->prev && tmp->cursor == 1)
		{
			tmp->cursor = 0;
			tmp = tmp->prev;
			tmp->cursor = 1;
			return ;
		}
		else if (!tmp->prev && tmp->cursor == 1)
		{
			tmp->cursor = 0;
			while (tmp->next)
				tmp = tmp->next;
			tmp->cursor = 1;
			return ;
		}
		else
			tmp = tmp->next;
	}
}

void		witch_arrow(char *buff, t_elem **list)
{
	if (buff[2] == 'D')
		moove_curs_left(list);
	else if (buff[2] == 'C')
		moove_curs_right(list);
	else if (buff[2] == 51)
		del_choice(list);
}

void		del_choice(t_elem **list)
{
	t_elem *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->cursor == 1)
			if (tmp->select == 1)
				tmp->select = 0;
		tmp = tmp->next;
	}
}

void		choose(t_elem **list)
{
	t_elem *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			if (tmp->select == 0)
			{
				tmp->select = 1;
				return ;
			}
			else if (tmp->select == 1)
			{
				tmp->select = 0;
				return ;
			}
		}
		tmp = tmp->next;
	}
}
