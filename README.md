# Sistema de Cadastro de Alunos

Sistema de gestão via linha de comandos (CLI) para registar e organizar dados, desenvolvido **integralmente em C**.

## Contexto
Projeto criado para gerenciar cadastros de forma eficiente via terminal. Este sistema serviu como o meu **primeiro projeto prático** para consolidar os conhecimentos iniciais adquiridos sobre programação em C durante o segundo período da faculdade. O foco principal foi dominar conceitos fundamentais da linguagem, como a **modularização de código**, **utilização de cabeçalhos (.h)** e a **manipulação de ficheiros de texto** para persistência de dados. A evolução do projeto incluiu a **conteinerização do ambiente**, garantindo portabilidade e isolamento. O próximo passo será continuar a evoluir a complexidade dos algoritmos e explorar **novas estruturas de dados** em projetos futuros.

## Funcionalidades

- **Registo completo** de alunos em sistema.
- **Persistência de dados local** (leitura e gravação) através do ficheiro de texto `alunos.txt`.
- **Interface de linha de comandos (CLI)** interativa para navegação entre as opções do menu.
- **Separação modular** de responsabilidades (lógica de negócio, interface e gestão de ficheiros).
- **Execução em Container:** Isolamento completo do sistema através de Docker, garantindo que rode em qualquer máquina sem necessidade de configurações locais.

## Decisões de Engenharia e Regras de Negócio

Para garantir que o sistema não permitisse inconsistências e fosse escalável, tomei as seguintes decisões:

- **Separação de Responsabilidades (Arquitetura):** O meu maior desafio inicial foi **evitar um código monolítico** onde a leitura de ficheiros se misturasse com as regras de cálculo e com a interface visual. Decidi **modularizar o sistema em camadas** (`aluno.c`, `arquivo.c`, `interface.c`). Isso garante que, se eu quiser alterar o menu, não quebro a regra de cálculo das notas.
- **Ordenação e Lógica de Negócio:** Na listagem, o sistema não se limita a imprimir os dados. Implementei a lógica para **processar as notas e exibir um relatório ordenado** pela média, juntamente com **estatísticas globais da turma** (média geral e aprovações), gerando valor imediato para o utilizador.
- **Integridade na Persistência de Dados:** Como escolhi armazenar os dados num ficheiro de texto (`alunos.txt`), a minha principal preocupação foi garantir que o ficheiro era aberto e fechado corretamente em cada transação. No ambiente Docker, utilizei mapeamento de **Volumes** para garantir que os dados escritos dentro do container fossem persistidos na máquina hospedeira de forma transparente.
- **Containerização com Multi-Stage Build:** Para evitar o envio de uma imagem pesada contendo o compilador GCC para produção, o `Dockerfile` foi dividido em duas etapas. A primeira compila o código e a segunda utiliza uma **imagem mínima** (`debian:stable-slim`) apenas com o executável, reduzindo drasticamente o consumo de memória e aumentando a segurança.

## Por que esta Stack?

- **C:** Escolhida para consolidar o meu aprendizado, permitindo que meus estudos fossem aplicados na prática com a criação de um projeto que **resolve um problema real**.
- **Make (Automação de Compilação):** Com a arquitetura do sistema ficando cada vez mais complexa, realizar o processo de compilação manualmente no Terminal deixou de ser viável. Introduzi o `Makefile` para garantir que a compilação ficasse **mais prática e automática**.
- **Docker:** Adotado para **eliminar o problema de "funciona na minha máquina"**. Qualquer pessoa pode rodar o projeto sem precisar ter o compilador C instalado.

## O que aprendi e o que faria diferente (Próximos Passos)

1. **Gestão de Memória:** Trabalhar diretamente com persistência em ficheiros `.txt` fez-me compreender melhor a **gestão manual da memória** em C. O grande desafio num ficheiro de texto não é gravar os dados, mas sim analisá-los corretamente ao ler de volta para as estruturas.
2. **Estruturas de Dados Avançadas:** Atualmente o sistema trabalha bem com *arrays*. Numa próxima iteração, o desafio técnico seria implementar o cadastro com **listas encadeadas**, permitindo que a **alocação dinâmica** evite desperdício de memória.

## Tecnologias

- **C** (Standard C)
- **GCC** (Compilador)
- **Make** (Automação de compilação e execução)
- **Docker** (Containerização e Multi-stage Build)

## Como rodar o projeto

Clone o repositório antes de escolher o método de execução:
```bash
git clone <url-do-seu-repo>
cd <pasta-do-projeto>
```
   
Opção 1: Via Docker (Recomendado)
> Não requer o GCC instalado na máquina, apenas o Docker.
```bash
# 1. Construa a imagem isolada do sistema
docker build -t cadastro-alunos .

# 2. Execute o sistema (o Makefile cuidará do mapeamento do Volume dos dados)
make docker-run
```

Opção 2: Compilação Local
> Requer o compilador GCC instalado localmente (Linux/Mac/Windows com MinGW).
```bash
# 1. Compile o projeto
make

# 2. Execute a aplicação (Linux/Mac)
./sistema

# Ou no Windows:
.\sistema.exe
```
Nota: Para limpar os ficheiros compilados localmente, execute make clean


## Estrutura do projeto

```text
├── main.c                  # Ponto de entrada da aplicação
├── Makefile                # Automação da compilação e comandos Docker
├── Dockerfile              # Receita Multi-stage para a criação da imagem
├── .dockerignore           # Filtro para ignorar lixo de compilação local
├── alunos.txt              # "Base de dados" persistente
├── aluno/
│   ├── aluno.c             # Lógica e regras de negócio relativas aos alunos
│   └── aluno.h
├── arquivo/
│   ├── arquivo.c           # Manipulação de ficheiros via C
│   └── arquivo.h
└── interface/
    ├── interface.c         # Menus e interação direta com o utilizador
    └── interface.h
```
