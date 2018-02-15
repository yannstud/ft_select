/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:50:39 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/15 02:00:06 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				init_terminal_data ()
{
	static char	term_buffer[2048];
	char		*termtype = getenv ("TERM");
	int			success;

	if (termtype == 0)
		ft_putstr_fd("Specify a terminal type with `setenv TERM <yourtype>'.\n", 2);
		return (1);
	success = tgetent (term_buffer, termtype);
	if (success < 0)
	{
		ft_putstr_fd("Could not access the termcap data base.\n", 2);
		return (0);
	}
	if (success == 0)
	{
		ft_putstr_fd("Terminal type is not defined.\n", 2);
		return (0);
	}
	return (2);
}

struct termios	*sigleton(struct termios *term)
{
	static struct termios *_term;

	if (term)
		_term = term;
	return (_term);
}

void		init_term()
{
	char			*term_name;
	struct termios	term;
	if ((term_name = getenv("TERM")) == NULL)
		exit (0);
	if (tgetent(NULL, term_name) == ERR)
		exit (0);
	if (tcgetattr(0, &term) == -1)
		exit (0);
	sigleton(&term);
	ft_putstr(tgetstr("cl", NULL));
	ft_putstr(tgetstr("vi", NULL));
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
}

void			exit_term()
{
	struct termios *term;
	
	term = sigleton(NULL);
	ft_putstr(tgetstr("ve", NULL));
	term->c_lflag = (ICANON | ECHO);
	tcsetattr(0, TCSADRAIN, term);
	exit(0);
}
void				sig_handler(int a)
{
	if (a == SIGINT || a == SIGKILL || a == SIGSTOP)
	{
		printf("\nsigint recu\n");
		sleep(1);
		exit_term();
	}
}
void	size_window(t_elem **list)
{
	struct winsize	ws;
	t_elem			*tmp;
	int				i;
	int				count;

	count = 0;
	ioctl(0, TIOCGWINSZ, &ws);
	tmp = *list;
	while (tmp)
	{
		i = 0;
		while (tmp->name[i])
			i++;
		count = count + i + 4;
		tmp = tmp->next;
	}
	printf("\ncount ==> %d\n", count);
	printf("col ==> %d\n", ws.ws_col);
	printf("row ==> %d\n", ws.ws_row);
}
int				main (int argc, char **argv, char **env)
{
	char buffer[3];
	int i;
	t_elem	*list = NULL;
	t_elem *list2 = NULL;
	if (argc <= 1)
		return (0);
	(void)env;
	if (init_terminal_data() == 0)
		return (0);
	init_term();
	list = init_list(argv[1]);
	i = 1;
	while (++i < argc)
		add_front_list(&list, list2, argv[i]);
	while (1)
	{
		print_list(&list);
		size_window(&list);
		ft_bzero(buffer, 4);
		if (read(0, buffer, 3) == -1)
			exit_term();
		signal(SIGINT, sig_handler);
		// ft_putchar('\n');
		// ft_putnbr(buffer[0]);
		// ft_putchar('\n');
		// ft_putnbr(buffer[1]);
		// ft_putchar('\n');
		// ft_putnbr(buffer[2]);
		// ft_putchar('\n');
		// sleep(1);
		ft_putstr(tgetstr("cl", NULL));
		if (buffer[0] == 27)
			witch_arrow(buffer, &list);
		else if (buffer[0] == 4 || buffer[0] == 15)
			exit_term();
		else if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
		{
			choose(&list);
			moove_curs_right(&list);
		}
		else if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
			return_elem(&list);
		else
			;
	}
	return (0);
}