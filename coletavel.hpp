#ifndef COLETAVEL_HPP
#define COLETAVEL_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Coletavel
{
    private:
        Coordenada posicao;
        int mapaEscolhido;

    public:
        Coletavel(Mapa& mapa);
};
#endif