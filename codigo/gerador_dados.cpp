#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cerrno>
#include <cstring>

// Função que cria um arquivo binário com 'tamanho' números float aleatórios.
void criar_arquivo(const std::string& caminho, size_t tamanho) {
    // Abre o arquivo para escrita em modo binário.
    std::ofstream arquivo(caminho, std::ios::binary);

    // Verifica se o arquivo foi aberto corretamente.
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao criar o arquivo '" << caminho << "': "
                  << std::strerror(errno) << std::endl;
        return; // Encerra a função se não conseguiu abrir o arquivo.
    }

    // Inicializa o gerador de números aleatórios.
    std::random_device rd;                                   // Fonte de entropia (aleatoriedade).
    std::mt19937 gen(rd());                                  // Gerador Mersenne Twister com semente aleatória.
    std::uniform_real_distribution<float> dist(-1e6f, 1e6f); // Gera floats entre -1.000.000 e 1.000.000

    // Gera 'tamanho' números aleatórios e grava no arquivo.
    for (size_t i = 0; i < tamanho; ++i) {
        float valor = dist(gen);                                             // Gera um número aleatório.
        arquivo.write(reinterpret_cast<const char*>(&valor), sizeof(float)); // Escreve o número no arquivo como bytes binários.
    }

    // Fecha o arquivo.
    arquivo.close();
    std::cout << "Arquivo '" << caminho << "' criado com " << tamanho << " floats." << std::endl;
}

int gerar() {
    criar_arquivo("../dados/pequeno.bin", 25'000);
    criar_arquivo("../dados/medio.bin",   110'000);
    criar_arquivo("../dados/grande.bin", 270'000);
    return 0;
}