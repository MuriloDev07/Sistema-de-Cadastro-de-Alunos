#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

// Criação de um Novo Aluno
struct Aluno* criarAluno(const char *nome, int idade, float nota) {
    struct Aluno *a1 = malloc(sizeof(struct Aluno));
    strcpy(a1->nome, nome);
    a1->idade = idade;
    a1->nota = nota;

    return a1;
}

// Inserir um Novo Aluno no Inicio da Lista
void inserirNoInicio(struct Aluno **cabeca, struct Aluno *novo) {
    novo->proximo = *cabeca;
    *cabeca = novo;
}

// Remover um Aluno da Lista
void removerPorNome(struct Aluno **cabeca, const char *nome) {
    struct Aluno *atual = *cabeca;
    struct Aluno *anterior = *cabeca;

    while (atual != NULL && strcmp(atual->nome, nome) != 0 ) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Aluno não encontrado!\n");
        return;
    }

    // Remove o primeiro
    if (atual == *cabeca) {
        *cabeca = atual->proximo;
    }

    // Remove do meio/fim
    else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
}

// Calcular Média da Turma
float calcularMedia(struct Aluno *cabeca) {
    struct Aluno *atual = cabeca;

    int quantidade = 0;
    float soma = 0;
    float media = 0;
    while (atual != NULL) {
        soma = soma + atual->nota;
        atual = atual->proximo;
        quantidade = quantidade + 1;
    }
    
    if (quantidade == 0) {
        return 0;
    }

    media = soma / quantidade;
    return media;
}

// Contagem dos Aprovados
int contarAprovados(struct Aluno *cabeca) {
    struct Aluno *atual = cabeca;
    enum Status status;

    int contAprovados = 0;
    while (atual != NULL) {
        if (atual->nota >= 6) {
            status = APROVADO;
        }

        else {
            status = REPROVADO;
        }

        switch (status) {
            case APROVADO:
                contAprovados = contAprovados + 1;
                break;
            case REPROVADO:
                break;
        
            }
        atual = atual->proximo;
    }

    return contAprovados;
}

// Liberar memória
void liberarLista(struct Aluno *cabeca) {
    struct Aluno *atual = cabeca;
    
    while (atual != NULL) {
        struct Aluno *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}