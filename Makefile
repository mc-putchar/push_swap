# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 15:28:27 by mcutura           #+#    #+#              #
#    Updated: 2023/06/10 16:11:49 by mcutura          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
#--- DIRECTORIES ---
SRCDIR := src
INCDIR := inc
OBJDIR := obj
LIBFTDIR := libft
#--- LIBRARIES ---
LIBFT := $(LIBFTDIR)/libft.a
#--- SOURCES ---
SRCS := $(addprefix $(SRCDIR)/, main.c error_handler.c push_swap.c ft_roll.c \
	ft_roll_ops.c)
#--- OBJECTS ---
OBJS := $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))
#--- HEADERS ---
HEADERS := $(addprefix $(INCDIR)/, push_swap.h ft_roll.h error_handler.h \
	libft.h get_next_line.h ft_printf.h ft_roll_ops.h)
#--- FLAGS ---
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR)
LDFLAGS := -L$(LIBFTDIR)
LDLIBS := -lft

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(HEADERS) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(HEADERS):
	ln $(LIBFTDIR)/libft.h $(INCDIR)/libft.h
	ln $(LIBFTDIR)/get_next_line.h $(INCDIR)/get_next_line.h
	ln $(LIBFTDIR)/ft_printf.h $(INCDIR)/ft_printf.h

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) $(INCDIR)/libft.h
	$(RM) $(INCDIR)/get_next_line.h
	$(RM) $(INCDIR)/ft_printf.h

re: fclean all
