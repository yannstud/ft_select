/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:45:57 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/15 22:08:39 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT
# define FT_SELECT
# include "../libft/libft.h"
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>
# include <signal.h>
# define RED "\033[1;31m"
# define NORMAL "\033[0m"

typedef struct		s_elem
{
	int				cursor;
	int				select;
	char			*name;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

t_elem				*parsing(int argc, char **argv);
void				print_list(t_elem **alst, struct winsize ws);
void				del_list(t_elem **list);
void				add_front_list(t_elem **alst, t_elem *new, char *name);
t_elem				*init_list(char *name);
void				print_end(char **my_tab, int i);
void				return_elem(t_elem **list);
void				del_choice(t_elem **list);
void				moove_curs_right(t_elem **list);
void				moove_curs_left(t_elem **list);
void				choose(t_elem **list);
void				witch_arrow(char *buff, t_elem **list);
void				exit_term();

#endif