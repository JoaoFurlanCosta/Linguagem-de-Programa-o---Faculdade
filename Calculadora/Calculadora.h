//calculadora.h

#include <iostream> 
    


class Calculadora {

private:
	void executar();
	

public:
	Calculadora();
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
};




