# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

# Arquivos-fonte e objetos
SRCS = romanos.cpp testa_romanos.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = testa_romanos

# Alvo principal
all: $(TARGET)

# Regra de compilação dos objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) -c $< -o $@

# Linkagem final
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) $(OBJS) -o $@

# Executar os testes
run: $(TARGET)
	./$(TARGET)

# Geração de cobertura
coverage: run
	gcov -r romanos.cpp

# Limpeza
clean:
	rm -f *.o *.gcno *.gcda *.gcov $(TARGET)

.PHONY: all run coverage clean