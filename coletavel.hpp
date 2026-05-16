#ifndef COLETAVEL_HPP
#define COLETAVEL_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Coletavel
{
    private:
        Coordenada posicao;

    public:
        void spawnColetavel(Mapa mapa);
};
#endif