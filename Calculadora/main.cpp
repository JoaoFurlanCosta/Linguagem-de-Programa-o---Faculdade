#include <iostream>
#include <math.h>
#include <conio.h>

int somar(int a, int b) {
    int resultadosoma = a + b;
    return resultadosoma;
}

int dividir(int a, int b) {
    int resultadodivisao = a/b;
    return resultadodivisao;
}

int multiplicar(int a, int b) {
    int resultadomultiplicacao = a * b;
    return resultadomultiplicacao;
}

int subtracao(int a, int b) {
    int resultadosubtracao = a - b;
    return resultadosubtracao;
}



int main() {
    using namespace std;

    int escolha=0;
    int numero1=0;
    int numero2=0;
    cout<<"\n--- Bem vindo a calculadora ---";
    cout<<"\n-- Selecione uma operação: --";
    cout<<"\n1 - Somar";
    cout<<"\n2 - Subtrair";
    cout<<"\n3 - Multiplicar";
    cout<<"\n4 - Dividir";
    cout<<"\n-- Escolha --";
    cin>>escolha;
    if (escolha==1){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        int somartotal=somar(numero1,numero2);
        cout<<"Valor total:"<<somartotal;
    };
    if (escolha==2){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        int resultadoSubtracao=subtracao(numero1,numero2);
        cout<<"Valor total:"<<resultadoSubtracao;
    };
    if (escolha==3){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        int multiplicacao=multiplicar(numero1,numero2);
        cout<<"Valor total:"<<multiplicacao;
    }
    if (escolha==4){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        int divisao=dividir(numero1,numero2);
        cout<<"Valor total:"<<subtracao;
    };
}