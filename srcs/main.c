/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysalaun <ysalaun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:45:14 by ysalaun           #+#    #+#             */
/*   Updated: 2018/02/16 01:12:37 by ysalaun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

struct termios	sigleton(struct termios term)
{
    static struct termios _term;

    if (term.c_cflag)
        _term = term;
    return (_term);
}

t_elem		**siglelist(t_elem **list)
{
    static t_elem *_list;

    if (list)
        _list = *list;
    return (&_list);
}

void			init_term()
{
    char            *term_name;
    struct termios  term;
    struct termios  term_ori;

    if ((term_name = getenv("TERM")) == NULL)
        exit (0);
    if (tgetent(NULL, term_name) == ERR)
        exit (0);
    if (tcgetattr(0, &term) == -1)
        exit (0);
	term_ori = term;
	sigleton(term_ori);
    ft_putstr(tgetstr("cl", NULL));
    ft_putstr(tgetstr("vi", NULL));
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSADRAIN, &term);
}

void            exit_term()
{
    struct termios term;

	ft_bzero(&term, sizeof(struct termios));
    term = sigleton(term);
    ft_putstr(tgetstr("ve", NULL));
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(0, 0, &term);
    exit(0);
}

void        sig_handler(int sig)
{
	t_elem *list;
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	list = *siglelist(NULL);
    if (sig == SIGWINCH)
    {
        ft_putstr(tgetstr("cl", NULL));
		print_list(&list, ws);
    }
    if (sig == SIGTSTP)
    {
    }
    else if (sig == SIGINT || sig == SIGQUIT || sig == SIGKILL || sig == SIGTERM)
        exit_term();
    else
		return ;
}

void        ft_signal()
{
    int     i;

    i = 0;
    while (i < 33)
    {
        signal(i, sig_handler);
        i++;
    }
}

int				main (int argc, char **argv, char **envp)
{
	char			buffer[3];
	t_elem			*alst;
	struct winsize	ws;

    if (argc <= 1)
        return (0);
	(void)envp;
	init_term();
	alst = parsing(argc, argv);
	ft_signal();
	siglelist(&alst);
    while (1)
    {
		ioctl(0, TIOCGWINSZ, &ws);
        print_list(&alst, ws);
        ft_bzero(buffer, 4);
        if (read(0, buffer, 3) == -1)
            exit_term();
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
            witch_arrow(buffer, &alst);
        else if (buffer[0] == 4 || buffer[0] == 15)
            exit_term();
        else if (buffer[0] == 32 && buffer[1] == 0 && buffer[2] == 0)
        {
            choose(&alst);
            moove_curs_right(&alst);
        }
        else if (buffer[0] == 10 && buffer[1] == 0 && buffer[2] == 0)
            return_elem(&alst);
        else
            ;
    }
    return (0);
}