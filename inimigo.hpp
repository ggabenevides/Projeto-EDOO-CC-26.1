#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "coletavel.hpp"

class Inimigo : public Coletavel
{
    public:
        Inimigo(Mapa& mapa);
        bool mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer); // retorna true se o inimigo atingiu o jogador
};

#endif
