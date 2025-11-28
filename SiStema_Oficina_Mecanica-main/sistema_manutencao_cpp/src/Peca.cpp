#include "Peca.hpp"

Peca::Peca(const std::string& cod, const std::string& n, double preco, int min)
    : codigoPeca(cod), nome(n), precoVenda(preco), estoqueAtual(0), estoqueMinimo(min) {}

void Peca::registrarEntrada(int qtd) {
    if (qtd > 0) {
        estoqueAtual += qtd;
        std::cout << "Entrada registrada. Peca: " << nome << ", Qtd: " << qtd << ", Estoque atual: " << estoqueAtual << "\n";
    }
}

bool Peca::darBaixa(int qtd) {
    if (qtd <= 0) return false;
    if (estoqueAtual >= qtd) {
        estoqueAtual -= qtd;
        std::cout << "Baixa realizada. Peca: " << nome << ", Qtd: " << qtd << ", Estoque atual: " << estoqueAtual << "\n";
        return true;
    } else {
        std::cout << "Estoque insuficiente para a peca: " << nome << "\n";
        return false;
    }
}

bool Peca::verificarEstoque() const {
    return estoqueAtual >= estoqueMinimo;
}

std::string Peca::getCodigo() const { return codigoPeca; }
std::string Peca::getNome() const { return nome; }
double Peca::getPreco() const { return precoVenda; }
int Peca::getEstoqueAtual() const { return estoqueAtual; }
