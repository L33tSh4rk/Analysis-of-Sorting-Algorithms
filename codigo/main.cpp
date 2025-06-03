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
                    SelectionSort(copia.data(), copia.size(), c);
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\n\n┌───────────────────────────────────────┐" << endl;
                    cout << "   Valor alvo (meio do vetor): " << alvo << endl;
                    cout << "├───────────────────────────────────────┤" << endl;

                    // Busca Sequencial
                    auto [posSeq, tempoSeq, compSeq] = executar_busca_sequencial(copia, alvo);
                    cout << "   BUSCA SEQUENCIAL" << endl;
                    cout << "   Posição:       " << (posSeq != -1 ? to_string(posSeq) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoSeq << "ms" << endl;
                    cout << "   Comparações:   " << compSeq << endl;


                    // Busca Binária
                    auto [posBin, tempoBin, compBin] = executar_busca_binaria(copia, alvo);
                    cout << "├───────────────────────────────────────┤" << endl;
                    cout << "   BUSCA BINÁRIA" << endl;
                    cout << "   Posição:       " << (posBin != -1 ? to_string(posBin) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoBin << "ms" << endl;
                    cout << "   Comparações:   " << compBin << endl;
                    cout << "└───────────────────────────────────────┘" << endl << endl;

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
                    SelectionSort(copia.data(), copia.size(), c);
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\n\n┌───────────────────────────────────────┐" << endl;
                    cout << "   Valor alvo (meio do vetor): " << alvo << endl;
                    cout << "├───────────────────────────────────────┤" << endl;

                    // Busca Sequencial
                    auto [posSeq, tempoSeq, compSeq] = executar_busca_sequencial(copia, alvo);
                    cout << "   BUSCA SEQUENCIAL" << endl;
                    cout << "   Posição:       " << (posSeq != -1 ? to_string(posSeq) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoSeq << "ms" << endl;
                    cout << "   Comparações:   " << compSeq << endl;


                    // Busca Binária
                    auto [posBin, tempoBin, compBin] = executar_busca_binaria(copia, alvo);
                    cout << "├───────────────────────────────────────┤" << endl;
                    cout << "   BUSCA BINÁRIA" << endl;
                    cout << "   Posição:       " << (posBin != -1 ? to_string(posBin) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoBin << "ms" << endl;
                    cout << "   Comparações:   " << compBin << endl;
                    cout << "└───────────────────────────────────────┘" << endl << endl;

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
                    SelectionSort(copia.data(), copia.size(), c);
                    
                    float alvo = dados[dados.size() / 2];
                    cout << "\n\n┌───────────────────────────────────────┐" << endl;
                    cout << "   Valor alvo (meio do vetor): " << alvo << endl;
                    cout << "├───────────────────────────────────────┤" << endl;

                    // Busca Sequencial
                    auto [posSeq, tempoSeq, compSeq] = executar_busca_sequencial(copia, alvo);
                    cout << "   BUSCA SEQUENCIAL" << endl;
                    cout << "   Posição:       " << (posSeq != -1 ? to_string(posSeq) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoSeq << "ms" << endl;
                    cout << "   Comparações:   " << compSeq << endl;


                    // Busca Binária
                    auto [posBin, tempoBin, compBin] = executar_busca_binaria(copia, alvo);
                    cout << "├───────────────────────────────────────┤" << endl;
                    cout << "   BUSCA BINÁRIA" << endl;
                    cout << "   Posição:       " << (posBin != -1 ? to_string(posBin) : "Não encontrado") << endl;
                    cout << "   Tempo:         " << tempoBin << "ms" << endl;
                    cout << "   Comparações:   " << compBin << endl;
                    cout << "└───────────────────────────────────────┘" << endl << endl;

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
