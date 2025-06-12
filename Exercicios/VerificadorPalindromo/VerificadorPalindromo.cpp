#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>

using namespace std;

class VerificadorPalindromo {
public:
    VerificadorPalindromo() = default;
    bool ehPalindromo(const string& texto) {
        string textoLimpo = limparString(texto);
        string textoReverso = textoLimpo;
        reverse(textoReverso.begin(), textoReverso.end());
        
        return textoLimpo == textoReverso;
    }

private:
    string limparString(const string& str) {
        string limpa;
        for (char c : str) {
            if (isalnum(c)) {
                limpa += tolower(c);
            }
        }
        return limpa;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    VerificadorPalindromo verificador;

    string entrada;
    cout << "\nDigite uma palavra ou frase para verificar se é um palíndromo: ";
    getline(cin, entrada);
    if (verificador.ehPalindromo(entrada)) {
        cout << "'" << entrada << "' é um palíndromo." << endl;
    } else {
        cout << "'" << entrada << "' não é um palíndromo." << endl;
    }

    return 0;
}