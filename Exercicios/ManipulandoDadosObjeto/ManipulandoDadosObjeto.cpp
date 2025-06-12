#include <iostream>

/**
 * @class Numero
 * @brief Uma classe simples para armazenar e imprimir um valor inteiro.
 */
class Numero {
private:
    int valor; // Atributo para armazenar o número inteiro.

public:
    /**
     * @brief Construtor da classe Numero.
     * @param v O valor inicial para o atributo 'valor'.
     */
    Numero(int v) : valor(v) {}

    /**
     * @brief Imprime o valor do atributo 'valor' na tela.
     */
    void imprimeValor() {
        std::cout << "O valor do atributo é: " << this->valor << std::endl;
    }

    /**
     * @brief Imprime o endereço de memória do objeto atual.
     */
    void imprimeEndereco() {
        // Em C++, 'this' é um ponteiro para o objeto atual.
        // Imprimi-lo diretamente nos mostra o endereço de memória.
        std::cout << "O endereço de memória do objeto é: " << this << std::endl;
    }
};

/**
 * @brief Função principal onde o programa começa a execução.
 */
int main() {
    // Define a localidade para português para correta acentuação no console.
    setlocale(LC_ALL, "Portuguese");

    // 1. Cria uma instância (objeto) da classe Numero.
    // O valor 42 é passado para o construtor para inicializar o atributo.
    Numero meuNumero(42);

    // 2. Chama o método para imprimir o valor do atributo.
    meuNumero.imprimeValor();

    // 3. Simula a ideia de "endereço de memória" chamando o método correspondente.
    meuNumero.imprimeEndereco();

    return 0;
}