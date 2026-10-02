#include <stdio.h>
#include <string.h>
#include "interface.h"

// Interface

// Gera linhas para Interface
void imprimirLinha(int tamanho) {
    for (int i = 0; i < tamanho; i = i + 1) {
        printf("-");
    }
    printf("\n");
}

// Centralizador de Textos
void cabecalho(const char *texto, int largura) {
    int tamanhoTexto = (int) strlen(texto);
    int espacos = (largura - tamanhoTexto) / 2;

    for (int i = 0; i < espacos; i = i + 1) {
        printf(" ");
    }
    printf("%s\n", texto);
}