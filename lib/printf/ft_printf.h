/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:14:22 by antonimo          #+#    #+#             */
/*   Updated: 2024/05/14 16:16:11 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

int		ft_putchar_pf(int c);
int		ft_putstr_pf(char *str);
int		ft_putptr_pf(va_list args);
int		ft_putnbr_pf(int number, int *count);
int		ft_putunsnbr_pf(unsigned int number);
int		ft_hex_pf(unsigned int number, char x_or_X, int *count);
int		ft_aux_pf(char const *format, int *i, va_list args);
int		ft_printf(char const *format, ...);

#endif