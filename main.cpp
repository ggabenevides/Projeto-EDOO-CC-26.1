#include "mapas.hpp"
#include "player.hpp"
#include "coordenada.hpp"
#include "coletavel.hpp"
#include <iostream>

int main(){

    // flag de controle do final do jogo
    bool terminou = false;

    // instanciando objetos
    Player jogador;
    Mapa mapa;

    // instanciando coletáveis e armazenando eles num vetor para poder avaliar quantidade
    std::vector<Coletavel> coletaveis; 
    while (coletaveis.size() < 3)
    {
        Coletavel item;
        item.spawnColetavel(mapa);
    }

    // fluxo de jogo
    while(not terminou)
    {
        // prompt movimento
        char movimento;
        std::cout << "Para onde você deseja se movimentar? (w/a/s/d) ";
        std::cin >> movimento;
        jogador.movimentoWASD(mapa, movimento);
    }

}