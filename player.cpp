#include "player.hpp"

Player::Player(Mapa& mapa)
{
    // posição inicial do jogador é centro da matriz 0
    posicaoAtual = Coordenada(4, 5);
    mapa.drawElement(0, posicaoAtual, 'P');
    coletaveisQtde = 0;
    vida = 3;
    colisao = false;
    novoColetavel = false;
    
}

void Player::tomarDano()
{
    if (vida > 0) {
        vida--;
        colisao = true;}
}

void Player::checarEvento()
{
    if (novoColetavel)
    {
        novoColetavel = false;
        std::cout << "Você tem um novo coletável!"<< std::endl <<
        "Seu saldo de coletáveis agora é: " <<  coletaveisQtde << "\n" << std::endl;
    }
    if (colisao)
    {
        colisao = false;
        std::cout << "Você foi atacado pelo inimigo!" << std::endl <<
        "Seu saldo de vida agora é: " << vida << "\n" << std::endl;
    }
}

void Player::movimentoWASD(Mapa& mapa, char m)
{
    Coordenada posicaoAntiga = posicaoAtual;
    bool movValido = false;

    if(m == 'a')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x-1, posicaoAtual.y)))
        {
            posicaoAtual.x -= 1;
            movValido = true;
        }
    }
    else if(m == 'd')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x+1, posicaoAtual.y)))
        {
            posicaoAtual.x += 1;
            movValido = true;
        }
    }
    else if(m == 'w')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x, posicaoAtual.y-1)))
        {
            posicaoAtual.y -= 1;
            movValido = true;
        }
    }
    else if(m == 's')
    {
        if(mapa.podeMover(mapa.getMapaAtual(), Coordenada(posicaoAtual.x, posicaoAtual.y+1)))
        {
            posicaoAtual.y += 1;
            movValido = true;
        }
    }
    if (movValido){
        // incrementa o contador se o jogador entrar na célula de coletável
        if (mapa.getChar(mapa.getMapaAtual(), posicaoAtual) == 'C') {
            coletaveisQtde++;
        }
        mapa.updateMapa(posicaoAntiga, posicaoAtual);
    }
    
}