#include <stdio.h>
#include "arquivo.h"

// Salvar tudo em arquivo
void salvarEmArquivo(struct Aluno *cabeca, const char *arquivo) {
    struct Aluno *atual = cabeca;

    FILE *arquivoAberto = fopen(arquivo, "w"); // Nome para o FILE é diferente do parametro original
    if (arquivoAberto == NULL) {
        printf("Arquivo ainda não foi criado!\n");
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    while (atual != NULL) {
        fprintf(arquivoAberto, "%s %d %f\n", atual->nome, atual->idade, atual->nota);
        atual = atual->proximo;
    }

    fclose(arquivoAberto);
}

// Carregar do Arquivo
struct Aluno* carregarArquivo(const char *arquivo) {
    FILE *arquivoAberto = fopen(arquivo, "r");
    if (arquivoAberto == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    char nomeTemp[50];
    int idadeTemp;
    float notaTemp;

    struct Aluno *cabeca = NULL;
    while (fscanf(arquivoAberto, "%s %d %f", nomeTemp, &idadeTemp, &notaTemp) == 3) {
        struct Aluno *aluno = criarAluno(nomeTemp, idadeTemp, notaTemp);
        inserirNoInicio(&cabeca, aluno);
    }
    fclose(arquivoAberto);
    return cabeca;
}