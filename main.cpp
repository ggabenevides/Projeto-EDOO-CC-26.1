#include "mapas.hpp"
#include "player.hpp"
#include "coordenada.hpp"
#include "coletavel.hpp"
#include "inimigo.hpp"
#include <iostream>

int main(){

    // flag de controle do final do jogo
    bool terminou = false;

    // instanciando objetos
    Mapa mapa;
    Player jogador(mapa);

    // instanciando coletáveis e armazenando eles num vetor para poder avaliar
    srand(time(0)); // é usado no construtor
    int coletavelCount = 0;
    while (coletavelCount < 3)
    {
        Coletavel item(mapa);
        coletavelCount++;
    }

    // instanciando inimigo
    Inimigo inimigo(mapa);

    // estado inicial
    std::cout << mapa;

    // fluxo de jogo
    while(not terminou)
    {
        // prompt movimento
        char movimento;
        std::cout << "Para onde você deseja se movimentar? (w/a/s/d) ";
        std::cin >> movimento;
        jogador.movimentoWASD(mapa, movimento);
        if (jogador.getColetaveisQtde() == 3) terminou = true;
        if (inimigo.mover(mapa, jogador.getPosicao(), mapa.getMapaAtual()))
            jogador.tomarDano();
        if (jogador.getVida() == 0) terminou = true;
        std::cout << mapa;
    }

}