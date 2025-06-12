#include "Calculadora.h"





int main() {
    using namespace std;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int escolha=0;
    int numero1=0;
    int numero2=0;
    Calculadora calc();
//    calc.Calculadora();
   do{   
    cout<<"\n--- Bem vindo a calculadora ---";
    cout<<"\n-- Selecione uma operação: --";
    cout<<"\n1 - Somar";
    cout<<"\n2 - Subtrair";
    cout<<"\n3 - Multiplicar";
    cout<<"\n4 - Dividir";
    cout<<"\n0 - Sair";
    cout<<"\n-- Escolha --";
    cin>>escolha;
    if (escolha==1){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        cout<<"Valor total:"<<calc.somar(numero1, numero2);
    };
    if (escolha==2){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        cout<<"Valor total:"<<calc.subtrair(numero1, numero2);
    };
    if (escolha==3){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        cout<<"Valor total:"<<calc.multiplicacao(numero1, numero2);
    }
    if (escolha==4){
        cout<<"\nDigite o primeiro número:";
        cin>>numero1;
        cout<<"\nDigite o segundo número:";
        cin>>numero2;
        cout<<"Valor total:"<<calc.divisao(numero1, numero2);
    };
    } while (escolha!=0)
}

