#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <cerrno>
#include <cstring>

void criar_arquivo(const std::string& caminho, size_t tamanho) {
    std::ofstream arquivo(caminho, std::ios::binary);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao criar o arquivo '" << caminho << "': "
                  << std::strerror(errno) << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(-1e6f, 1e6f);

    for (size_t i = 0; i < tamanho; ++i) {
        float valor = dist(gen);
        arquivo.write(reinterpret_cast<const char*>(&valor), sizeof(float));
    }

    arquivo.close();
    std::cout << "Arquivo '" << caminho << "' criado com " << tamanho << " floats." << std::endl;
}

int main() {
    criar_arquivo("../dados/pequeno.bin", 100'000);
    criar_arquivo("../dados/medio.bin",   2'000'000);
    criar_arquivo("../dados/grande.bin", 10'000'000);
    return 0;
}