#include "busca.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>

// Implementação da busca sequencial
template <typename T>
int busca_sequencial(const std::vector<T>& vetor, const T& alvo) {
    for (size_t it = 0; it < vetor.size(); it++) {
        if (vetor[it] == alvo) {
            return static_cast<int>(it); // Retorna o índice se encontrado
        }
    }
    return -1; // Não encontrado
}

//Implementação da busca binária
template <typename T>
int busca_binaria(const std::vector<T>& vetor, const T& alvo) {
    int esq = 0;
    int dir = static_cast<int>(vetor.size()) - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2; // Ponto médio (evita overflow)

        if (vetor[meio] == alvo) {
            return meio; // Elemento encontrado
        } else if (vetor[meio] < alvo) {
            esq = meio + 1; // Busca na metade direita
        } else {
            dir = meio - 1; // Busca na metade esquerda
        }
    }
    return -1; // Não encontrado
}


/*=====================================*/
/*         Busca Sequencial            */
/*=====================================*/

template <typename T>
std::pair<int, double> executar_busca_sequencial(const std::vector<T>& vetor, const T& alvo) {
    auto inicio = std::chrono::high_resolution_clock::now(); // Marca o início
    int posicao = busca_sequencial(vetor, alvo); // Executa a busca
    auto fim = std::chrono::high_resolution_clock::now(); // Marca o fim

    // Calcula a duração em segundos
    std::chrono::duration<double> duracao = fim - inicio;
    return {posicao, duracao.count()};
}

/*=====================================*/
/*            Busca Binária            */
/*=====================================*/

template <typename T>
std::pair<int, double> executar_busca_binaria(const std::vector<T>& vetor, const T& alvo) {
    auto inicio = std::chrono::high_resolution_clock::now();
    int posicao = busca_binaria(vetor, alvo);
    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;
    return {posicao, duracao.count()};
}


/*=====================================*/
// Instanciação explícita para float   //(para o linker encontrar as implementações e não retornar referência indefinida)
/*=====================================*/

template int busca_sequencial<float>(const std::vector<float>&, const float&);
template int busca_binaria<float>(const std::vector<float>&, const float&);
template std::pair<int, double> executar_busca_sequencial<float>(const std::vector<float>&, const float&);
template std::pair<int, double> executar_busca_binaria<float>(const std::vector<float>&, const float&);



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

