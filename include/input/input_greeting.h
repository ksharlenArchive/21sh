/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_greeting.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 02:55:57 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/06 19:16:15 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_GREETING_H
# define INPUT_GREETING_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# include "libft.h"
# include "21sh_struct.h"
# include "input_macros.h"

# define CLEAN	ft_bzero
# define QUOTE_GREET_STR	"quote> "

int			input_greeting(const struct s_user_info *u_info);
int			input_quote_greet(const struct s_user_info *u_info);

#endif