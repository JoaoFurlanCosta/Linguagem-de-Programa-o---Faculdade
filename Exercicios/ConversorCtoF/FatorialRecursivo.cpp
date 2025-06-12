#include <iostream>
#include <stdexcept>
#include <limits>

class Fatorial {
public:
    unsigned long long calcular(int n) {
        if (n < 0) {
            throw std::invalid_argument("Fatorial nao definido para numeros negativos.");
        }
        if (n == 0) {
            return 1;
        }
        return static_cast<unsigned long long>(n) * calcular(n - 1);
    }
};

int main() {
    using namespace std;
#ifdef _WIN32
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
#else
    setlocale(LC_ALL, "pt_BR.UTF-8");
#endif

    int numero;
    Fatorial calculadora;

    cout << "Digite um numero inteiro nao negativo: ";

    while (!(cin >> numero)) {
        cout << "Entrada invalida. Por favor, digite um numero inteiro: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    try {
        unsigned long long resultado = calculadora.calcular(numero);
        cout << "O fatorial de " << numero << " e " << resultado << std::endl;
    } catch (const std::invalid_argument& e) {
        cerr << "Erro: " << e.what() << std::endl;
    }

    return 0;
}