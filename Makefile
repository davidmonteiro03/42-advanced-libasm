# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/07 07:15:44 by dcaetano          #+#    #+#              #
#    Updated: 2026/09/11 15:40:09 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === COMMANDS =============================================================== #

COMMAND_CC                       = cc
COMMAND_MKDIR                    = mkdir
COMMAND_RM                       = rm
COMMAND_AR_RCS                   = ar rcs

# === DIRECTORIES ============================================================ #

DIRECTORY_MANDATORY              = mandatory
DIRECTORY_BONUS                  = bonus
DIRECTORY_INCLUDES               = includes
DIRECTORY_SOURCES                = sources
DIRECTORY_OBJECTS                = objects
DIRECTORY_LIBASM                 = libasm
DIRECTORY_HELPER                 = helper

# === EXTENSIONS ============================================================= #

EXTENSION_C                      = .c
EXTENSION_H                      = .h
EXTENSION_O                      = .o

# === FILES ================================================================== #

# mandatory
FILES_MANDATORY_HEADERS          = colors common functions libs tester
FILES_MANDATORY_FUNCTIONS        = strlen strcpy strcmp write read strdup calloc
FILES_MANDATORY_TESTS            = $(addprefix test_,$(FILES_MANDATORY_FUNCTIONS))
FILES_MANDATORY_INCLUDES         = $(addprefix $(DIRECTORY_MANDATORY)/$(DIRECTORY_INCLUDES)/,$(addsuffix $(EXTENSION_H),$(FILES_MANDATORY_HEADERS)))
FILES_MANDATORY_SOURCES          = $(addprefix $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/,$(addsuffix $(EXTENSION_C),$(FILES_MANDATORY_TESTS)))
FILES_MANDATORY_OBJECTS          = $(patsubst $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_C),$(DIRECTORY_OBJECTS)/$(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_MANDATORY_SOURCES))
FILES_MANDATORY_MAIN_SRC         = tester.c
FILES_MANDATORY_MAIN_OBJ         = $(DIRECTORY_OBJECTS)/tester.o

# bonus
FILES_BONUS_HEADERS              = colors common functions libs tester
FILES_BONUS_FUNCTIONS            = atoi_base list_push_front list_size list_sort list_remove_if
FILES_BONUS_HELPERS              = atoi_base alloc_functions compare_functions free_functions print_functions list_utils
FILES_BONUS_TESTS                = $(addprefix test_,$(FILES_BONUS_FUNCTIONS))
FILES_BONUS_INCLUDES             = $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_INCLUDES)/,$(addsuffix _bonus$(EXTENSION_H),$(FILES_BONUS_HEADERS)))
FILES_BONUS_SOURCES              = $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/,$(addsuffix _bonus$(EXTENSION_C),$(FILES_BONUS_TESTS)))
FILES_BONUS_SOURCES             += $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/$(DIRECTORY_HELPER)/,$(addsuffix _bonus$(EXTENSION_C),$(FILES_BONUS_HELPERS)))
FILES_BONUS_OBJECTS              = $(patsubst $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_C),$(DIRECTORY_OBJECTS)/$(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_BONUS_SOURCES))
FILES_BONUS_MAIN_SRC             = tester_bonus.c
FILES_BONUS_MAIN_OBJ             = $(DIRECTORY_OBJECTS)/tester_bonus.o

ifneq ($(MAKECMDGOALS),bonus)
    OBJECTS                      = $(FILES_MANDATORY_OBJECTS)
    MAIN_OBJ                     = $(FILES_MANDATORY_MAIN_OBJ)
else
    OBJECTS                      = $(FILES_BONUS_OBJECTS)
    MAIN_OBJ                     = $(FILES_BONUS_MAIN_OBJ)
endif

# === FLAGS ================================================================== #

FLAGS_CC                         = -Wall -Wextra -Werror -O0 -ggdb3
FLAGS_MKDIR                      = -p
FLAGS_RM                         = -rfv

# === PROJECT ================================================================ #

LIBASM                           = libasm.a
LIBTESTER                        = libtester.a
LIBS                             = $(LIBTESTER) $(DIRECTORY_LIBASM)/$(LIBASM)
NAME                             = tester

# === RULES ================================================================== #

all: $(NAME)

bonus: $(NAME)

clean:
	@$(MAKE) -sC '$(DIRECTORY_LIBASM)' clean
	@$(COMMAND_RM) $(FLAGS_RM) '$(DIRECTORY_OBJECTS)'

fclean: clean
	@$(MAKE) -sC '$(DIRECTORY_LIBASM)' fclean
	@$(COMMAND_RM) $(FLAGS_RM) '$(LIBTESTER)' '$(NAME)'

re: fclean all

$(NAME): $(LIBTESTER) $(MAIN_OBJ)
	@$(MAKE) -sC '$(DIRECTORY_LIBASM)' $(MAKECMDGOALS)
	@$(COMMAND_CC) $(FLAGS_CC) '$(MAIN_OBJ)' $(LIBS) -o '$(NAME)'

$(LIBTESTER): $(OBJECTS)
	@$(COMMAND_AR_RCS) '$(LIBTESTER)' $(OBJECTS)

$(DIRECTORY_OBJECTS)/$(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O): $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_C) $(FILES_MANDATORY_INCLUDES)
	@$(COMMAND_MKDIR) $(FLAGS_MKDIR) '$(dir $@)'
	@$(COMMAND_CC) $(FLAGS_CC) -c '$<' -o '$@'

$(DIRECTORY_OBJECTS)/$(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O): $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_C) $(FILES_BONUS_INCLUDES)
	@$(COMMAND_MKDIR) $(FLAGS_MKDIR) '$(dir $@)'
	@$(COMMAND_CC) $(FLAGS_CC) -c '$<' -o '$@'

$(DIRECTORY_OBJECTS)/%$(EXTENSION_O): %$(EXTENSION_C)
	@$(COMMAND_CC) $(FLAGS_CC) -c '$<' -o '$@'

.PHONY: all bonus clean fclean re
