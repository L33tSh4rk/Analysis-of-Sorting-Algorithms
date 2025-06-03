#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
#include <vector>
#include <filesystem>

#include "busca.h"
#include "ordenacao.h"
#include "gerador_dados.h"

using namespace std;
using namespace std::chrono;

void mostrarMenu() {
    std::cout << "\n╔════════════════════════════╗" << std::endl;
    std::cout << "║        MENU PRINCIPAL      ║" << std::endl;
    std::cout << "╠════════════════════════════╣" << std::endl;
    std::cout << "║  1. Arquivo Pequeno        ║" << std::endl;
    std::cout << "║  2. Arquivo Médio          ║" << std::endl;
    std::cout << "║  3. Arquivo Grande         ║" << std::endl;
    std::cout << "║ ━━━━━━━━━━━━━━━━━━━━━━━━━━ ║" << std::endl;
    std::cout << "║  4. Gerar Arquivos Novos   ║" << std::endl;
    std::cout << "║  5. Sair                   ║" << std::endl;
    std::cout << "╚════════════════════════════╝" << std::endl;
    std::cout << "\n  ➤ Escolha uma opção: ";}

int main() {
    vector<float> dados; //vetor que lê os dados (leitura será feita dentro dos casos de escolha)

    int escolha;
    
    do {
        mostrarMenu();
        cin >> escolha;

        if (escolha >= 1 && escolha <= 4) {
            
            
            switch(escolha) {
                case 1: {
                    dados = ler_arquivo("../dados/pequeno.bin");
                    Contador c;
                    auto inicio = std::chrono::high_resolution_clock::now();
                    {   
                        vector<float> copia = dados;
                        medirTempo("SelectionSort", SelectionSort, copia, "../dados/pequeno.bin");
                        salvar_arquivo("../resultados/SelectionPequeno.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/pequeno.bin");
                        salvar_arquivo("../resultados/SelectionOptPequeno.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSort", BubbleSort, copia, "../dados/pequeno.bin");
                        salvar_arquivo("../resultados/BubblePequeno.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSortOptimized", BubbleSortOpt, copia, "../dados/pequeno.bin");
                        salvar_arquivo("../resultados/BubbleOptPequeno.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("InsertionSort", InsertionSort, copia, "../dados/pequeno.bin");
                        salvar_arquivo("../resultados/InsertionPequeno.bin", copia);
                    }
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao1 = std::chrono::duration_cast<std::chrono::seconds>(fim - inicio);
                    auto duracao2 = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
                    cout << "\nDuração completa das ordenações: " << duracao1.count() << "s (" 
                         << duracao2.count() << "ms)" << endl;
                    

                    vector<float> copia = dados;
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\nValor alvo (do meio do vetor): " << alvo << endl;

                    //Busca Sequencial
                    auto [posSeq, tempoSeq] = executar_busca_sequencial(copia, alvo);
                    if (posSeq != -1)
                        cout << "Busca Sequencial: encontrado na posição " << posSeq << " em " << tempoSeq << "s\n";
                    else
                        cout << "Busca Sequencial: valor não encontrado (tempo: " << tempoSeq << "s)\n";

                    // Ordenar antes da busca binária
                    SelectionSort(copia.data(), copia.size(), c);

                    auto [posBin, tempoBin] = executar_busca_binaria(copia, alvo);
                    if (posBin != -1)
                        cout << "Busca Binária: encontrado na posição " << posBin << " em " << tempoBin << "s\n";
                    else
                        cout << "Busca Binária: valor não encontrado (tempo: " << tempoBin << "s)\n";

                    break;  
                }

                case 2: {
                    dados = ler_arquivo("../dados/medio.bin");
                    Contador c;
                    auto inicio = std::chrono::high_resolution_clock::now();
                    {   
                        vector<float> copia = dados;
                        medirTempo("SelectionSort", SelectionSort, copia, "../dados/medio.bin");
                        salvar_arquivo("../resultados/SelectionMedio.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/medio.bin");
                        salvar_arquivo("../resultados/SelectionOptMedio.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSort", BubbleSort, copia, "../dados/medio.bin");
                        salvar_arquivo("../resultados/BubbleMedio.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSortOptimized", BubbleSortOpt, copia, "../dados/medio.bin");
                        salvar_arquivo("../resultados/BubbleOptMedio.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("InsertionSort", InsertionSort, copia, "../dados/medio.bin");
                        salvar_arquivo("../resultados/InsertionMedio.bin", copia);
                    }
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao1 = std::chrono::duration_cast<std::chrono::seconds>(fim - inicio);
                    auto duracao2 = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
                    cout << "\nDuração completa das ordenações: " << duracao1.count() << "s (" 
                         << duracao2.count() << "ms)" << endl;

                    vector<float> copia = dados;
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\nValor alvo (do meio do vetor): " << alvo << endl;

                    //Busca Sequencial
                    auto [posSeq, tempoSeq] = executar_busca_sequencial(copia, alvo);
                    if (posSeq != -1)
                        cout << "Busca Sequencial: encontrado na posição " << posSeq << " em " << tempoSeq << "s\n";
                    else
                        cout << "Busca Sequencial: valor não encontrado (tempo: " << tempoSeq << "s)\n";

                    // Ordenar antes da busca binária
                    SelectionSort(copia.data(), copia.size(), c);

                    auto [posBin, tempoBin] = executar_busca_binaria(copia, alvo);
                    if (posBin != -1)
                        cout << "Busca Binária: encontrado na posição " << posBin << " em " << tempoBin << "s\n";
                    else
                        cout << "Busca Binária: valor não encontrado (tempo: " << tempoBin << "s)\n";
                        
                    break;  
                }

                case 3: {
                    
                    dados = ler_arquivo("../dados/grande.bin");
                    Contador c;
                    auto inicio = std::chrono::high_resolution_clock::now();
                    {   
                        vector<float> copia = dados;
                        medirTempo("SelectionSort", SelectionSort, copia, "../dados/grande.bin");
                        salvar_arquivo("../resultados/SelectionGrande.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("SelectionSortOptimized", SelectionSortOpt, copia, "../dados/grande.bin");
                        salvar_arquivo("../resultados/SelectionOptGrande.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSort", BubbleSort, copia, "../dados/grande.bin");
                        salvar_arquivo("../resultados/BubbleGrande.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("BubbleSortOptimized", BubbleSortOpt, copia, "../dados/grande.bin");
                        salvar_arquivo("../resultados/BubbleOptGrande.bin", copia);
                    }
                    {
                        vector<float> copia = dados;
                        medirTempo("InsertionSort", InsertionSort, copia, "../dados/grande.bin");
                        salvar_arquivo("../resultados/InsertionGrande.bin", copia);
                    }
                    auto fim = std::chrono::high_resolution_clock::now();
                    auto duracao1 = std::chrono::duration_cast<std::chrono::seconds>(fim - inicio);
                    auto duracao2 = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
                    cout << "\nDuração completa das ordenações: " << duracao1.count() << "s (" 
                         << duracao2.count() << "ms)" << endl;

                    vector<float> copia = dados;
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\nValor alvo (do meio do vetor): " << alvo << endl;

                    //Busca Sequencial
                    auto [posSeq, tempoSeq] = executar_busca_sequencial(copia, alvo);
                    if (posSeq != -1)
                        cout << "Busca Sequencial: encontrado na posição " << posSeq << " em " << tempoSeq << "s\n";
                    else
                        cout << "Busca Sequencial: valor não encontrado (tempo: " << tempoSeq << "s)\n";

                    // Ordenar antes da busca binária
                    SelectionSort(copia.data(), copia.size(), c);

                    auto [posBin, tempoBin] = executar_busca_binaria(copia, alvo);
                    if (posBin != -1)
                        cout << "Busca Binária: encontrado na posição " << posBin << " em " << tempoBin << "s\n";
                    else
                        cout << "Busca Binária: valor não encontrado (tempo: " << tempoBin << "s)\n";
                        
                    break;  
                }

                case 4: {
                    gerar();
                    break;
                }
                
            }
        }

    } while (escolha != 5);
    std::cout << "\n Finalizando sessão..." << std::endl;
    std::cout << "\n╔════════════════════════════╗" << std::endl;
    std::cout << "║    Programa encerrado      ║" << std::endl;
    std::cout << "╚════════════════════════════╝" << std::endl << std::endl;

    return 0;
}
