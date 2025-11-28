#ifndef VEICULO_HPP
#define VEICULO_HPP

#include <string>
#include <iostream>

class Veiculo {
private:
    std::string placa;
    std::string modelo;
    int ano;
    int quilometragem;

public:
    Veiculo() = default;
    Veiculo(const std::string& p, const std::string& m, int a);

    void registrarQuilometragem(int km);
    void cadastrarVeiculo() const;

    std::string getPlaca() const;
    std::string getModelo() const;
    int getQuilometragem() const;
};

#endif // VEICULO_HPP
