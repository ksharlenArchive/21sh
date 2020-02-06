/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_additional_modes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:03:00 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 20:33:04 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parse_key.h"

void	input_additional_modes(struct s_input *inp)
{
	if (inp->str_for_parse)
		input_quote_mode(inp);
	// cmd = gap_get_buf(&inp->gap);
}
