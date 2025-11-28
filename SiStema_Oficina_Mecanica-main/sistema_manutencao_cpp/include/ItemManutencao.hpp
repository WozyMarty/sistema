#ifndef ITEM_MANUTENCAO_HPP
#define ITEM_MANUTENCAO_HPP

#include <string>
#include "Peca.hpp"

class ItemManutencao {
private:
    std::string idItem;
    int quantidade;
    double valorUnitario;
    Peca* peca; // associação

public:
    ItemManutencao() = default;
    ItemManutencao(const std::string& id, Peca* p, int qtd);

    double calcularSubtotal() const;

    std::string getId() const;
    int getQuantidade() const;
    Peca* getPeca() const;
};

#endif // ITEM_MANUTENCAO_HPP
