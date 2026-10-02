# Sistema de Cadastro de Alunos

Sistema de gestão via linha de comandos (CLI) para registar e organizar dados, desenvolvido integralmente em C.

## Funcionalidades

- Registo completo de **alunos** em sistema
- Persistência de dados local (leitura e gravação) através do ficheiro de texto `alunos.txt`
- Interface de linha de comandos interativa para navegação entre as opções do menu
- Separação modular de responsabilidades (lógica de negócio, interface e gestão de ficheiros)

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

## Contexto
Projeto criado para gerenciar cadastros de forma eficiente via terminal. Este sistema serviu como o meu primeiro projeto prático para consolidar os conhecimentos iniciais adquiridos sobre programação em C durante o segundo período da faculdade. O foco principal foi dominar conceitos fundamentais da linguagem, como a modularização de código, utilização de cabeçalhos (.h) e a manipulação de ficheiros de texto para persistência de dados. O próximo passo será continuar a evoluir a complexidade dos algoritmos e explorar novas estruturas de dados em projetos futuros.