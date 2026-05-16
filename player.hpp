#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "coordenada.hpp"
#include "mapas.hpp"

class Player 
{
    private:
        Coordenada posiçãoAtual;
        int coletaveisQtde;
        
    public:
        void movimentoWASD(Mapa mapaAtual, char m);
        int getX() {return posiçãoAtual.x;}
        int getY() {return posiçãoAtual.y;}
};

#endif