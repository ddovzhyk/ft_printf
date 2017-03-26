#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

typedef struct	s_print
{
	short 		apostrophe;
	short 		hyphen;
	short 		plus;
	short 		space;
	short 		hash;
	short 		zero;
	char		*size;
	int			prec;
	int			width;
	int 		byte;
}				t_print;

int				ft_printf(const char *format, ...);

void			clear_struct(t_print *pr);
void			check_modificator(char **str, va_list f, t_print *print);
void			check_spec_char(char **str, va_list f, t_print *print);
void			specif(va_list f, char *sp, t_print *pr);
void			length(char *tmp, char **size);
void			flag(char tmp, t_print *pr);
void			add_zeros_nbr(char **num, t_print *pr);
void			add_width_str(char **str, t_print pr, size_t len);
void			flag_apostrophe(char **num);
void			flag_hash(char **num, char sp);

void			specif_di_ld(va_list f, t_print *pr, char sp);
void			specif_uoxb_luoxb(va_list f, char sp, t_print *pr);
void			specif_c_lc(va_list f, t_print *pr, char *sp);
void			specif_s(va_list f, t_print *pr);
void			specif_ls(va_list f, t_print *pr, int i);
void			specif_n(va_list f, t_print pr);
void			specif_p(va_list f, t_print *pr);

short			size_char(int c);
void			put_wchar(int c, short size);
void			put_wstr(int *str, int n);
int				*wstr_null(char *str, short *flag);
int				check_l_for_cs(char *s);
unsigned int	ft_atou(char **str);
char			*toa_base(uintmax_t value, short base, char *tmp, int negative);
int				num_is_zero(char *num);
int				is_specif(char c);
int				is_length(char c);
int				is_flag(char c);

#endif