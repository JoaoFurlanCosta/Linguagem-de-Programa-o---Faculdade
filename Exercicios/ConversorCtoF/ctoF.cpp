#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>

using namespace std;

class ConversorTemperatura {
public:
    double celsiusParaFahrenheit(double celsius) {
        return (celsius * 9.0 / 5.0) + 32.0;
    }
    double fahrenheitParaCelsius(double fahrenheit) {
        return (fahrenheit - 32.0) * 5.0 / 9.0;
    }
};

void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    #ifdef _WIN32
        setlocale(LC_ALL, "Portuguese_Brazil.1252");
    #else
        setlocale(LC_ALL, "pt_BR.UTF-8");
    #endif

    ConversorTemperatura conversor;
    int escolha;
    while (true) {
        cout << "\n--- Conversor de Temperatura ---" <<endl;
        cout << "1: Celsius para Fahrenheit" <<endl;
        cout << "2: Fahrenheit para Celsius" <<endl;
        cout << "0: Sair" <<endl;
        cout << "Escolha a direcao da conversao (1, 2 ou 0): ";

        if (!(cin >> escolha)) {
            cout << "Opcao invalida. Por favor, digite um numero." << endl;
            limparBufferEntrada();
            continue;
        }

        if (escolha == 0) {
            cout << "Encerrando o programa." << endl;
            break;
        }

        double temperatura;
        switch (escolha) {
            case 1: {
                cout << "Digite a temperatura em Celsius: ";
                if (!(cin >> temperatura)) {
                    cout << "Entrada invalida. Por favor, insira um numero." << endl;
                    limparBufferEntrada();
                    continue;
                }
                double fahrenheit = conversor.celsiusParaFahrenheit(temperatura);
                cout << fixed << setprecision(2)
                          << "Resultado: " << temperatura << "°C equivalem a " << fahrenheit << "°F" << endl;
                break;
            }
            case 2: {
                cout << "Digite a temperatura em Fahrenheit: ";
                if (!(cin >> temperatura)) {
                    cout << "Entrada invalida. Por favor, insira um numero." << endl;
                    limparBufferEntrada();
                    continue;
                }
                double celsius = conversor.fahrenheitParaCelsius(temperatura);
                cout << fixed << setprecision(2)
                          << "Resultado: " << temperatura << "°F equivalem a " << celsius << "°C" << endl;
                break;
            }
            default:
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
                break;
        }
    }

    return 0;
}