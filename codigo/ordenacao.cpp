#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <filesystem>
#include <fstream>
#include "ordenacao.h"

int max(float* v, int ini, int fim, Contador& c){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        c.comparacoes++;
        if(v[i] > v[maior])
            maior = i;
    }
    return maior;
}

void troca(float* v, int a, int b, Contador& c){
    float aux = v[a];
    v[a] = v[b];
    v[b] = aux;
    c.trocas++;
}

void SelectionSort(float* v, int n, Contador& c){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i, c);
        troca(v, pmaior, i, c);
    }
}

void SelectionSortOpt(float* v, int n, Contador& c){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i, c);
        // Só troca se os índices forem diferentes
        if (pmaior != i)
            troca(v, pmaior, i, c);
    }
}

void BubbleSort(float* v, int n, Contador& c) {
    for(int j = n-1; j > 0; j--) {
        for(int i = 0; i < j; i++) {
            c.comparacoes++;
            if(v[i] > v[i + 1])
                troca(v, i, i+1, c);
        }
    }
}


void BubbleSortOpt(float* v, int n, Contador& c) {
    bool trocou;
    for(int j = n - 1; j > 0; j--) {
        trocou = false;
        for(int i = 0; i < j; i++) {
            c.comparacoes++;
            if(v[i] > v[i + 1]) {
                troca(v, i, i + 1, c);
                trocou = true;
            }
        }
        if(!trocou) break; // já está ordenado
    }
}


void insertion(float* v, int k, Contador& c) {
    float x = v[k];
    int i = k - 1;
    while(i >= 0) {
        c.comparacoes++;
        if(v[i] > x) {
            v[i+1] = v[i];
            c.trocas++;
            i--;
        } else break;
    }
    v[i+1] = x;
}

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
    
    std::ofstream saida("resultados.csv", std::ios::app);
    if (saida.is_open()) {
        saida << nomeAlg << "," << nomeArquivo << "," << tempo << "," 
              << cont.comparacoes << "," << cont.trocas << "\n";
        saida.close();
    } else {
        std::cerr << "Erro ao abrir o arquivo resultados.csv para escrita.\n";
    }
}

