#include "inimigo.hpp"
#include <cstdlib>

Inimigo::Inimigo(Mapa& mapa) : Objeto(mapa, 'I') {}

bool Inimigo::mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer)
{
    // só se move se estiver no mesmo mapa que o jogador
    if (mapaEscolhido != mapaPlayer) return false;

    int dx = posicaoPlayer.x - posicaoAtual.x;
    int dy = posicaoPlayer.y - posicaoAtual.y;

    if (dx == 0 && dy == 0) return false;

    // tenta movimento diagonal (fiel ao Python que atualiza x e y simultaneamente)
    Coordenada novaPosicao = posicaoAtual;
    if (dx != 0) novaPosicao.x += (dx > 0) ? 1 : -1;
    if (dy != 0) novaPosicao.y += (dy > 0) ? 1 : -1;

    // detecta colisão com o jogador no destino diagonal
    if (novaPosicao.x == posicaoPlayer.x && novaPosicao.y == posicaoPlayer.y)
        return true;

    // se o destino diagonal estiver bloqueado, tenta apenas o eixo de maior diferença
    if (!mapa.podeMover(mapaEscolhido, novaPosicao) || mapa.getChar(mapaEscolhido, novaPosicao) == 'C')
    {
        novaPosicao = posicaoAtual;
        if (std::abs(dx) >= std::abs(dy))
            novaPosicao.x += (dx > 0) ? 1 : -1;
        else
            novaPosicao.y += (dy > 0) ? 1 : -1;

        // detecta colisão com o jogador no destino do eixo único
        if (novaPosicao.x == posicaoPlayer.x && novaPosicao.y == posicaoPlayer.y)
            return true;
    }

    // move se a célula destino for chão livre (não sobrescreve coletáveis nem o jogador)
    if (mapa.podeMover(mapaEscolhido, novaPosicao) && mapa.getChar(mapaEscolhido, novaPosicao) != 'C')
    {
        mapa.drawElement(mapaEscolhido, posicaoAtual, '.');
        mapa.drawElement(mapaEscolhido, novaPosicao, 'I');
        posicaoAtual = novaPosicao;
    }

    return false;
}
