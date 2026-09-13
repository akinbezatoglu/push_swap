/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 14:07:41 by abezatog          #+#    #+#             */
/*   Updated: 2026/09/14 00:46:11 by abezatog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	char	type;
	int		minus;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	int		width;
}	t_flags;

int			ft_printf(const char *format, ...);

void		ft_putnstr(char *s, int n, int *len);
t_flags		*ft_flags_new(void);
const char	*ft_flags_parse(const char *format, t_flags *flags);
void		ft_flags_override(t_flags *flags);
void		ft_flags_print_char(char c, t_flags *f, int *len);
void		ft_flags_print_str(char *s, t_flags *f, int *len);
void		ft_flags_print_nbr(int n, t_flags *f, int *len);
void		ft_flags_print_nbr_u(unsigned int n, t_flags *f, int *len);
void		ft_flags_print_ptr(void *ptr, t_flags *f, int *len);
void		ft_flags_print_hex(unsigned int n, t_flags *f, int *len, char x);
void		ft_put_padding(char c, int strlen, int *len);
int			ft_count_digit(int n);
int			ft_count_digit_u(unsigned int n, int base);

void		ft_putchar(int c, int *len);
void		ft_putstr(char *s, int *len);
void		ft_putnbr(int n, int *len);
void		ft_putnbr_unsigned(unsigned int n, int *len);
void		ft_putptr(void *ptr, int *len);
void		ft_puthex(unsigned long n, int *len, char format);

#endif