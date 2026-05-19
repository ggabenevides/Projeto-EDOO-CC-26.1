#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Player 
{
    private:
        Coordenada posicaoAtual;
        int coletaveisQtde;
        
    public:
        Player (Mapa& mapa);
        void movimentoWASD(Mapa& mapaAtual, char m);
};

#endif