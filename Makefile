#VARIABLES
NAME = pipex
BONUS_NAME = pipex_bonus
CC = gcc -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
LIBFT_PATH = ./libft
GREEN = `tput setaf 2`
RESET = `tput sgr0`
BLUE = `tput setaf 4`

#ARCHIVO
FILES = pipex.c\
		archive_process.c\
		archive_cmd.c\

#CREA LOS ARCHIVOS OBJETO
OBJS = $(FILES:.c=.o)

#COMPILA LOS ARCHIVOS
#SE ENCARGA DE QUE AGREGAR A LA LIBRERIA .A LOS OBJETOS
all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	@-make -sC $(LIBFT_PATH)
	@-$(CC) -I ./pipex.h -c $< -o $@
	@-echo "${GREEN}-----------✅PIPEX COMPILED✅------------${RESET}"
#ENCARGADO DE HACER LA PARTE DE LIMPIEZA TANTO EN ESTA CARPETA COMO EN LIBFT

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@make -sC $(LIBFT_PATH) clean
	@echo "${BLUE}------✅ALL CLEAN✅-------${RESET}"

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -sC $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re