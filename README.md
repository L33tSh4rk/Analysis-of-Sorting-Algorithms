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
```

isso gera o executável `programa`;

Para limpar os arquivos objeto e o executável, use:

```
make clean
```

## Execução

Após compilação, execute o programa com:

```
./programa
```

O programa executa os algoritmos e gera os arquivos de resultados.

## Geração dos Gráficos

Utilize o script Python `graficos.py` para ler os arquivos CSV gerados e criar gráficos de barras com:

```
python3 graficos.py
```

Os gráficos serão salvos na pasta `../images/`.

## Dependências

- Python 3
- Pandas (`pip install pandas`) - caso não queira usar pip, instale manualmente via repositórios do sistema.
- Matplotlib (`pip install matplotlib`)

## Observações

- Certifique-se que os arquivos binários de dados estão no caminho correto para serem lidos pelo programa.
- Os gráficos gerados facilitam a comparação visual do desempenho dos algoritmos e buscas em diferentes tamanhos de arquivos.
