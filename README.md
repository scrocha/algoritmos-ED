# Tarefa de Estrutura de Dados

## Alunos
- Matheus Fillype Ferreira de Carvalho - Ciência de Dados
- Sillas Rocha da Costa - Ciência de Dados

## Organização do Repositório

Este repositório contém a implementação de algoritmos de estrutura de dados em C++. Abaixo está a organização dos diretórios e arquivos:

### `arvore/`
Este diretório contém as implementações e definições relacionadas às árvores.

- `arvores.h` e `arvores.tpp`: Arquivos de cabeçalho e implementação para as operações básicas com árvores.
- `bfsSearch.h` e `bfsSearch.tpp`: Arquivos de cabeçalho e implementação para a busca em largura (Breadth-First Search).
- `dfsSearch.h` e `dfsSearch.tpp`: Arquivos de cabeçalho e implementação para a busca em profundidade (Depth-First Search).
- `main.cpp`: Arquivo principal para execução dos testes e demonstrações das árvores.

### `code/`
Este diretório contém as implementações e definições de vários algoritmos de ordenação.

- `bubbleSort.h` e `bubbleSort.tpp`: Arquivos de cabeçalho e implementação do algoritmo Bubble Sort.
- `insertionSort.h` e `insertionSort.tpp`: Arquivos de cabeçalho e implementação do algoritmo Insertion Sort.
- `listNodes.h`: Arquivo de cabeçalho para a estrutura de lista de nós.
- `main.cpp`: Arquivo principal para execução dos testes e demonstrações dos algoritmos de ordenação.
- `radixSort.h` e `radixSort.tpp`: Arquivos de cabeçalho e implementação do algoritmo Radix Sort.
- `selectionSort.h` e `selectionSort.tpp`: Arquivos de cabeçalho e implementação do algoritmo Selection Sort.

### `data/`
Este diretório contém arquivos CSV com dados de desempenho dos algoritmos.

- `tempo_lista_10000.csv`: Dados de desempenho para listas com 10.000 elementos.
- `timeLista.csv`: Dados de desempenho gerais para diferentes listas.
- `timeTree.csv`: Dados de desempenho para operações com árvores.

### Arquivos de configuração
- `.gitignore`: Arquivo para especificar quais arquivos ou diretórios devem ser ignorados pelo Git.
- `LICENSE`: Arquivo de licença do projeto.
- `README.md`: Este arquivo, fornecendo uma visão geral do repositório.

## Como executar
Para compilar e executar os códigos fornecidos, utilize um compilador C++ (como g++) e execute os arquivos `main.cpp` dentro dos diretórios `arvore` e `code`.

### Exemplo de compilação e execução
No terminal, navegue até o diretório `arvore` ou `code` e execute os comandos:

```sh
g++ -o main main.cpp
./main
```