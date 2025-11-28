#include "Cliente.hpp"

Cliente::Cliente(const std::string& id, const std::string& n, const std::string& tel, const std::string& c)
    : idCliente(id), nome(n), telefone(tel), cpf(c) {}

std::string Cliente::getId() const { return idCliente; }
std::string Cliente::getNome() const { return nome; }

void Cliente::cadastrarCliente() const {
    std::cout << "Cliente cadastrado: " << nome << " (ID: " << idCliente << ")\n";
}

void Cliente::consultarHistorico(const std::string& placa) const {
    std::cout << "Simulando consulta de historico para placa: " << placa << " do cliente " << nome << "\n";
}
