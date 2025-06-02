#ifndef BUSCAS_H
#define BUSCAS_H


#include <vector>
#include <chrono>
#include <string>
#include <utility>


/*======================*/
// Métodos para buscas  //
/*======================*/

// Busca Sequencial (básica)
template <typename T>
int busca_sequencial(const std::vector<T>& vetor, const T& alvo);

// Busca Binária (requer vetor ordenado)
template <typename T>
int busca_binaria(const std::vector<T>& vetor, const T& alvo);

// Busca Sequencial com medição de tempo
template <typename T>
std::pair<int, double> executar_busca_sequencial(const std::vector<T>& vetor, const T& alvo);

// Busca Binária com medição de tempo
template <typename T>
std::pair<int, double> executar_busca_binaria(const std::vector<T>& vetor, const T& alvo);


/*======================*/
// Métodos para arquivos//
/*======================*/

// Lê um arquivo binário de floats e retorna um vector
std::vector<float> ler_arquivo(const std::string& caminho);

// Salva um vector de floats em um arquivo binário
void salvar_arquivo(const std::string& caminho, const std::vector<float>& dados);

#endif