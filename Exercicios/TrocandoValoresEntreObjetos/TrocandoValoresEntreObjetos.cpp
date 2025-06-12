#include <iostream>
using namespace std;
class ValorContainer {
public:
    int valor;
    ValorContainer(int v = 0) : valor(v) {}
    static void trocarValores(ValorContainer &refA, ValorContainer &refB) {
        int temp = refA.valor;
        refA.valor = refB.valor;
        refB.valor = temp;
    }
};

int main() {
    ValorContainer objA;
    ValorContainer objB;
    cout << "Digite um valor para o objeto A: ";
    cin >> objA.valor;
    cout << "Digite um valor para o objeto B: ";
    cin >> objB.valor;
    
    cout << "\n--- Valores Originais ---\n";
    cout << "Valor de objA: " << objA.valor << endl;
    cout << "Valor de objB: " << objB.valor << endl;
    
    ValorContainer::trocarValores(objA, objB);
    
    cout << "\n--- Valores Trocados ---\n";
    cout << "Novo valor de objA: " << objA.valor << endl;
    cout << "Novo valor de objB: " << objB.valor << endl;

    return 0;
}