NAME = ft_printf

SRCDIR = src/

FORTEST = $(SRCDIR)for_test/

FROMLIBFTDIR = $(SRCDIR)from_libft/

FTSTDLIBDIR = $(FROMLIBFTDIR)ft_stdlib/

FTSTRINGDIR = $(FROMLIBFTDIR)ft_string/

TAKESPECLSTDIR = $(SRCDIR)take_spec_lst/

SPECLSTSDIR =  $(TAKESPECLSTDIR)spec_lst/

TAKEFLAGSDIR = $(TAKESPECLSTDIR)take_flags/

TAKESPECDIR = $(TAKESPECLSTDIR)take_spec/

CHECKERROR = $(SRCDIR)check_errors/

CHECKVALIDSPECLST = $(CHECKERROR)check_valid_spec_lst/

TAKEARGS = $(TAKESPECLSTDIR)take_args/


SRC = $(SRCDIR)main.c\
	  $(SRCDIR)ft_printf.c\
	  $(FORTEST)print_spec_lst.c\
	  $(FORTEST)basic_test_arg_c.c\
	  $(FORTEST)basic_test_arg_s.c\
	  $(FORTEST)basic_test_arg_p.c\
	  $(FORTEST)print_arg_lst.c\
	  $(FTSTDLIBDIR)ft_prf_atoi.c\
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
	  $(CHECKVALIDSPECLST)check_valid_spec_lst.c\
	  $(TAKEARGS)take_args.c\
	  $(TAKEARGS)take_arg_c.c\
	  $(TAKEARGS)take_arg_s.c\
	  $(TAKEARGS)take_arg_p.c

OBJ = $(SRC:.c=.o)

LIBDIR = libft/

LIB = ft

#SRCDIR_BONUS = src_bonus/
#SRC_BONUS =

#OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -L$(LIBDIR) -l$(LIB)
INCLD = includes/

.c.o:
	$(CC) -I$(INCLD) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
	#make -C libft
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME) 

#bonus:		$(NAME) $(OBJ_BONUS)
#	ar rc $(NAME) $(OBJ) $(OBJ_BONUS)
#	ranlib $(NAME)

clean:
	#make fclean -C libft
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean	all
