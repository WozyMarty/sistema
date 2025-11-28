#ifndef PECA_HPP
#define PECA_HPP

#include <string>
#include <iostream>

class Peca {
private:
    std::string codigoPeca;
    std::string nome;
    double precoVenda;
    int estoqueAtual;
    int estoqueMinimo;

public:
    Peca() = default;
    Peca(const std::string& cod, const std::string& n, double preco, int min);

    void registrarEntrada(int qtd);
    bool darBaixa(int qtd);
    bool verificarEstoque() const;

    std::string getCodigo() const;
    std::string getNome() const;
    double getPreco() const;
    int getEstoqueAtual() const;
};

#endif // PECA_HPP
