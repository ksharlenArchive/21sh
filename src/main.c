/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjonella <tjonella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:55:32 by ksharlen          #+#    #+#             */
/*   Updated: 2020/03/10 23:09:00 by tjonella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_term_var	g_term_lst;

int		main(int argc, char **argv, char **env)
{
	t_init			init;

	(void)(argc);
	(void)(argv);
	(void)(env);

	sh21_init(&init, env);
	while (1)
	{
		input_begin(&init.inp);
		if ((!init.inp.str_for_parse && init.inp.key == ('d' & 0x1f)) ||
				(init.inp.str_for_parse &&
				!ft_strcmp(init.inp.str_for_parse, "exit")))
			break ;
		else if (init.inp.str_for_parse)
			if (!parser(&(init.inp.str_for_parse), &init.prs))
				check_choice(init.execlist, init.prs.beg);
		free_befor_exec(&init.prs);
	}
	input_finish(&init.inp);
	return (0);
}

/*** not to do ***/
// (-) "$> cat -e << EOF >> /tmp/test.txt"
// (-) quote с кавычками должен делать перенос строк, где требуется
// (-) Ctrl+T при последовательности действий: нажатие->стирание->нажатие - падает шелл

/*** complite ***/
// (+) добавить '\n' в echo
// (+) "$> ls;;" - ломает шелл
// (+) "$> ls ; exit " - не завершается шелл
// (+) cd не работает 
// (+) не заполнен интерфейс execlist.exec_envlist.path
// (+) не работают перенаправления потоков
// (+) exit - не возвращает число завершения
// (+) env go-go-go
// (+) " ~ " - не подставляет домашнюю директорию

/*** ned to do ***/
//* (-) Ctrl+C или Ctrl+D при работающих командах, например "ls -lR /", - не работают
//* (-) "$> cat " - не работет обработка сигналов
//* (-) - Run the command "$> cat" then press ctrl+C.
//		  The shell must kill cat's proccess and give back the prompt.
// (-) при вставке новой строки появляется БАГ
// (-) (довести до работоспособности все внутренние команды)

/*** for tests ***/

// int		main(int argc, char **argv, char **env)
// {
// 	t_init			init;

// 	(void)(argc);
// 	(void)(argv);
// 	(void)(env);
// 	sh21_init(&init, env);
// 	init.inp.str_for_parse = ft_strdup("~~");
// 	if (!parser(&(init.inp.str_for_parse), &init.prs))
// 		check_choice(init.execlist, init.prs.beg);
// 	free_befor_exec(&init.prs);
// 	input_finish(&init.inp);
// 	return (0);
// }
