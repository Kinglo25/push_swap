NAME		=	push_swap

SRC_PATH	=	src/

OBJ_PATH	=	obj/

SRC			=	main.c push.c rotate.c sort_small_stacks.c \
				utils.c free_exit.c index.c parser.c \
				reverse_rotate.c sort_big_stacks.c swap.c 

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

OBJ			=	$(SRC:c=o)

OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I ./includes

all:		$(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o:		$(SRC_PATH)%.c
				@echo "Compiling $<"
				@$(CC) $(CFLAGS) -c $(INC) $< -o $@
				@echo "Compiling OK!"

$(OBJ_PATH):
				@echo "Creating objects directory for $(NAME)."
				@mkdir $(OBJ_PATH)
				@echo "Created."

$(NAME):	$(OBJS)
				@echo "Creating executable: $@."
				@${MAKE} -C ./libft
				@cc $(CFLAGS) $^ ./libft/libft.a -o $@
				@echo "Job's done!"
clean:
				@${MAKE} -C ./libft fclean
				@echo "Cleaning objects of $(NAME)..."
				@rm -rf $(OBJ_PATH)
				@echo "Cleaned up!"

fclean:		clean
				@echo "Cleaning $(NAME)"
				@rm -rf $(NAME)
				@echo "$(NAME) cleaned up!"

re:			fclean all

.PHONY:		all clean fclean re