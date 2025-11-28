#include "Manutencao.hpp"

Manutencao::Manutencao(const std::string& id, Veiculo* v, Mecanico* m)
    : idOS(id), dataInicio(""), dataFim(""), status("Aberta"), observacoes(""), valorTotal(0.0),
      veiculo(v), mecanico(m) {}

void Manutencao::adicionarItem(ItemManutencao* item) {
    if (item) {
        itens.push_back(item);
        std::cout << "Item " << item->getId() << " adicionado à OS " << idOS << "\n";
    }
}

double Manutencao::calcularValorTotal() {
    double total = 0.0;
    for (auto it : itens) {
        if (it) total += it->calcularSubtotal();
    }
    valorTotal = total;
    std::cout << "Valor total calculado: " << valorTotal << "\n";
    return valorTotal;
}

void Manutencao::fecharOS() {
    valorTotal = calcularValorTotal();
    status = "Fechada";
    std::cout << "OS " << idOS << " fechada. Valor total: " << valorTotal << "\n";
}

std::string Manutencao::getId() const { return idOS; }
std::string Manutencao::getStatus() const { return status; }
