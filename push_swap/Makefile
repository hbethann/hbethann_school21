NAME	=	push_swap

NAME_B	=	checker

SRCS	=	push_swap.c		add_stack.c		big_sort.c		ft_check.c\
			init_stack.c	med_sort.c		minisort.c		optimus.c\
			push_cmd.c		rev_rot.c 		rotate.c		swap.c

SRCS_B	=	checker.c		add_stack.c		big_sort.c		ft_check.c\
			init_stack.c	med_sort.c		minisort.c		optimus.c\
			push_cmd.c		rev_rot.c 		rotate.c		swap.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE = lib_ps/

HEADER	=	push_swap.h

CC		=	cc

FLAGS	=	-Wall -Werror -Wextra -g

RM		=	rm -rf



.PHONY:		all		clean	fclean	re	bonus	libft

all:	libft $(NAME)

%.o:	%.c $(INCLUDE)$(HEADER)
		$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

libft:
		@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
		
bonus:	libft $(OBJ_B)
		$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B) 

clean:
		@$(RM) $(OBJ) $(OBJ_B)
		@$(MAKE) -C libft/ clean

fclean:	clean
		@$(MAKE) -C libft/ fclean
		@$(RM) $(NAME) $(NAME_B)

re:		fclean all