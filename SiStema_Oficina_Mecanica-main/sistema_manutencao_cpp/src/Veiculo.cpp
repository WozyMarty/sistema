#include "Veiculo.hpp"

Veiculo::Veiculo(const std::string& p, const std::string& m, int a)
    : placa(p), modelo(m), ano(a), quilometragem(0) {}

void Veiculo::registrarQuilometragem(int km) {
    if (km >= 0) {
        quilometragem = km;
        std::cout << "Quilometragem do veiculo " << placa << " atualizada para " << quilometragem << " km\n";
    }
}

void Veiculo::cadastrarVeiculo() const {
    std::cout << "Veiculo cadastrado: " << placa << " - " << modelo << " (" << ano << ")\n";
}

std::string Veiculo::getPlaca() const { return placa; }
std::string Veiculo::getModelo() const { return modelo; }
int Veiculo::getQuilometragem() const { return quilometragem; }
