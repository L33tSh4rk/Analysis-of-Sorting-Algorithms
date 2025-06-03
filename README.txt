# Análise de Algoritmos de Ordenação

Este projeto implementa cinco algoritmos de ordenação:
- SelectionSort
- SelectionSort Otimizado
- BubbleSort
- BubbleSort Otimizado
- InsertionSort

e duas buscas:
- Sequencial
- Binária

Mede o tempo de execução, número de comparações e trocas para diferentes tamanhos de arquivos de dados armazenados em binários. Também gera gráficos para análise dos resultados.

## Estrutura do Projeto

- Código fonte em C++: main.cpp, ordenacao.cpp, busca.cpp, gerador_dados.cpp
- Makefile para compilar o projeto
- Arquivos de dados binários: pequeno.bin, medio.bin, grande.bin
- Scripts em Python para gerar gráficos a partir dos resultados CSV
- Resultados armazenados em arquivos CSV
- Imagens geradas dos gráficos em pasta `../images/`

## Compilação

Para compilar o programa, use o comando:

```
make
´´´
