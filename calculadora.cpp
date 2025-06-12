// Calculadora.cpp

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <locale>


class Calculadora {
    private:
    float resultado;

    public:
        Calculadora();

    float getResultado() {return this->resultado;}

    // void setNumero1(float numero1) {this->numero1 = numero1;}
    // void setNumero2(float numero2) {this->numero2 = numero2;}
    // void setResultado(float resultado) {this->resultado = resultado;}

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
    this->resultado = numero1 / numero2;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
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

        // Se o usuário digitar 0, ele sai do loop, então não precisamos pedir os números.
        if (operacao == 0) {
            cout << "Saindo da calculadora. Até mais!" << endl;
            break; // Sai do loop do-while
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
                // A mensagem de erro para divisão por zero já está na função dividir.
                // Aqui apenas mostra o resultado se a divisão for válida.
                if (numero2 != 0) {
                    cout << "Resultado da Divisão: " << calcul.getResultado() << endl;
                }
                break;
            default:
                cout << "Opção inválida. Por favor, escolha uma operação entre 0 e 4." << endl;
                break;
        }

    } while (operacao != 0); // O loop continua enquanto 'operacao' não for 0.

    return 0;
}