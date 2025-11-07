#******************************************************************************
# MAIN *
#******************************************************************************
COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

#******************************************************************************
# DIRECTORIES *
#******************************************************************************
OBJ_DEP_DIR = obj_n_dep/

#******************************************************************************
# SOURCES, OBJECTS, HEADER & DEPENDENCIES *
#******************************************************************************
COLLEEN_SRC = Colleen.c
GRACE_SRC = Grace.c
SULLY_SRC = Sully.c

#******************************************************************************
# INSTRUCTIONS *
#******************************************************************************
CC = cc -g3
FLAGS = -Wall -Wextra -Werror -I

#******************************************************************************
# COLORS *
#******************************************************************************
RESET = \033[0m
ROSE = \033[1;38;5;225m
VIOLET = \033[1;38;5;55m
VERT = \033[1;38;5;85m
BLEU = \033[1;34m

#******************************************************************************
# COMPILATION *
#******************************************************************************

all: $(COLLEEN) $(GRACE) $(SULLY)
	@echo "$(ROSE)✓ Tous les programmes sont compilés !$(RESET)"

$(COLLEEN): $(COLLEEN_SRC)
	@echo "$(BLEU)⚙ Compilation de $(COLLEEN)...$(RESET)"
	@$(CC) $(CFLAGS) $(COLLEEN_SRC) -o $(COLLEEN)
	@echo "$(ROSE)✓ $(COLLEEN) créé avec succès !$(RESET)"

$(GRACE): $(GRACE_SRC)
	@echo "$(BLEU)⚙ Compilation de $(GRACE)...$(RESET)"
	@$(CC) $(CFLAGS) $(GRACE_SRC) -o $(GRACE)
	@echo "$(ROSE)✓ $(GRACE) créé avec succès !$(RESET)"

$(SULLY): $(SULLY_SRC)
	@echo "$(BLEU)⚙ Compilation de $(SULLY)...$(RESET)"
	@$(CC) $(CFLAGS) $(SULLY_SRC) -o $(SULLY)
	@echo "$(ROSE)✓ $(SULLY) créé avec succès !$(RESET)"

clean:
	@echo "$(VIOLET)🧹 Nettoyage des fichiers temporaires...$(RESET)"
	@rm -rf *.o *_kid.c tmp/
	@echo "$(ROSE)✓ Nettoyage terminé !$(RESET)"

fclean: clean
	@echo "$(VERT)🗑️  Suppression des exécutables...$(RESET)"
	@rm -f $(COLLEEN) $(GRACE) $(SULLY)
	@rm -f Grace_kid.c Sully_*.c Sully_* tmp_colleen
	@echo "$(ROSE)✓ Tout est propre !$(RESET)"

re: fclean all

.PHONY: all clean fclean re