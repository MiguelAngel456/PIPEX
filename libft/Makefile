NAME = libft.a
SCRS = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\
get_next_line.c\
get_next_line_utils.c\
ft_printf.c\
ft_printf_char.c\
ft_printf_du.c\
ft_printf_por.c\
ft_printf_punt.c\
ft_printf_s.c\
ft_printf_xX.c\

OBJS = $(SCRS:.c=.o)

SCRS_BONUS = ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstsize_bonus.c\
ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c\
ft_lstclear_bonus.c\
ft_lstiter_bonus.c\
ft_lstmap_bonus.c\

OBJS_BONUS = $(SCRS_BONUS:.c=.o)
RM = rm -f
COMPILER = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = libft.h
STATIC_LIB = ar rcs
GREEN = `tput setaf 2`
BLUE = `tput setaf 4`
RESET = `tput sgr0`
all:	$(NAME)
$(NAME): $(OBJS) $(HEADER)
	@-$(STATIC_LIB) $(NAME) $(OBJS)
	@echo "${GREEN}------✅LIBF-PRINTF-GNL COMPILED✅-------${RESET}"
bonus: $(OBJS) $(OBJS_BONUS) $(NAME)
	@-$(STATIC_LIB) $(NAME) $(OBJS) $(OBJS_BONUS)
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "${BLUE}------✅ALL CLEAN✅-------${RESET}"
fclean: clean
	$(RM) $(NAME)
re: fclean
	@-$(MAKE) all
.Phony: all clean fclean re bonus