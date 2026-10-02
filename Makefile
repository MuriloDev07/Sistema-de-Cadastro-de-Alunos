# Nome do executável final
TARGET = sistema

# Compilador utilizado
CC = gcc

# Flags (opções) de compilação: mostram avisos úteis e preparam para debug
CFLAGS = -Wall -Wextra -g

# Todos os ficheiros de código que precisam de ser compilados
SRCS = main.c aluno/aluno.c arquivo/arquivo.c interface/interface.c

# Regra padrão executada ao digitar apenas 'make'
all: $(TARGET)

# Instrução de como gerar o executável a partir dos ficheiros .c
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Regra para limpar o projeto (remover o executável)
clean:
# Para Windows:
	del /Q /F $(TARGET).exe

# Para Linux: rm -f $(TARGET) $(TARGET).exe
	
