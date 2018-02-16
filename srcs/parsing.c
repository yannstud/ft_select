/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:03:39 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/15 20:53:46 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_elem		*parsing(int argc, char **argv)
{
	int		i;
	t_elem	*alst;
	t_elem	*new = NULL;

	i = 2;
	if (argc == 1)
	{
		ft_putchar('\n');
		return (NULL);
	}
	alst = init_list(argv[1]);
	while (argv[i])
	{
		add_front_list(&alst, new, argv[i]);
		i++;
	}
	return (alst);
}