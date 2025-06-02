#include <iostream>
#include <ctime>
#include <cstdlib>
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