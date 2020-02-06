/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:11:15 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 21:16:24 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

#define IS_QT(sym) ((sym) == '\'' || (sym) == '\"' || (sym) == '`')

static void	put_in_stack_quote_from_str(const char *str, t_queue *qu)
{
	while (*str)
	{
		if (IS_QT(*str))
			ft_qu_push(qu, (void *)str, sizeof(char));
		++str;
	}
}

static void	quote_init(struct s_input *inp)
{
	gap_clean_buf(&inp->gap);
	inp->save_refresh_pos = get_pos_cursor();
	--inp->save_refresh_pos.y;
	inp->save_refresh_pos.x = inp->len_greet;
	inp->cr = inp->save_refresh_pos;
	inp->key = 0;
}

static char	line_form(struct s_input *inp, char search_qt, char *src_str)
{
	char		*str;
	char		close_qt;
	t_queue		qu;

	ft_qu_init(&qu);
	ft_qu_push(&qu, &search_qt, sizeof(char));
	str = gap_get_buf(&inp->gap);
	put_in_stack_quote_from_str(str, &qu);
	inp->str_for_parse = ft_strreplace(src_str, str);
	close_qt = search_double_quotes(&qu);
	return (close_qt);
}

static void	quote_mode(struct s_input *inp, char search_qt, char *src_str)
{
	char	close_qt;

	quote_init(inp);
	inp->greet(&inp->u_info);
	while (inp->key != KEY_NEW_LINE)
	{
		inp->key = input_getch();
		if (inp->key == CTR_KEY('c'))
		{
			clean_struct_input(inp);
			input_put_new_line(inp);
			return ;
		}
		input_process_key_press(inp);
	}
	input_put_new_line(inp);
	close_qt = line_form(inp, search_qt, src_str);
	if (close_qt != TRUE)
		quote_mode(inp, close_qt, inp->str_for_parse);
}

void		input_quote_mode(struct s_input *inp)
{
	t_queue	qu;
	int		quote_close;

	ft_qu_init(&qu);
	put_in_stack_quote_from_str(inp->str_for_parse, &qu);
	quote_close = search_double_quotes(&qu);
	if (quote_close != TRUE)
	{
		inp->greet = input_quote_greet;
		inp->len_greet = ft_strlen(QUOTE_GREET_STR);
		quote_mode(inp, quote_close, inp->str_for_parse);
	}
}
