/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:10:02 by ryaoi             #+#    #+#             */
/*   Updated: 2016/12/12 13:22:31 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef	struct	s_pf
{
	char		specifer;
	int			flag_diese;
	int			flag_space;
	int			flag_minus;
	int			flag_plus;
	int			flag_zero;
	int			flag_dot;
	int			width;
	int			precision;
	int			ret;
	int			skip;
	char		*result;
	char		*length;
}				t_pf;

void			select_specifer(t_pf **pf, va_list ap);
int				ft_printf(const char *format, ...);
int				match_specifer(const char *p, t_pf **pf);
int				match_specifer_2(const char *p, t_pf **pf);
int				check_length(const char *p, t_pf **pf);
int				check_precision(const char *p, t_pf **pf);
int				check_width(const char *p, t_pf **pf);
int				match_flag(const char *p, t_pf **pf);
void			ft_printf_s(t_pf **pf, va_list ap);
void			ft_printf_caps(t_pf **pf, va_list ap);
void			ft_printf_p(t_pf **pf, va_list ap);
void			ft_printf_d(t_pf **pf, va_list ap);
void			ft_printf_capd(t_pf **pf, va_list ap);
void			ft_printf_i(t_pf **pf, va_list ap);
void			ft_printf_o(t_pf **pf, va_list ap);
void			ft_printf_capo(t_pf **pf, va_list ap);
void			ft_printf_u(t_pf **pf, va_list ap);
void			ft_printf_capu(t_pf **pf, va_list ap);
void			ft_printf_x(t_pf **pf, va_list ap);
void			ft_printf_capx(t_pf **pf, va_list ap);
void			ft_printf_c(t_pf **pf, va_list ap);
void			ft_printf_capc(t_pf **pf, va_list ap);
void			ft_printf_pourcent(t_pf **pf);
void			s_strcopy(t_pf **pf, char *str, size_t n);
t_pf			*init_pf(void);
void			ft_length_ll(t_pf **pf, long long nbr, int base);
void			ft_length_ull(t_pf **pf, unsigned long long nbr, int base);
char			*ft_lltoa_base(long long nbr, int base);
char			*ft_ulltoa_base(unsigned long long nbr, int base);
char			*ft_ltoa_base(long nbr, int base);
char			*ft_ultoa_base(unsigned long nbr, int base);
char			*ft_hhtoa_base(char nbr, int base);
char			*ft_uhhtoa_base(unsigned char nbr, int base);
char			*ft_htoa_base(short nbr, int base);
char			*ft_uhtoa_base(unsigned short nbr, int base);
char			*ft_itoa_base(int nbr, int base);
char			*ft_uitoa_base(unsigned int nbr, int base);
int				ft_count_digit_base(long long nbr, int base);
int				ft_ucount_digit_base(unsigned long long nbr, int base);
void			add_prefix_oct(t_pf **pf);
void			add_prefix_hex(t_pf **pf);
void			ft_str_capitalize(char **str);
int				ft_wcharlen(wchar_t c);
void			ft_printf_unicode(wchar_t c, size_t size);
void			ft_printf_str_unicode(wchar_t *str, int lim);
int				ft_wstrlen(wchar_t *str);
void			ft_bzero(void *s, size_t len);
void			*ft_memset(void *b, int c, size_t n);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_toupper(int c);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_memdel(void **ap);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strcat(char *s1, const char *s2);
void			ft_stradjust(t_pf **pf);
void			ft_check_hex(t_pf **pf);
void			ft_check_oct(t_pf **pf);
void			ft_put_space(t_pf **pf, long long nbr);
void			ft_check_dec(t_pf **pf);
int				only_pourcent(const char *format);
long long		select_length_d(t_pf **pf, va_list ap);
void			select_specifer_two(t_pf **pf, va_list ap);
int				ft_digit(long long nbr, int base);
int				ft_case_plus(t_pf **pf);
void			ft_d_final_check(t_pf **pf, long long nbr);
int				first_check_s(t_pf **pf, char **str, va_list ap);
void			add_prefix_oct_add(t_pf **pf);
void			add_prefix_hex_add(t_pf **pf);

#endif
