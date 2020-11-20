NAME = libftprintf.a

SRCDIR = src/

FROMLIBFTDIR = $(SRCDIR)from_libft/

FTSTDLIBDIR = $(FROMLIBFTDIR)ft_stdlib/

FTSTRINGDIR = $(FROMLIBFTDIR)ft_string/

TAKESPECLSTDIR = $(SRCDIR)take_spec_lst/

SPECLSTSDIR =  $(TAKESPECLSTDIR)spec_lst/

TAKEFLAGSDIR = $(TAKESPECLSTDIR)take_flags/

TAKESPECDIR = $(TAKESPECLSTDIR)take_spec/


TAKEARGS = $(TAKESPECLSTDIR)take_args/

TAKERESULTSTRDIR = $(SRCDIR)take_result_str/

SRC = $(SRCDIR)ft_printf.c\
	  $(FTSTDLIBDIR)ft_prf_atoi.c\
	  $(FTSTDLIBDIR)ft_prf_itoa.c\
	  $(FTSTDLIBDIR)ft_prf_uitoa.c\
	  $(FTSTDLIBDIR)ft_prf_uitoa_base.c\
	  $(FTSTRINGDIR)ft_prf_memcmp.c\
	  $(FTSTRINGDIR)ft_prf_strlen.c\
	  $(FTSTRINGDIR)ft_prf_strjoin.c\
	  $(TAKESPECLSTDIR)take_spec_lst.c\
	  $(SPECLSTSDIR)spec_lst_create.c\
	  $(SPECLSTSDIR)spec_lst_add_back.c\
	  $(SPECLSTSDIR)spec_lst_clear.c\
	  $(TAKEFLAGSDIR)take_flags.c\
	  $(TAKESPECDIR)take_spec.c\
	  $(TAKEARGS)take_args.c\
	  $(TAKEARGS)take_arg_c.c\
	  $(TAKEARGS)take_arg_s.c\
	  $(TAKEARGS)take_arg_p.c\
	  $(TAKEARGS)take_arg_d.c\
	  $(TAKEARGS)take_arg_u.c\
	  $(TAKEARGS)take_arg_x.c\
	  $(TAKEARGS)take_arg_upx.c\
	  $(TAKERESULTSTRDIR)take_result_str.c\

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLD = includes/

.c.o:
	@$(CC) $(CFLAGS) -I$(INCLD) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all:	$(NAME) 

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re:	fclean	all
