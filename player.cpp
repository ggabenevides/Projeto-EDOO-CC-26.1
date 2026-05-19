#include "player.hpp"

Player::Player(Mapa& mapa)
{
    // posição inicial do jogador é centro da matriz 0
    posicaoAtual = Coordenada(4, 5);
    mapa.drawElement(0, posicaoAtual, 'P');
    coletaveisQtde = 0;
    
}

void Player::movimentoWASD(Mapa& mapaAtual, char m)
{
    Coordenada posicaoAntiga = posicaoAtual;

    if(m == 'a')
    {
        posicaoAtual.y -= 1;
    }
    else if(m == 'd')
    {
        posicaoAtual.y += 1;
    }
    else if(m == 'w')
    {
        posicaoAtual.x -= 1;
    }
    else if(m == 's')
    {
        posicaoAtual.x += 1;
    }

    mapaAtual.updateMapa(posicaoAntiga, posicaoAtual);
}