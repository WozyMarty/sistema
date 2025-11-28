#include "ItemManutencao.hpp"

ItemManutencao::ItemManutencao(const std::string& id, Peca* p, int qtd)
    : idItem(id), quantidade(qtd), peca(p) {
    valorUnitario = (peca ? peca->getPreco() : 0.0);
}

double ItemManutencao::calcularSubtotal() const {
    return quantidade * valorUnitario;
}

std::string ItemManutencao::getId() const { return idItem; }
int ItemManutencao::getQuantidade() const { return quantidade; }
Peca* ItemManutencao::getPeca() const { return peca; }
