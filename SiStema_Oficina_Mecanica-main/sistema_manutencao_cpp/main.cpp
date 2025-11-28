#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <limits>
#include "include/Cliente.hpp"
#include "include/Veiculo.hpp"
#include "include/Mecanico.hpp"
#include "include/Peca.hpp"
#include "include/ItemManutencao.hpp"
#include "include/Manutencao.hpp"

using namespace std;

// Simple in-memory repositories
vector<Cliente> clientes;
vector<Veiculo> veiculos;
vector<Mecanico> mecanicos;
vector<Peca> pecas;
vector<unique_ptr<Manutencao>> manutencoes;

// Utility to read a line
static void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Clear the console screen (cross-platform)
static void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

Cliente* findClienteById(const string& id) {
    for (auto &c : clientes) if (c.getId() == id) return &c;
    return nullptr;
}

Veiculo* findVeiculoByPlaca(const string& placa) {
    for (auto &v : veiculos) if (v.getPlaca() == placa) return &v;
    return nullptr;
}

Mecanico* findMecanicoById(const string& id) {
    for (auto &m : mecanicos) if (m.getId() == id) return &m;
    return nullptr;
}

Peca* findPecaByCodigo(const string& cod) {
    for (auto &p : pecas) if (p.getCodigo() == cod) return &p;
    return nullptr;
}

Manutencao* findOSById(const string& id) {
    for (auto &osPtr : manutencoes) if (osPtr->getId() == id) return osPtr.get();
    return nullptr;
}

// Module menus
void menuClientes() {
    while (true) {
        cout << "\n--- Clientes ---\n1 - Cadastrar Cliente\n2 - Consultar Historico (simulado)\n0 - Voltar\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) break;
        if (op == 1) {
            string id,nome,tel,cpf;
            cout << "ID: "; getline(cin, id);
            cout << "Nome: "; getline(cin, nome);
            cout << "Telefone: "; getline(cin, tel);
            cout << "CPF: "; getline(cin, cpf);
            clientes.emplace_back(id,nome,tel,cpf);
            clientes.back().cadastrarCliente();
        } else if (op == 2) {
            string id, placa;
            cout << "ID do cliente: "; getline(cin, id);
            cout << "Placa do veiculo: "; getline(cin, placa);
            Cliente* c = findClienteById(id);
            if (c) c->consultarHistorico(placa);
            else cout << "Cliente nao encontrado.\n";
        }
    }
}

void menuVeiculos() {
    while (true) {
        cout << "\n--- Veiculos ---\n1 - Cadastrar Veiculo\n2 - Registrar Quilometragem\n0 - Voltar\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) break;
        if (op == 1) {
            string placa, modelo; int ano;
            cout << "Placa: "; getline(cin, placa);
            cout << "Modelo: "; getline(cin, modelo);
            cout << "Ano: "; cin >> ano; clearCin();
            veiculos.emplace_back(placa, modelo, ano);
            veiculos.back().cadastrarVeiculo();
        } else if (op == 2) {
            string placa; int km;
            cout << "Placa: "; getline(cin, placa);
            cout << "Quilometragem: "; cin >> km; clearCin();
            Veiculo* v = findVeiculoByPlaca(placa);
            if (v) v->registrarQuilometragem(km);
            else cout << "Veiculo nao encontrado.\n";
        }
    }
}

void menuMecanicos() {
    while (true) {
        cout << "\n--- Mecanicos ---\n1 - Cadastrar Mecanico\n2 - Registrar Jornada\n0 - Voltar\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) break;
        if (op == 1) {
            string id,nome,esp;
            cout << "ID: "; getline(cin, id);
            cout << "Nome: "; getline(cin, nome);
            cout << "Especialidade: "; getline(cin, esp);
            mecanicos.emplace_back(id,nome,esp);
            cout << "Mecanico cadastrado: " << nome << " (" << id << ")\n";
        } else if (op == 2) {
            string id;
            cout << "ID: "; getline(cin, id);
            Mecanico* m = findMecanicoById(id);
            if (m) m->registrarJornada();
            else cout << "Mecanico nao encontrado.\n";
        }
    }
}

