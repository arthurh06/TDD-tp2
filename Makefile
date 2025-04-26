# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Alvo principal
all: testa_romanos

# Compila os objetos
romanos.o: romanos.cpp romanos.hpp
	$(CXX) $(CXXFLAGS) -c romanos.cpp

testa_romanos.o: testa_romanos.cpp romanos.hpp
	$(CXX) $(CXXFLAGS) -c testa_romanos.cpp

# Linka tudo e gera o executável
testa_romanos: romanos.o testa_romanos.o
	$(CXX) $(CXXFLAGS) romanos.o testa_romanos.o -o testa_romanos

# Executa os testes (se quiser automatizar)
run: testa_romanos
	./testa_romanos

# Gcov para cobertura
gcov: clean
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c romanos.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c testa_romanos.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage romanos.o testa_romanos.o -o testa_romanos
	./testa_romanos
	gcov romanos.cpp testa_romanos.cpp

# Valgrind (Linux)
valgrind: testa_romanos
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_romanos

# Debug com gdb
debug: testa_romanos
	gdb ./testa_romanos

# Limpa arquivos temporários
clean:
	rm -f *.o *.exe *.out *.gcno *.gcda *.gcov testa_romanos

.PHONY: all run gcov valgrind debug clean
