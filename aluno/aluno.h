#ifndef ALUNO_H
#define ALUNO_H

// Molde da Lista Ligada
struct Aluno {
    char nome[50];
    int idade;
    float nota;
    struct Aluno *proximo;
};

enum Status {APROVADO, REPROVADO};

// Criação de um Novo Aluno
struct Aluno* criarAluno(const char *nome, int idade, float nota);

// Inserir um Novo Aluno no Inicio da Lista
void inserirNoInicio(struct Aluno **cabeca, struct Aluno *novo);

// Remover um Aluno da Lista
void removerPorNome(struct Aluno **cabeca, const char *nome);

// Calcular Média da Turma
float calcularMedia(struct Aluno *cabeca);

// Contagem dos Aprovados
int contarAprovados(struct Aluno *cabeca);

// Liberar memória
void liberarLista(struct Aluno *cabeca);

#endif