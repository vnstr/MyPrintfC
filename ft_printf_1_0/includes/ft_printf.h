/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <gdrive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:40:00 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/15 19:18:00 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# define HEX "0123456789abcdef"

int			ft_printf(const char *s, ...);

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

int			ft_prf_memcmp(const void *s1, const void *s2, size_t n);
int			ft_prf_atoi(const char *str);
char		*ft_prf_uitoa_base(uint64_t nb, char *base);
size_t		ft_prf_strlen(const char *s);
char		*ft_prf_strjoin(char const *s1, char const *s2);
t_spec_info	*take_spec_lst(const char *s, va_list factor);
t_spec_info	*spec_lst_create(void);
t_spec_info	*spec_lst_add_back(t_spec_info **begin_lst, char *spec_position);
t_spec_info *spec_lst_clear(t_spec_info **begin_lst);
int			check_valid_spec_lst(t_spec_info *begin_lst);
void		take_flags(char *s, t_spec_info *lst, va_list factor);
int			is_flag(char c);
char		*take_spec(char *s, t_spec_info *lst);
int			take_args(t_spec_info *lst, va_list factor);
int			take_arg_c(t_spec_info *lst, va_list factor);
int			take_arg_s(t_spec_info *lst, va_list factor);
int			apply_width_s(t_spec_info *lst);
int			apply_precision_s(t_spec_info *lst);
void		apply_minus_s(t_spec_info *lst);
void		apply_zero_s(t_spec_info *lst);
int			take_arg_p(t_spec_info *lst, va_list factor);




/*
 * Для ТЕСТОВ
 */

void		print_spec_lst(t_spec_info *begin);
void		print_arg_lst(t_spec_info *begin_lst);

void		basic_test_arg_c(void);
void		basic_test_arg_s(void);

#endif
