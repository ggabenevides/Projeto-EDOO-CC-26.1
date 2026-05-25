#ifndef COLETAVEL_HPP
#define COLETAVEL_HPP
#include "coordenada.hpp"
#include "mapas.hpp"
#include "objeto.hpp"

class Coletavel : public Objeto
{
    public:
        Coletavel(Mapa& mapa, char simbolo = 'C') : Objeto(mapa, simbolo) {};
        bool mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer) {return false;} //sempre retorna falso pois coletável não se move
        ~Coletavel(){}
};
#endif
