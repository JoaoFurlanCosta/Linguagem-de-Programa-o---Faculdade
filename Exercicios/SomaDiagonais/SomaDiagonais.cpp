#include <iostream>
#include <vector>
using namespace std;

class MatrizQuadrada {
private:
    int n;
    vector<vector<int>> matriz;

public:
    MatrizQuadrada(int ordem) : n(ordem), matriz(ordem, vector<int>(ordem)) {}
    void preencherMatriz() {
        cout << "\nDigite os elementos da matriz:\n";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }

    int somaDiagonalPrincipal() {
        int soma = 0;
        for (int i = 0; i < n; ++i) {
            soma += matriz[i][i];
        }
        return soma;
    }
};

int main() {
    int n;
    cout << "Digite a ordem da matriz quadrada: ";
    cin >> n;
    if (n <= 0) {
        cerr << "Erro: A ordem da matriz deve ser um número positivo." << endl;
        return 1;
    }
    
    MatrizQuadrada minhaMatriz(n);
    minhaMatriz.preencherMatriz();

    cout << "\n--- Resultados ---\n";
    cout << "Soma da diagonal principal: " << minhaMatriz.somaDiagonalPrincipal() << endl;
    cout << "Soma da diagonal secundária: " << minhaMatriz.somaDiagonalSecundaria() << endl;

    return 0;
}