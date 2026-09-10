# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/10 12:20:45 by dcaetano          #+#    #+#              #
#    Updated: 2026/09/10 17:16:17 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === COMMANDS =============================================================== #

COMMAND_NASM                     = nasm
COMMAND_MKDIR                    = mkdir
COMMAND_RM                       = rm
COMMAND_AR_RCS                   = ar rcs

# === DIRECTORIES ============================================================ #

DIRECTORY_MANDATORY              = mandatory
DIRECTORY_BONUS                  = bonus
DIRECTORY_INCLUDES               = includes
DIRECTORY_SOURCES                = sources
DIRECTORY_OBJECTS                = objects

# === EXTENSIONS ============================================================= #

EXTENSION_S                      = .s
EXTENSION_H                      = .h
EXTENSION_O                      = .o

# === FILES ================================================================== #

# mandatory
FILES_MANDATORY_HEADERS          = libasm
FILES_MANDATORY_INCLUDES         = $(addprefix $(DIRECTORY_MANDATORY)/$(DIRECTORY_INCLUDES)/,$(addsuffix $(EXTENSION_H),$(FILES_MANDATORY_HEADERS)))

FILES_MANDATORY_FUNCTIONS        = strlen strcpy strcmp write read strdup calloc
FILES_MANDATORY_FTS              = $(addprefix ft_,$(FILES_MANDATORY_FUNCTIONS))
FILES_MANDATORY_SOURCES          = $(addprefix $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/,$(addsuffix $(EXTENSION_S),$(FILES_MANDATORY_FTS)))
FILES_MANDATORY_OBJECTS          = $(patsubst $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S),$(DIRECTORY_OBJECTS)/$(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_MANDATORY_SOURCES))

FILES_MANDATORY_FUNCTIONS_DEP    =
FILES_MANDATORY_FTS_DEP          = $(addprefix ft_,$(addsuffix _bonus,$(FILES_MANDATORY_FUNCTIONS_DEP)))
FILES_MANDATORY_SOURCES_DEP      = $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/,$(addsuffix $(EXTENSION_S),$(FILES_MANDATORY_FTS_DEP)))
FILES_MANDATORY_OBJECTS_DEP      = $(patsubst $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S),$(DIRECTORY_OBJECTS)/$(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_MANDATORY_SOURCES_DEP))

# bonus
FILES_BONUS_HEADERS              = libasm_bonus
FILES_BONUS_INCLUDES             = $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_INCLUDES)/,$(addsuffix $(EXTENSION_H),$(FILES_BONUS_HEADERS)))

FILES_BONUS_FUNCTIONS            = atoi_base list_push_front list_size list_sort list_remove_if
FILES_BONUS_FTS                  = $(addprefix ft_,$(addsuffix _bonus,$(FILES_BONUS_FUNCTIONS)))
FILES_BONUS_SOURCES              = $(addprefix $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/,$(addsuffix $(EXTENSION_S),$(FILES_BONUS_FTS)))
FILES_BONUS_OBJECTS              = $(patsubst $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S),$(DIRECTORY_OBJECTS)/$(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_BONUS_SOURCES))

FILES_BONUS_FUNCTIONS_DEP        = strlen
FILES_BONUS_FTS_DEP              = $(addprefix ft_,$(FILES_BONUS_FUNCTIONS_DEP))
FILES_BONUS_SOURCES_DEP          = $(addprefix $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/,$(addsuffix $(EXTENSION_S),$(FILES_BONUS_FTS_DEP)))
FILES_BONUS_OBJECTS_DEP          = $(patsubst $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S),$(DIRECTORY_OBJECTS)/$(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O),$(FILES_BONUS_SOURCES_DEP))

ifneq ($(MAKECMDGOALS),bonus)
    OBJECTS                      = $(FILES_MANDATORY_OBJECTS) $(FILES_MANDATORY_OBJECTS_DEP)
else
    OBJECTS                      = $(FILES_BONUS_OBJECTS) $(FILES_BONUS_OBJECTS_DEP)
endif

# === FLAGS ================================================================== #

FLAGS_NASM                       = -f elf64 -g
FLAGS_MKDIR                      = -p
FLAGS_RM                         = -rfv

# === PROJECT ================================================================ #

NAME                             = libasm.a

# === RULES ================================================================== #

all: $(NAME)

bonus: $(NAME)

clean:
	@$(COMMAND_RM) $(FLAGS_RM) '$(DIRECTORY_OBJECTS)'

fclean: clean
	@$(COMMAND_RM) $(FLAGS_RM) '$(LIBTESTER)' '$(NAME)'

re: fclean all

$(NAME): $(OBJECTS)
	@$(COMMAND_AR_RCS) '$(NAME)' $(OBJECTS)

$(DIRECTORY_OBJECTS)/$(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O): $(DIRECTORY_MANDATORY)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S) $(FILES_MANDATORY_INCLUDES)
	@$(COMMAND_MKDIR) $(FLAGS_MKDIR) '$(dir $@)'
	@$(COMMAND_NASM) $(FLAGS_NASM) '$<' -o '$@'

$(DIRECTORY_OBJECTS)/$(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_O): $(DIRECTORY_BONUS)/$(DIRECTORY_SOURCES)/%$(EXTENSION_S) $(FILES_BONUS_INCLUDES)
	@$(COMMAND_MKDIR) $(FLAGS_MKDIR) '$(dir $@)'
	@$(COMMAND_NASM) $(FLAGS_NASM) '$<' -o '$@'

.PHONY: all bonus clean fclean re
