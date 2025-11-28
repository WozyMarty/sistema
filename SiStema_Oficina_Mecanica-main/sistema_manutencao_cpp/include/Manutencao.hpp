#ifndef MANUTENCAO_HPP
#define MANUTENCAO_HPP

#include <vector>
#include <string>
#include <iostream>
#include "ItemManutencao.hpp"
#include "Veiculo.hpp"
#include "Mecanico.hpp"

class Manutencao {
private:
    std::string idOS;
    std::string dataInicio;
    std::string dataFim;
    std::string status;
    std::string observacoes;
    double valorTotal;

    Veiculo* veiculo;
    Mecanico* mecanico;
    std::vector<ItemManutencao*> itens;

public:
    Manutencao() = default;
    Manutencao(const std::string& id, Veiculo* v, Mecanico* m);

    void adicionarItem(ItemManutencao* item);
    double calcularValorTotal();
    void fecharOS();
    std::string getId() const;
    std::string getStatus() const;
};

#endif // MANUTENCAO_HPP
