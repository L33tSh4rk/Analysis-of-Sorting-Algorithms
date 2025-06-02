#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include <vector>

#include "busca.h"
#include "ordenacao.h"

using namespace std;
using namespace std::chrono;

void mostrarMenu(){

    std::cout << "\n===== MENU =====" << std::endl;
    std::cout << "1. Arquivo Pequeno" << std::endl;
    std::cout << "2. Arquivo Médio" << std::endl;
    std::cout << "3. Arquivo Grande" << std::endl;
    std::cout << "4. Sair" << std::endl;
    
    std::cout << "Escolha o arquivo que deseja ler: " << std::endl;
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
    std::cout << "\n=== " << nomeAlg << " ==="
              << "\nTempo: " << duracao.count() << " ms"
              << "\nComparações: " << cont.comparacoes
              << "\nTrocas: " << cont.trocas << std::endl;
    
    // Salva os dados ordenados
    std::string caminho_saida = "../resultados/" + nomeAlg + "_" + nomeArquivo;
    salvar_arquivo(caminho_saida, copia);
    std::cout << "Arquivo salvo: " << caminho_saida << std::endl;
}



int main() {
    vector<float> dados; //vetor que lê os dados (leitura será feita dentro dos casos de escolha)

    int escolha;
    float alvo;

    do {
        mostrarMenu();
        cin >> escolha;

        if (escolha >= 1 && escolha <= 4) {
            
            
            switch(escolha) {
                case 1: {
                    dados = ler_arquivo("../dados/pequeno.bin");

                    vector<float> copia(dados.begin(), dados.end());
                    
                    medirTempo("SelectionSort", SelectionSort, copia, "../dados/pequeno.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/pequeno.bin");
                    medirTempo("BubbleSort", BubbleSort, copia, "../dados/pequeno.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/pequeno.bin");
                    medirTempo("InsertionSort", InsertionSort, copia, "../dados/pequeno.bin");
                    
                }

                case 2: {
                    dados = ler_arquivo("../dados/pequeno.bin");
                    
                    vector<float> copia(dados.begin(), dados.end());
                    
                    medirTempo("SelectionSort", SelectionSort, copia, "../dados/medio.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/medio.bin");
                    medirTempo("BubbleSort", BubbleSort, copia, "../dados/medio.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/medio.bin");
                    medirTempo("InsertionSort", InsertionSort, copia, "../dados/medio.bin");

                }

                case 3: {
                    dados = ler_arquivo("../dados/pequeno.bin");
                    
                    vector<float> copia(dados.begin(), dados.end());
                    
                    medirTempo("SelectionSort", SelectionSort, copia, "../dados/grande.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/grande.bin");
                    medirTempo("BubbleSort", BubbleSort, copia, "../dados/grande.bin");
                    medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/grande.bin");
                    medirTempo("InsertionSort", InsertionSort, copia, "../dados/grande.bin");

                
                }

                case 4: {
                    cout << "Saindo do Programa..." << endl;
                    return 0;
                }
                default: {
                    cout << "Opção Invalida" << endl;
                }
            }
        }

    } while (escolha != 4);

    return 0;
}
