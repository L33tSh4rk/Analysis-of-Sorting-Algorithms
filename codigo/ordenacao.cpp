#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <filesystem>
#include <fstream>
#include "ordenacao.h"

// Retorna o índice do maior elemento no intervalo [ini, fim] do vetor v.
int max(float* v, int ini, int fim, Contador& c){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        c.comparacoes++; // Incrementa o contador de comparações a cada comparação realizada.
        if(v[i] > v[maior])
            maior = i;
    }
    return maior;
}

// Troca os elementos nas posições a e b do vetor v.
void troca(float* v, int a, int b, Contador& c){
    float aux = v[a];
    v[a] = v[b];
    v[b] = aux;
    c.trocas++; // Incrementa o contador de trocas.
}

// Implementação do Selection Sort (Ordenação por Seleção).
// Encontra o maior elemento da parte não ordenada e o coloca na posição correta no final.
void SelectionSort(float* v, int n, Contador& c){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i, c); // Encontra o maior elemento entre 0 e i.
        troca(v, pmaior, i, c);       // Coloca o maior na posição correta (final da parte não ordenada).
    }
}

// Versão otimizada do Selection Sort.
// Só realiza a troca se o maior elemento não estiver já na posição correta.
void SelectionSortOpt(float* v, int n, Contador& c){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i, c);
        if (pmaior != i) // Evita troca desnecessária
            troca(v, pmaior, i, c);
    }
}

// Implementação do Bubble Sort (Ordenação por Flutuação).
// Compara pares de elementos adjacentes e os troca se estiverem fora de ordem.
void BubbleSort(float* v, int n, Contador& c) {
    for(int j = n-1; j > 0; j--) {
        for(int i = 0; i < j; i++) {
            c.comparacoes++; // Incrementa o contador de comparações a cada comparação realizada.
            if(v[i] > v[i + 1])
                troca(v, i, i+1, c);
        }
    }
}

// Versão otimizada do Bubble Sort.
// Se em uma passada completa não houver trocas, o vetor já está ordenado e o algoritmo encerra.
void BubbleSortOpt(float* v, int n, Contador& c) {
    bool trocou;
    for(int j = n - 1; j > 0; j--) {
        trocou = false;
        for(int i = 0; i < j; i++) {
            c.comparacoes++;            // Incrementa o contador de comparações a cada comparação realizada.
            if(v[i] > v[i + 1]) {
                troca(v, i, i + 1, c);
                trocou = true;
            }
        }
        if(!trocou) break;              // termina cedo se não houve trocas.
    }
}

// Função auxiliar do Insertion Sort.
// Insere o elemento v[k] na posição correta na parte ordenada do vetor (v[0..k-1]).
void insertion(float* v, int k, Contador& c) {
    float x = v[k];
    int i = k - 1;
    while(i >= 0) {
        c.comparacoes++;    // Incrementa o contador de comparações a cada comparação realizada.
        if(v[i] > x) {
            v[i+1] = v[i];  // Desloca elemento maior.
            c.trocas++;     // Incrementa o contador de trocas.
            i--;
        } else break;
    }
    v[i+1] = x;             // Insere o elemento na posição correta.
}

// Implementação do Insertion Sort (Ordenação por Inserção).
// Percorre o vetor a partir do segundo elemento, inserindo cada um na posição correta da parte já ordenada.
void InsertionSort(float* v, int n, Contador& c) {
    for (int j = 1; j < n; j++) {
        insertion(v, j, c);
    }
}


void medirTempo(const std::string& nomeAlg, 
               void (*alg)(float*, int, Contador&),
               const std::vector<float>& dados,
               const std::string& nomeArquivo) 
{
    // Cria cópia dos dados para ordenação
    std::vector<float> copia = dados;
    Contador cont;
    
    // Executa e mede o tempo
    auto inicio = std::chrono::high_resolution_clock::now();
    alg(copia.data(), static_cast<int>(copia.size()), cont);
    auto fim = std::chrono::high_resolution_clock::now();
    
    // Mostra resultados no console
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    long long tempo = duracao.count();

    std::cout << "\n┌───────────────────────────────────────┐" << std::endl;
    std::cout << "   Resultados do " << nomeAlg << std::endl;
    std::cout << "├───────────────────────────────────────┤" << std::endl;
    std::cout << "   Tempo de execução: " << tempo << "ms" << std::endl;
    std::cout << "   Comparações:      " << cont.comparacoes << std::endl;
    std::cout << "   Trocas:           " << cont.trocas << std::endl;
    std::cout << "└───────────────────────────────────────┘" << std::endl;
    
    // Salva os resultados no arquivo resultado.csv para geração dos gráficos.
    std::ofstream saida("resultados.csv", std::ios::app);
    if (saida.is_open()) {
        saida << nomeAlg << "," << nomeArquivo << "," << tempo << "," 
              << cont.comparacoes << "," << cont.trocas << "\n";
        saida.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo resultados.csv para escrita.\n";
    }
}

