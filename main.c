#include <stdio.h>
#include "aluno/aluno.h"
#include "arquivo/arquivo.h"
#include "interface/interface.h"

// Sistema
int main() {
    struct Aluno *cabeca = NULL;
    enum Opcao {INSERIR, REMOVER, LISTAR, SALVAR, SAIR};

    struct Aluno *atual = carregarArquivo("alunos.txt");
    cabeca = atual;

    int opcao = 0;
    while (opcao != SAIR) {
        imprimirLinha(30);
        cabecalho("MENU", 30);
        imprimirLinha(30);
        printf("0 - INSERIR Aluno\n");
        printf("1 - REMOVER Aluno\n");
        printf("2 - LISTAR Alunos\n");
        printf("3 - SALVAR Alunos\n");
        printf("4 - SAIR\n");
        imprimirLinha(30);

        printf("Sua Opcao: ");
        scanf("%d", &opcao);
        imprimirLinha(30);

        switch (opcao) {
            case INSERIR: {
                char nome[50];
                int idade;
                float nota;

                printf("Nome do Aluno: ");
                scanf("%s", nome);
                printf("Idade do Aluno: ");
                scanf("%d", &idade);
                printf("Nota do Aluno: ");
                scanf("%f", &nota);

                struct Aluno *a0 = criarAluno(nome, idade, nota);
                inserirNoInicio(&cabeca, a0);
                break;
            }

            case REMOVER: {
                char nome[50];
                printf("Nome do Aluno: ");
                scanf("%s", nome);

                removerPorNome(&cabeca, nome);
                break;
            }

            case LISTAR: {
                struct Aluno *atual = cabeca;
                while (atual != NULL) {
                    printf("Nome: %s\nIdade: %d\nNota: %.2f\n\n", atual->nome, atual->idade, atual->nota);
                    atual = atual->proximo;
                }

                float media = calcularMedia(cabeca);
                printf("A media da turma foi %.2f\n", media);

                int aprovados = contarAprovados(cabeca);
                printf("Na turma tivemos %d aprovados!\n", aprovados);

                break;
            }

            case SALVAR: {
                salvarEmArquivo(cabeca, "alunos.txt");
                break;
            }
            
            case SAIR: {
                printf("Programa Encerrado!\nVolte Sempre!\n");
                break;
            }

            default: {
                printf("ERRO! Escolha uma opção válida!\n");
            }
        }
    }
    liberarLista(cabeca);
    return 0;
}