void menuPecas() {
    while (true) {
        cout << "\n--- Pecas ---\n1 - Cadastrar Peca\n2 - Registrar Entrada\n3 - Dar Baixa\n4 - Verificar Estoque\n0 - Voltar\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) break;
        if (op == 1) {
            string cod,nome; double preco; int min;
            cout << "Codigo: "; getline(cin, cod);
            cout << "Nome: "; getline(cin, nome);
            cout << "Preco venda: "; cin >> preco; clearCin();
            cout << "Estoque minimo: "; cin >> min; clearCin();
            pecas.emplace_back(cod,nome,preco,min);
            cout << "Peca cadastrada: " << nome << " (" << cod << ")\n";
        } else if (op == 2) {
            string cod; int qtd;
            cout << "Codigo: "; getline(cin, cod);
            cout << "Quantidade: "; cin >> qtd; clearCin();
            Peca* p = findPecaByCodigo(cod);
            if (p) p->registrarEntrada(qtd);
            else cout << "Peca nao encontrada.\n";
        } else if (op == 3) {
            string cod; int qtd;
            cout << "Codigo: "; getline(cin, cod);
            cout << "Quantidade: "; cin >> qtd; clearCin();
            Peca* p = findPecaByCodigo(cod);
            if (p) p->darBaixa(qtd);
            else cout << "Peca nao encontrada.\n";
        } else if (op == 4) {
            string cod;
            cout << "Codigo: "; getline(cin, cod);
            Peca* p = findPecaByCodigo(cod);
            if (p) {
                cout << "Estoque atual: " << p->getEstoqueAtual() << ", minimo: " << (p->verificarEstoque() ? "OK" : "ABAIXO") << "\n";
            } else cout << "Peca nao encontrada.\n";
        }
    }
}

void menuOS() {
    while (true) {
        cout << "\n--- Ordens de Servico ---\n1 - Abrir OS\n2 - Adicionar Item a OS\n3 - Calcular Valor OS\n4 - Fechar OS\n5 - Listar OS\n0 - Voltar\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) break;
        if (op == 1) {
            string id, placa, idMec;
            cout << "ID OS: "; getline(cin, id);
            cout << "Placa do veiculo: "; getline(cin, placa);
            cout << "ID do mecanico responsavel: "; getline(cin, idMec);
            Veiculo* v = findVeiculoByPlaca(placa);
            Mecanico* m = findMecanicoById(idMec);
            if (!v) { cout << "Veiculo nao encontrado. Cadastre antes.\n"; continue; }
            if (!m) { cout << "Mecanico nao encontrado. Cadastre antes.\n"; continue; }
            manutencoes.emplace_back(make_unique<Manutencao>(id, v, m));
            cout << "OS " << id << " criada.\n";
        } else if (op == 2) {
            string idOS, codPeca, idItem; int qtd;
            cout << "ID OS: "; getline(cin, idOS);
            Manutencao* os = findOSById(idOS);
            if (!os) { cout << "OS nao encontrada.\n"; continue; }
            cout << "ID Item: "; getline(cin, idItem);
            cout << "Codigo da peca: "; getline(cin, codPeca);
            cout << "Quantidade: "; cin >> qtd; clearCin();
            Peca* p = findPecaByCodigo(codPeca);
            if (!p) { cout << "Peca nao encontrada.\n"; continue; }
            // Do not automatically dar baixa na peça aqui; business rule could require confirmacao.
            ItemManutencao* item = new ItemManutencao(idItem, p, qtd);
            os->adicionarItem(item);
        } else if (op == 3) {
            string idOS;
            cout << "ID OS: "; getline(cin, idOS);
            Manutencao* os = findOSById(idOS);
            if (!os) { cout << "OS nao encontrada.\n"; continue; }
            os->calcularValorTotal();
        } else if (op == 4) {
            string idOS;
            cout << "ID OS: "; getline(cin, idOS);
            Manutencao* os = findOSById(idOS);
            if (!os) { cout << "OS nao encontrada.\n"; continue; }
            os->fecharOS();
        } else if (op == 5) {
            cout << "Listando OS criadas:\n";
            for (auto &osPtr : manutencoes) {
                cout << " - " << osPtr->getId() << " [" << osPtr->getStatus() << "]\n";
            }
        }
    }
}

int main() {
    cout << "Sistema de Registro de Manutencoes - Menu Principal\n";
    while (true) {
        cout << "\n=== Menu Principal ===\n1 - Clientes\n2 - Veiculos\n3 - Mecanicos\n4 - Pecas\n5 - Ordens de Servico\n0 - Sair\nEscolha: ";
        int op; if (!(cin >> op)) { clearCin(); continue; }
        clearCin();
        if (op == 0) {
            cout << "Saindo...\n";
            break;
        }
        bool returnedFromSubmenu = false;
        if (op == 1) { menuClientes(); returnedFromSubmenu = true; }
        else if (op == 2) { menuVeiculos(); returnedFromSubmenu = true; }
        else if (op == 3) { menuMecanicos(); returnedFromSubmenu = true; }
        else if (op == 4) { menuPecas(); returnedFromSubmenu = true; }
        else if (op == 5) { menuOS(); returnedFromSubmenu = true; }
        else cout << "Opcao invalida.\n";

        if (returnedFromSubmenu) {
            clearConsole();
            cout << "Sistema de Registro de Manutencoes - Menu Principal\n";
        }
    }
    return 0;
}
