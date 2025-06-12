#include <iostream>
#include <limits>
using namespace std;

class Matriz {
private:
    int** matriz; 
    int linhas;
    int colunas;

public:
    Matriz(int m, int n) : linhas(m), colunas(n) {
        matriz = new int*[linhas];
        for (int i = 0; i < linhas; ++i) {
            matriz[i] = new int[colunas];
        }
    }
    
    ~Matriz() {
        for (int i = 0; i < linhas; ++i) {
            delete[] matriz[i];
        }
        delete[] matriz;
        cout << "\nMemória da matriz liberada com sucesso!" << endl;
    }
    void preencherMatriz() {
        cout << "\n--- Preenchimento da Matriz ---" << endl;
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                cout << "Digite o valor para o elemento [" << i << "][" << j << "]: ";
                cin >> matriz[i][j];
            }
        }
    }
    void encontrarMaiorMenor() {
        if (linhas == 0 || colunas == 0) {
            cout << "\nA matriz está vazia. Não é possível encontrar o maior e o menor elemento." << endl;
            return;
        }
        int maior = matriz[0][0];
        int menor = matriz[0][0];
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j < colunas; ++j) {
                if (matriz[i][j] > maior) {
                    maior = matriz[i][j];
                }
                if (matriz[i][j] < menor) {
                    menor = matriz[i][j];
                }
            }
        }
        cout << "\n--- Resultados ---" << endl;
        cout << "Maior elemento encontrado: " << maior << endl;
        cout << "Menor elemento encontrado: " << menor << endl;
    }
};

int main() {
    int m, n;
    
    cout << "--- Criação da Matriz ---" << endl;
    cout << "Informe o número de linhas (m): ";
    cin >> m;
    cout << "Informe o número de colunas (n): ";
    cin >> n;
    
    if (m <= 0 || n <= 0) {
        cout << "Erro: As dimensões da matriz devem ser valores positivos." << endl;
        return 1; 
    }
    
    Matriz minhaMatriz(m, n);

    
    minhaMatriz.preencherMatriz();
    minhaMatriz.encontrarMaiorMenor();

    return 0;
}