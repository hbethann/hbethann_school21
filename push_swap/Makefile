NAME	=	push_swap
NAME_B	=	checker
SRCS	=	push_swap.c		add_stack.c		big_sort.c		ft_check.c\
			init_stack.c	med_sort.c		minisort.c		optimus.c\
			push_cmd.c		rev_rot.c 		rotate.c		swap.c
SRCS_B	=	checker.c		add_stack.c		big_sort.c		ft_check.c\
			init_stack.c	med_sort.c		minisort.c		optimus.c\
			push_cmd.c		rev_rot.c 		rotate.c		swap.c\
OBJ		=	$(patsubst %.c, %.o, $(SRCS))
OBJ_S	=	$(patsubst %.c, %.o, $(SRCS_B))
LIB		=	libft/libft.a
HEADER	=	push_swap.h
CC		=	cc
FLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf
.PHONY:		all		clean	fclean	re	bonus	libft

all:	libft	$(NAME)

libft:
		@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS $(OBJ) $(LIB) -o $(NAME)

%.o:	%.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@
		

bonus:	libft $(OBJ_B)
		$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B) 

clean:
		@$(RM) $(OBJ) $(OBJ_B)
		@$(MAKE) -C libft/ clean

fclean:	clean
		@$(MAKE) -C libft/ fclean
		@$(RM) $(NAME) $(NAME_B)

re:		fclean all