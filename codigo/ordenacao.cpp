#include <iostream>
#include <ctime>
#include <cstdlib>

int max(int *v, int ini, int fim ){
    int maior = ini;
    for(int i = ini+1; i <= fim; i++){
        if(v[i] > v[maior])
            maior = i;
    }
    return maior;
}

void troca(int *v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

void SelectionSort(int *v, int n){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i);
        troca(v, pmaior, i);
    }
}   

void SelectionSortOpt(int *v, int n){
    for(int i = n-1; i > 0; i--){
        int pmaior = max(v, 0, i);
        // Só troca se os índices forem diferentes
        if (pmaior != i)
            troca(v, pmaior, i);
    }
}

void BubbleSort(int *v, int n) {
    for(int j = n-1; j > 0; j--) {
        for(int i = 0; i < j; i++) {
            if(v[i] > v[i + 1])
                troca(v, i, i+1);
        }
    }
}


void BubbleSortOpt(int *v, int n) {
    bool trocou;
    for(int j = n - 1; j > 0; j--) {
        trocou = false;
        for(int i = 0; i < j; i++) {
            if(v[i] > v[i + 1]) {
                troca(v, i, i + 1);
                trocou = true;
            }
        }
        if(!trocou) break; // já está ordenado
    }
}


void insertion(int* v, int k) {
    int i = k - 1;
    int x = v[k];
    while((i> 0) && (v[i] > x)) {
        v[i+1] = v[i];
        i--;
    }
    v[i + 1] = x;
}

void InsertionSort(int* v, int n) {
    for (int j = 1; j < n; j++) {
        insertion(v, j);
    }
}