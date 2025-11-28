#include "Mecanico.hpp"

Mecanico::Mecanico(const std::string& id, const std::string& n, const std::string& e)
    : idFuncional(id), nome(n), especialidade(e) {}

std::string Mecanico::getId() const { return idFuncional; }
std::string Mecanico::getNome() const { return nome; }

void Mecanico::registrarJornada() const {
    std::cout << "Jornada registrada para o mecanico: " << nome << " (ID: " << idFuncional << ")\n";
}
