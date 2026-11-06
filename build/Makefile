# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sicleerd <sicleerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/10/30 13:58:46 by sicleerd      #+#    #+#                  #
<<<<<<< HEAD
#    Updated: 2026/11/05 14:38:31 by sicleerd      ########   odam.nl          #
=======
#    Updated: 2026/11/05 17:23:00 by sicleerd      ########   odam.nl          #
>>>>>>> main
#                                                                              #
# **************************************************************************** #

NAMEP		= push_swap
NAMEC		= checker

SRC_DIR		= srcs/src
OBJ_DIR		= obj
LIBFT_DIR	= srcs/libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Sources used by BOTH programs. A new shared .c file goes here, nowhere else.
SRC_COMMON	= arg_check create_node del_stacks error_delete_all \
			execute printstacks push_stack reverse_rotate_stack \
			rotate_stack sorted stack_sorted swap_stack disorder \
<<<<<<< HEAD
			normalize chunk_sort bench_mode simple_sort simple_sort_imp 
=======
			normalize chunk_sort bench_mode simple_sort simple_sort_imp
>>>>>>> main

# Sources used by only one program (each one holds that program's main).
SRC_P		= push_swap
SRC_C		= checker read_line

OBJ_COMMON	= $(SRC_COMMON:%=$(OBJ_DIR)/%.o)
OBJ_P		= $(SRC_P:%=$(OBJ_DIR)/%.o)
OBJ_C		= $(SRC_C:%=$(OBJ_DIR)/%.o)
DEPS		= $(OBJ_COMMON:.o=.d) $(OBJ_P:.o=.d) $(OBJ_C:.o=.d)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
CPPFLAGS	= -I includes -I $(LIBFT_DIR) -MMD -MP

all: $(NAMEP) $(NAMEC)

$(NAMEP): $(OBJ_P) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_P) $(OBJ_COMMON) $(LIBFT) -o $@
	@echo "Linked $@"

$(NAMEC): $(OBJ_C) $(OBJ_COMMON) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_C) $(OBJ_COMMON) $(LIBFT) -o $@
	@echo "Linked $@"

# libft has its own Makefile, so always ask it whether it has work to do.
# It only touches libft.a when something changed, so push_swap and checker
# only relink when libft really was rebuilt.
$(LIBFT): FORCE
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

FORCE:

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $(notdir $<)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

# Header dependencies: editing a .h rebuilds every .c that includes it.
-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAMEP) $(NAMEC)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean
	@$(MAKE) --no-print-directory all

.PHONY: all clean fclean re FORCE
