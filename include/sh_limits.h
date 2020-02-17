/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_limits.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharlen <ksharlen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 03:16:21 by ksharlen          #+#    #+#             */
/*   Updated: 2020/02/16 20:06:17 by ksharlen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LIMITS_H
# define SH_LIMITS_H

# include <sys/types.h>
# include <limits.h>

# define P_N	"21sh"

# define SH21_MAX_PATH	256
# define SH21_MAX_NAME	256
# define SH21_MAX_ARG	1024

/*
**GREETING
*/
# define SIZE_TIME		8
# define SIZE_NAME		SH21_MAX_NAME
# define SIZE_DIR		SH21_MAX_PATH
# define SKIP_DATE		11
# define COLOR_DFLT		"\e[0m"
# define COLOR_TIME		"\e[34;1m"
# define COLOR_USER		"\e[31;1m"
# define COLOR_DIR		"\e[36;1m"
# define COLOR_YELLOW	"\e[33;1m"

typedef int32_t			t_key;

#endif