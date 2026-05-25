#ifndef COLETAVEL_HPP
#define COLETAVEL_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Coletavel
{
    protected:
        Coordenada posicaoAtual;
        int mapaEscolhido;

    public:
        Coletavel(Mapa& mapa, char simbolo = 'C');
        Coordenada getPosicao() { return posicaoAtual; }
        int getMapa() { return mapaEscolhido; }
};
#endif
