#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <iostream>

class Cliente {
private:
    std::string idCliente;
    std::string nome;
    std::string telefone;
    std::string cpf;

public:
    Cliente() = default;
    Cliente(const std::string& id, const std::string& n, const std::string& tel, const std::string& c);

    std::string getId() const;
    std::string getNome() const;

    void cadastrarCliente() const;
    void consultarHistorico(const std::string& placa) const;
};

#endif // CLIENTE_HPP
