# Nome do executável
EXEC = programa

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O3

# Fontes e objetos
SRCS = main.cpp ordenacao.cpp busca.cpp gerador_dados.cpp
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(EXEC)

# Compilação final
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Limpeza
clean:
	rm -f *.o $(EXEC)
