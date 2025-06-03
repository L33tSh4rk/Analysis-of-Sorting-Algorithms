#ifndef ORDENACAO_H
#define ORDENACAO_H

struct Contador {
    long comparacoes = 0;
    long trocas = 0;
};

void SelectionSort(float* v, int n, Contador& c);
void SelectionSortOpt(float* v, int n, Contador& c);
void BubbleSort(float* v, int n, Contador& c);
void BubbleSortOpt(float* v, int n, Contador& c);
void InsertionSort(float* v, int n, Contador& c);
void medirTempo(const std::string& nomeAlg, 
               void (*alg)(float*, int, Contador&),
               const std::vector<float>& dados,
               const std::string& nomeArquivo);


#endif 