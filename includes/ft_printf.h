/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:40:00 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/18 11:54:52 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# define HEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

int							ft_printf(const char *s, ...);

typedef struct				s_flags_info
{
	char					minus;
	char					zero;
	int						width;
	int						precision;
}							t_flags_info;

typedef struct				s_spec_info
{
	char					spec;
	char					*spec_ptr;
	t_flags_info			flags;
	char					*arg;
	int						arg_len;
	int						all_len;
	struct s_spec_info		*next;
}							t_spec_info;

typedef struct				s_result_str
{
	char					*str;
	size_t					str_len;
}							t_result_str;

int							ft_prf_memcmp(const void *s1, const void *s2,
size_t n);
int							ft_prf_atoi(const char *str);
char						*ft_prf_itoa(int64_t n);
char						*ft_prf_uitoa(uint32_t n);
char						*ft_prf_uitoa_base(uint64_t nb, char *base);
size_t						ft_prf_strlen(const char *s);
char						*ft_prf_strjoin(char const *s1, char const *s2);
t_spec_info					*take_spec_lst(const char *s, va_list factor);
t_spec_info					*spec_lst_create(void);
t_spec_info					*spec_lst_add_back(t_spec_info **begin_lst,
char *spec_position);
t_spec_info					*spec_lst_clear(t_spec_info **begin_lst);
int							check_valid_spec_lst(t_spec_info *begin_lst);
void						take_flags(char *s, t_spec_info *lst,
va_list factor);
int							is_flag(char c);
char						*take_spec(char *s, t_spec_info *lst);
int							take_args(t_spec_info *lst, va_list factor);
int							is_spec(char c);
int							take_arg_c(t_spec_info *lst, va_list factor,
char c);
int							take_arg_s(t_spec_info *lst, va_list factor);
char						*take_null_s(void);
int							apply_width_s(t_spec_info *lst);
void						apply_minus_s(t_spec_info *lst);
void						apply_zero_s(t_spec_info *lst);
int							take_arg_p(t_spec_info *lst, va_list factor);
int							take_arg_d(t_spec_info *lst, va_list factor);
int							apply_precision_d(t_spec_info *lst);
int							take_arg_u(t_spec_info *lst, va_list factor);
int							take_arg_x(t_spec_info *lst, va_list factor);
int							take_arg_upx(t_spec_info *lst, va_list factor);
int							take_res_s(const char *s, t_result_str *res_s,
t_spec_info *lst);

#endif
