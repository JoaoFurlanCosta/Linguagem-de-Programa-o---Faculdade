SistemaDeGerenciamentoFuncionarios

#include <iostream>
#include <vector>
#include <string>
#include <numeric> // Para accumulate
#include <limits>  // Para numeric_limits
using namespace std;

class Funcionario {
public:
    string nome;
    int id;
    double salario;
    string departamento;

    Funcionario(string n, int i, double s, string d)
        : nome(n), id(i), salario(s), departamento(d) {}

    void exibirDados() const {
        cout << "ID: " << id << "\n"
                  << "Nome: " << nome << "\n"
                  << "Salario: R$ " << salario << "\n"
                  << "Departamento: " << departamento << "\n"
                  << "-----------------------------" << endl;
    }
};

void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<Funcionario> listaFuncionarios;
    int proximoId = 1;
    int opcao;

    do {
        cout << "\n## Sistema de Gerenciamento de Funcionarios ##\n";
        cout << "1. Cadastrar Funcionario\n";
        cout << "2. Calcular Total de Salarios por Departamento\n";
        cout << "3. Listar Todos os Funcionarios\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (cin.fail()) {
            cout << "Opcao invalida! Por favor, insira um numero.\n";
            cin.clear();
            limparBuffer();
            continue;
        }

        limparBuffer();

        switch (opcao) {
            case 1: {
                string nome, departamento;
                double salario;

                cout << "\n--- Cadastro de Funcionario ---\n";
                cout << "Nome: ";
                getline(cin, nome);

                cout << "Salario: ";
                cin >> salario;
                while (cin.fail()) {
                    cout << "Entrada invalida. Digite o salario novamente: ";
                    cin.clear();
                    limparBuffer();
                    cin >> salario;
                }
                limparBuffer();

                cout << "Departamento: ";
                getline(cin, departamento);

                listaFuncionarios.emplace_back(nome, proximoId++, salario, departamento);
                cout << "\nFuncionario cadastrado com sucesso! ID: " << proximoId - 1 << endl;
                break;
            }
            case 2: {
                cout << "\n--- Total de Salarios por Departamento ---\n";
                cout << "Digite o nome do departamento: ";
                string deptoBusca;
                getline(cin, deptoBusca);

                double totalSalarios = 0.0;
                for (const auto& func : listaFuncionarios) {
                    if (func.departamento == deptoBusca) {
                        totalSalarios += func.salario;
                    }
                }

                cout << "O total de salarios para o departamento '" << deptoBusca
                          << "' e: R$ " << totalSalarios << endl;
                break;
            }
            case 3: {
                cout << "\n--- Lista de Todos os Funcionarios ---\n";
                if (listaFuncionarios.empty()) {
                    cout << "Nenhum funcionario cadastrado ainda.\n";
                } else {
                    for (const auto& func : listaFuncionarios) {
                        func.exibirDados();
                    }
                }
                break;
            }
            case 4:
                cout << "Saindo do sistema...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
                break;
        }

    } while (opcao != 4);

    return 0;
}