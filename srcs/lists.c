/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:48:53 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/14 23:07:33 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem		*init_list(char *name)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	new->name = ft_strdup(name);
	new->select = 0;
	new->cursor = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		add_front_list(t_elem **alst, t_elem *new, char *name)
{
	t_elem	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = malloc(sizeof(t_elem));
	tmp->next = new;
	new->name = ft_strdup(name);
	new->next = NULL;
	new->select = 0;
	new->cursor = 0;
	new->prev = tmp;
}

void		del_list(t_elem **list)
{
	t_elem *tmp;
	t_elem *lst;

	lst = *list;
	tmp = lst;
	while (lst)
	{
		tmp = *list;
		lst = lst->next;
		free(tmp->name);
		free(tmp);
		tmp = NULL;
	}
}
