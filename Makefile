# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minabe <minabe@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 13:12:23 by louisnop          #+#    #+#              #
#    Updated: 2023/08/09 23:30:49 by minabe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -MMD -MP
# CFLAGS += -g -fsanitize=address

TARGET = bsq

INCDIR = incs
INCS = $(shell find $(INCDIR) -type f -name "*.h")

SRCDIR = ./srcs
SRCS = $(shell find $(SRCDIR) -type f -name "*.c")

OBJDIR = ./objs
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(OBJS:.o=.d)

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

LDFLAGS = -Llibft -lft -I$(INCDIR)

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

.PHONY: all clean re
clean:
	$(MAKE) fclean -C $(LIBFTDIR)
	-rm -f $(OBJS)

fclean:
	-rm -f $(TARGET) $(OBJS)

re: fclean all
