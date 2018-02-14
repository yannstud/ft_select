/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:48:34 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/14 16:52:38 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# define RED "\033[1;31m"
# define NORMAL "\033[0m"

typedef struct		s_elem
{
	char			*name;
	int				cursor;
	int				select;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

void				init_term();
t_elem				*init_list(char *name);
void				add_front_list(t_elem **alst, t_elem *new, char *name);
void				print_list(t_elem **alst);
void				del_list(t_elem **list);
void				moove_curs_right(t_elem **list);
void				moove_curs_left(t_elem **list);
void				witch_arrow(char *buff, t_elem **list);
void				choose(t_elem **list);
void				print_end(char **my_tab, int i);
void				return_elem(t_elem **list);
void				my_clear();
void				exit_term();
void				del_choice(t_elem **list);

#endif
