#include "player.hpp"

Player::Player(Mapa& mapa)
{
    // posição inicial do jogador é centro da matriz 0
    posicaoAtual = Coordenada(4, 5);
    mapa.drawElement(0, posicaoAtual, 'P');
    coletaveisQtde = 0;
    
}

void Player::movimentoWASD(Mapa& mapa, char m)
{
    Coordenada posicaoAntiga = posicaoAtual;
    bool movValido = false;

    if(m == 'a')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x, posicaoAtual.y-1)))
        {
            posicaoAtual.x -= 1;
            movValido = true;
        }
    }
    else if(m == 'd')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x, posicaoAtual.y+1)))
        {posicaoAtual.x += 1;
        movValido = true;}
    }
    else if(m == 'w')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x-1, posicaoAtual.y)))
        {posicaoAtual.y -= 1;
        movValido = true;}
    }
    else if(m == 's')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x+1, posicaoAtual.y)))
        {posicaoAtual.y += 1;
        movValido = true;}
    }
    if (movValido){
        mapa.updateMapa(posicaoAntiga, posicaoAtual);
    }
    
}