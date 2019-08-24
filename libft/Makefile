# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elhampto <elhampto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 17:30:33 by elhampto          #+#    #+#              #
#    Updated: 2019/08/24 05:00:08 by elhampto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GNL = get_next_line \

PRINT = checks \
		dispatch \
		ft_printf \
		norm \
		ft_atoc \
		con_per \
		con_b \
		con_c \
		con_d \
		con_o \
		con_p \
		con_s \
		con_u \
		con_x \
		con_xa \

LIB = ft_atoi ft_bzero ft_ccstrjoin ft_ccstrjoini ft_cstrjoin ft_cstrjoini \
	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_is_space \
	ft_intputstr free_copy\
	ft_isint ft_itoa ft_itoa_b ft_itoa_base ft_itoa_base_unsigned ft_itoa_cx \
	ft_itoa_unsigned ft_itoa_x ft_itoa_o_unsigned ft_itoa_u_p ft_is_upper \
	ft_is_lower ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
	ft_lstmap ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel \
	ft_memmove ft_memset ft_numlen ft_putchar ft_putchar_fd ft_putendl \
	ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_strcat \
	ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ \
	ft_striter ft_striteri ft_strjoin ft_strlcat ft_strlen ft_strmap \
	ft_strmapi ft_strncat ft_strncpy ft_strncmp ft_strnequ ft_strnew \
	ft_strnstr ft_strrchr ft_strsplit ft_strstr ft_strsub ft_strtrim \
	ft_toupper ft_tolower ft_wordcount ft_tabs ft_unumlen ft_wordcount \

INC = -I includes

VPATH = gnl:is:lst:mem:other:put:str:print/conversions:print/files

OBJ_DOR = obj

OBJ  = $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(GNL)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(PRINT)))
OBJ += $(addsuffix .o, $(addprefix $(OBJ_DOR)/, $(LIB)))

CC = gcc

CFLAGS = -Wall -Werror -Wextra $(INC)

all: $(OBJ_DOR) $(NAME)

$(OBJ_DOR):
	@echo "\033[32mCreating objects...\033[0m"
	@mkdir -p $(OBJ_DOR)

$(OBJ_DOR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[32mCreating library...\033[0m"
	@ar -rcs $@ $^

clean:
	@echo "\033[33mCleaning objects...\033[0m"
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "\033[33mCleaning objects and library...\033[0m"
	@/bin/rm -rf $(OBJ_DOR)
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
