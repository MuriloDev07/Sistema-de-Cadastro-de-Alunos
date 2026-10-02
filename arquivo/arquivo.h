#ifndef ARQUIVO_H
#define ARQUIVO_H
#include "../aluno/aluno.h"

// Salvar tudo em arquivo
void salvarEmArquivo(struct Aluno *cabeca, const char *arquivo);

// Carregar do Arquivo
struct Aluno* carregarArquivo(const char *arquivo);

#endif
