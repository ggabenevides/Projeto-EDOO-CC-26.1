#ifndef OBJETO_HPP
#define OBJETO_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

// classe mãe para objetos que o jogador não controla mas ficam no mapa (inimigo e coletaveis)
class Objeto
{
    protected:
        Coordenada posicaoAtual;
        int mapaEscolhido;

    public:
        Objeto(Mapa& mapa, char simbolo);
        Coordenada getPosicao() { return posicaoAtual; }
        int getMapa() { return mapaEscolhido; }
        virtual bool mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer) = 0; //sempre retorna falso pois coletável não se move
        virtual ~Objeto() {};
};
#endif