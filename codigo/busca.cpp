#include "busca.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>

// Implementação da busca sequencial
template <typename T>
int busca_sequencial(const std::vector<T>& vetor, const T& alvo, int& comparacoes) {
    comparacoes = 0; // Resetar contador
    for (size_t it = 0; it < vetor.size(); it++) {
        comparacoes++; // Conta cada comparação
        if (vetor[it] == alvo) {
            return static_cast<int>(it);
        }
    }
    return -1;
}

//Implementação da busca binária
template <typename T>
int busca_binaria(const std::vector<T>& vetor, const T& alvo, int& comparacoes) {
    comparacoes = 0; // Resetar contador
    int esq = 0;
    int dir = static_cast<int>(vetor.size()) - 1;

    while (esq <= dir) {
        comparacoes++; // Conta a comparação do while
        int meio = esq + (dir - esq) / 2;

        comparacoes++; // Conta a próxima comparação
        if (vetor[meio] == alvo) {
            return meio;
        } else if (vetor[meio] < alvo) {
            comparacoes++; // Conta a comparação do else if
            esq = meio + 1;
        } else {
            dir = meio - 1;
        }
    }
    return -1;
}


/*=====================================*/
/*         Busca Sequencial            */
/*=====================================*/

template <typename T>
std::tuple<int, double, int> executar_busca_sequencial(const std::vector<T>& vetor, const T& alvo) {
    auto inicio = std::chrono::high_resolution_clock::now();
    int comparacoes = 0;
    int posicao = busca_sequencial(vetor, alvo, comparacoes);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duracao = fim - inicio;
    return {posicao, duracao.count(), comparacoes};
}

/*=====================================*/
/*            Busca Binária            */
/*=====================================*/

template <typename T>
std::tuple<int, double, int> executar_busca_binaria(const std::vector<T>& vetor, const T& alvo) {
    auto inicio = std::chrono::high_resolution_clock::now();
    int comparacoes = 0;
    int posicao = busca_binaria(vetor, alvo, comparacoes);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> duracao = fim - inicio;
    return {posicao, duracao.count(), comparacoes};
}


/*=====================================*/
// Instanciação explícita para float   //(para o linker encontrar as implementações e não retornar referência indefinida)
/*=====================================*/

template int busca_sequencial<float>(const std::vector<float>&, const float&, int&);
template int busca_binaria<float>(const std::vector<float>&, const float&, int&);
template std::tuple<int, double, int> executar_busca_sequencial<float>(const std::vector<float>&, const float&);
template std::tuple<int, double, int> executar_busca_binaria<float>(const std::vector<float>&, const float&);



/*=====================================*/
/*            Leitor Arquivo           */
/*=====================================*/

std::vector<float> ler_arquivo(const std::string& caminho) {
    // Abre o arquivo em modo binário
    std::ifstream arquivo(caminho, std::ios::binary);
    
    // Verifica se o arquivo foi aberto corretamente
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo '" << caminho << "': " 
                 << std::strerror(errno) << std::endl;
        exit(1); // Encerra o programa com erro
    }

    // Obtém o tamanho do arquivo
    arquivo.seekg(0, std::ios::end); // Vai para o final
    std::streampos tamanho = arquivo.tellg(); // Obtém a posição (tamanho)
    arquivo.seekg(0, std::ios::beg); // Volta para o início

    // Calcula quantos floats existem no arquivo
    size_t num_floats = tamanho / sizeof(float);
    std::vector<float> dados(num_floats); // Cria vetor com tamanho calculado

    // Lê os dados binários diretamente para o vetor
    arquivo.read(reinterpret_cast<char*>(dados.data()), tamanho);
    
    // Verifica se a leitura foi completa
    if (!arquivo) {
        std::cerr << "Erro ao ler o arquivo '" << caminho << "': " 
                 << std::strerror(errno) << std::endl;
        exit(1);
    }

    arquivo.close();
    return dados;
}


/*=====================================*/
/*            Salvar Arquivo           */
/*=====================================*/

void salvar_arquivo(const std::string& caminho, const std::vector<float>& dados) {
    std::ofstream arquivo(caminho, std::ios::binary);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao criar o arquivo '" << caminho << "': " 
                 << std::strerror(errno) << std::endl;
        exit(1);
    }

    // Escreve os dados binários diretamente do vetor
    arquivo.write(reinterpret_cast<const char*>(dados.data()), 
                dados.size() * sizeof(float));
    
    // Verifica se a escrita foi bem-sucedida
    if (!arquivo) {
        std::cerr << "Erro ao escrever no arquivo '" << caminho << "': " 
                 << std::strerror(errno) << std::endl;
        exit(1);
    }

    arquivo.close();
}

