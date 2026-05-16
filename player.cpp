#include "player.hpp"

void Player::movimentoWASD(Mapa mapaAtual, char m)
{
    int x = getX();
    int y = getY();
    bool movValido;

    if(m == 'a')
    {
        movValido = mapaAtual.podeMover(x-1, y);
    }
    else if(m == 'd')
    {
        movValido = mapaAtual.podeMover(x+1, y);
    }
    else if(m == 'w')
    {
        movValido = mapaAtual.podeMover(x, y+1);
    }
    else if(m == 's')
    {
        movValido = mapaAtual.podeMover(x, y-1);
    }

    if (movValido)
    {
        // atualizar matrizes com nova posição do jogador ou então trocar de matriz
    }
}