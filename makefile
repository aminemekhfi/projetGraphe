# Nom de l'exécutable
EXEC = programme

# Fichiers objets nécessaires
OBJ = main.o Exercice1.o

# Compilateur et options
CC = gcc
CFLAGS = -Wall -g

# Règle principale : créer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Règle pour compiler main.o
main.o: main.c Exercice1.h
	$(CC) $(CFLAGS) -c main.c

# Règle pour compiler Exercice1.o
Exercice1.o: Exercice1.c Exercice1.h
	$(CC) $(CFLAGS) -c Exercice1.c

# Nettoyer les fichiers intermédiaires
clean:
	rm -f $(OBJ) $(EXEC)
