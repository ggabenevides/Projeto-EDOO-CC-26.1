#ifndef INIMIGO_HPP
#define INIMIGO_HPP
#include "objeto.hpp"

class Inimigo : public Objeto
{
    public:
        Inimigo(Mapa& mapa);
        bool mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer); // retorna true se o inimigo atingiu o jogador
        ~Inimigo(){};
};

#endif
