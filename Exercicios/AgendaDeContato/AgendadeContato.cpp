#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Contato {
public:
    string nome;
    string telefone;
    string email;

    Contato(string n, string t, string e) : nome(n), telefone(t), email(e) {}
};

void limparBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void adicionarContato(vector<Contato> &agenda) {
    if (agenda.size() >= 10) {
        cout << "\n❌ Agenda cheia! Não é possível adicionar mais contatos.\n";
        return;
    }

    string nome, telefone, email;
    limparBuffer();

    cout << "\n--- Adicionar Novo Contato ---\n";
    cout << "Nome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "Email: ";
    getline(cin, email);

    agenda.push_back(Contato(nome, telefone, email));
    cout << "\n✅ Contato adicionado com sucesso!\n";
}

void listarContatos(const vector<Contato> &agenda) {
    cout << "\n--- Lista de Contatos ---\n";
    if (agenda.empty()) {
        cout << "Nenhum contato cadastrado.\n";
    } else {
        for (size_t i = 0; i < agenda.size(); ++i) {
            cout << "Contato #" << i + 1 << "\n";
            cout << "  Nome: " << agenda[i].nome << "\n";
            cout << "  Telefone: " << agenda[i].telefone << "\n";
            cout << "  Email: " << agenda[i].email << "\n\n";
        }
    }
}

void procurarContato(const vector<Contato> &agenda) {
    if (agenda.empty()) {
        cout << "\n❌ Agenda vazia! Não há contatos para procurar.\n";
        return;
    }

    string nomeBusca;
    limparBuffer();

    cout << "\n--- Procurar Contato ---\n";
    cout << "Digite o nome do contato a ser procurado: ";
    getline(cin, nomeBusca);

    bool encontrado = false;
    for (const Contato &contato : agenda) {
        if (contato.nome == nomeBusca) {
            cout << "\n🔎 Contato encontrado:\n";
            cout << "  Telefone: " << contato.telefone << "\n";
            cout << "  Email: " << contato.email << "\n";
            encontrado = true;
            break; 
        }
    }

    if (!encontrado) {
        cout << "\n❌ Contato com o nome '" << nomeBusca << "' não encontrado.\n";
    }
}

int main() {
    vector<Contato> agenda; 
    int opcao = 0;

    #ifdef _WIN32
        setlocale(LC_ALL, "Portuguese");
    #endif

    do {
        cout << "\n--- 📓 Agenda de Contatos ---\n";
        cout << "1. Adicionar Contato\n";
        cout << "2. Listar Contatos\n";
        cout << "3. Procurar Contato\n";
        cout << "4. Sair\n";
        cout << "-----------------------------\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;


        if(cin.fail()) {
            cout << "\nOpção inválida. Por favor, digite um número.\n";
            cin.clear();
            limparBuffer();
            opcao = 0; 
            continue;
        }

        switch (opcao) {
            case 1:
                adicionarContato(agenda);
                break;
            case 2:
                listarContatos(agenda);
                break;
            case 3:
                procurarContato(agenda);
                break;
            case 4:
                cout << "\nSaindo da agenda... Até logo! 👋\n";
                break;
            default:
                cout << "\nOpção inválida. Tente novamente.\n";
                break;
        }

    } while (opcao != 4);

    return 0;
}