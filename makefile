NAME=source
# OBJFILES=$(NAME).o linkedList.o linkedListNode.o vertex.o
OBJFILES=$(NAME).o vertex.o shortestPathNode.o shortestPathVertex.o shortestPathEdge.o shortestPathGraph.o shortestPathList.o

CC=g++
CFLAGS= -std=c++11 -pedantic -Wall -Wextra -g

# vzorové pravidlo pro generování všech objektových souborů
%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Startovací pravidlo - pro přehlednost
all: $(NAME)

# Generování závislostí
# při změně souborů spustíme 'make dep'
dep:
	$(CC) -MM *.cpp >dep.list

-include dep.list

# závěrečné slinkování
$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@