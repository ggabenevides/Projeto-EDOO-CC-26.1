#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Player 
{
    private:
        Coordenada posicaoAtual;
        int coletaveisQtde;
        int vida;
        
    public:
        Player (Mapa& mapa);
        void movimentoWASD(Mapa& mapaAtual, char m);
        int getColetaveisQtde() { return coletaveisQtde; }
        Coordenada getPosicao() { return posicaoAtual; }
        int getVida() { return vida; }
        void tomarDano();
};

#endif