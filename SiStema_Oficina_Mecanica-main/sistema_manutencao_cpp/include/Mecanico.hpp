#ifndef MECANICO_HPP
#define MECANICO_HPP

#include <string>
#include <iostream>

class Mecanico {
private:
    std::string idFuncional;
    std::string nome;
    std::string especialidade;

public:
    Mecanico() = default;
    Mecanico(const std::string& id, const std::string& n, const std::string& e);

    std::string getId() const;
    std::string getNome() const;

    void registrarJornada() const;
};

#endif // MECANICO_HPP
