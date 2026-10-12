# Sistema de Cadastro de Alunos

Sistema de gestão via linha de comandos (CLI) para registar e organizar dados, desenvolvido integralmente em C.

## Contexto
Projeto criado para gerenciar cadastros de forma eficiente via terminal. Este sistema serviu como o meu primeiro projeto prático para consolidar os conhecimentos iniciais adquiridos sobre programação em C durante o segundo período da faculdade. O foco principal foi dominar conceitos fundamentais da linguagem, como a modularização de código, utilização de cabeçalhos (.h) e a manipulação de ficheiros de texto para persistência de dados. O próximo passo será continuar a evoluir a complexidade dos algoritmos e explorar novas estruturas de dados em projetos futuros.

## Funcionalidades

- Registo completo de **alunos** em sistema
- Persistência de dados local (leitura e gravação) através do ficheiro de texto `alunos.txt`
- Interface de linha de comandos interativa para navegação entre as opções do menu
- Separação modular de responsabilidades (lógica de negócio, interface e gestão de ficheiros)

## Decisões de Engenharia e Regras de Negócio

Para garantir que o sistema não permitia inconsistências, tomei as seguintes decisões:

* **Separação de Responsabilidades (Arquitetura):** O meu maior desafio inicial foi evitar um código monolítico onde a leitura de ficheiros se misturasse com as regras de cálculo e com a interface visual. Decidi modularizar o sistema em camadas (aluno.c, arquivo.c, interface.c). Isso garante que, se eu quiser alterar o menu, não quebro a regra de cálculo das notas.
* **Ordenação e Lógica de Negócio:** Na listagem, o sistema não se limita a imprimir os dados. Implementei a lógica para processar as notas e exibir um relatório ordenado pela média, juntamente com estatísticas globais da turma (média geral e aprovações), gerando valor imediato para o utilizador.
* **Integridade na Persistência de Dados:** Como escolhi armazenar os dados num ficheiro de texto (alunos.txt), a minha principal preocupação foi garantir que o ficheiro era aberto e fechado corretamente em cada transação, prevenindo a corrupção ou perda do histórico caso a execução do programa fosse interrompida inesperadamente.

## Por que esta Stack?

* **C:** Escolhida para consolidar o meu aprendizado, permitindo que meus estudos fossem aplicados na prática com a criação de um projeto que resolve um problema real, realizar o cadastro de alunos de maneira prática e rápida.
* **Make (Automação de Compilação):** Com a arquitetura do sistema ficando cada vez mais complexa, realizar o processo de compilação manualmente no Terminal deixou de ser viável. Introduzi o MakeFile para garantir que a compilação ficasse mais prática e automática.

## O que aprendi e o que faria diferente (Próximos Passos)

1. **Gestão de Memória:** Trabalhar diretamente com persistência em ficheiros .txt fez-me compreender melhor a gestão manual da memória em C. O grande desafio num ficheiro de texto não é gravar os dados, mas sim analisá-los corretamente ao ler de volta para as estruturas.
2. **Estruturas de Dados Avançadas:** Atualmente o sistema trabalha bem com *arrays*. Numa próxima iteração, o desafio técnico seria implementar o cadastro com listas encadeadas, permitindo que a alocação dinâmica evite desperdício de memória caso a turma tenha poucos (ou muitos) alunos, eliminando um possível tamanho fixo inicial.

## Tecnologias

- C (Standard C)
- GCC (Compilador)
- Make (Automação de compilação)

## Como rodar o projeto

1. Clone o repositório
   ```bash
   git clone <url-do-seu-repo>
   cd <pasta-do-projeto>
   ```
   
2. Compile o projeto utilizando o Make
   ```bash
   make
   ```

3. Execute a aplicação 

   ```bash
   # No Windows
   .\sistema.exe

   # No Linux/Mac
   ./sistema
   ```
(Nota: Para limpar os ficheiros compilados, execute make clean)

## Estrutura do projeto

```text
├── main.c                  # Ponto de entrada da aplicação
├── Makefile                # Ficheiro de automação da compilação
├── alunos.txt              # "Base de dados" persistente
├── aluno/
│   ├── aluno.c             # Lógica e regras de negócio relativas aos alunos
│   └── aluno.h
├── arquivo/
│   ├── arquivo.c           # Manipulação e gestão da leitura/escrita de ficheiros
│   └── arquivo.h
└── interface/
    ├── interface.c         # Menus e interação direta com o utilizador
    └── interface.h
```
