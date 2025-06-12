#include <iostream>
#include <math.h>
#include <stdio.h>

class Calculadora {
    private:
    float resultado;

    public:
        Calculadora();

    float getResultado() {return this->resultado;}

    void soma(float numero1, float numero2);
    void subtracao(float numero1, float numero2);
    void multiplicacao(float numero1, float numero2);
    void dividir(float numero1, float numero2);
};

Calculadora::Calculadora() {
    this->resultado = 0;
}

void Calculadora::soma(float numero1, float numero2) {
    this->resultado = numero1 + numero2;
}

void Calculadora::subtracao(float numero1, float numero2) {
    this->resultado = numero1 - numero2;
}

void Calculadora::multiplicacao(float numero1, float numero2) {
    this->resultado = numero1 * numero2;
}

void Calculadora::dividir(float numero1, float numero2) {
    if (numero2 != 0) {
        this->resultado = numero1 / numero2;
    } else {
        std::cout << "Erro: Divisão por zero!" << std::endl;
        this->resultado = 0;
    }
}

int main() {
    using namespace std;
    float numero1;
    float numero2;
    int operacao;
    Calculadora calcul;

    do {
        cout << "\n--- Selecione a operação: ---" << endl;
        cout << " 1 - Soma" << endl;
        cout << " 2 - Subtração" << endl;
        cout << " 3 - Multiplicação" << endl;
        cout << " 4 - Divisão" << endl;
        cout << " 0 - Sair" << endl;
        cout << "\n Digite sua opção: ";
        cin >> operacao;


        if (operacao == 0) {
            cout << "Saindo da calculadora. Até mais!" << endl;
            break;
        }

        // Pedir os números apenas se uma operação válida for selecionada
        cout << "Digite o primeiro valor: ";
        cin >> numero1;
        cout << "Digite o segundo valor: ";
        cin >> numero2;

        switch (operacao) {
            case 1:
                calcul.soma(numero1, numero2);
                cout << "Resultado da Soma: " << calcul.getResultado() << endl;
                break;
            case 2:
                calcul.subtracao(numero1, numero2);
                cout << "Resultado da Subtração: " << calcul.getResultado() << endl;
                break;
            case 3:
                calcul.multiplicacao(numero1, numero2);
                cout << "Resultado da Multiplicação: " << calcul.getResultado() << endl;
                break;
            case 4:
                calcul.dividir(numero1, numero2);
                if (numero2 != 0) {
                    cout << "Resultado da Divisão: " << calcul.getResultado() << endl;
                }
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma operação entre 0 e 4." << endl;
                break;
        }

    } while (operacao != 0);

    return 0;
}