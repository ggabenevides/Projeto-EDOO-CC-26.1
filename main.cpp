#include "mapas.hpp"
#include "player.hpp"
#include "coordenada.hpp"
#include "coletavel.hpp"
#include "inimigo.hpp"
#include "excecoes.hpp"
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

    // instruções
    std::string instrucoes = "Usando as teclas W/A/S/D (capitalizadas ou não), movimente-se pelas áreas livres do mangue até reunir três coletáveis, dispersos pelo caminho.\n"
                             "Mas atenção: inimigos estão à espreita e, com apenas três ataques, poderão dar fim a sua jornada!\n"
                             "Será que você consegue concluir a missão?\n";

    // estado inicial
    std::cout << mapa;

    // fluxo de jogo
    while(not terminou)
    {
        try
        {
            // prompt movimento
            char movimento;
            std::cout << "Para onde você deseja se movimentar? (W/A/S/D) ";
            std::cin >> movimento;
            // padronização de entrada
            movimento = std::tolower(movimento);
            jogador.movimentoWASD(mapa, movimento);

            // fluxo sem exceção
            std::cout << "\n" << mapa << std::endl;
            jogador.checarEvento();

            if (inimigo.mover(mapa, jogador.getPosicao(), mapa.getMapaAtual()))
                jogador.tomarDano();
            if (jogador.getColetaveisQtde() == 3)
            {
                std::cout << "Parabéns! Você venceu os inimigos e juntou seus três coletáveis com sucesso!" << std::endl;
                terminou = true;
            }
            if (jogador.getVida() == 0)
            {
                std::cout << "Não foi dessa vez! Os inimigos conseguiram alcançá-lo!" << std::endl;
                terminou = true;
            }
            if (terminou) std::cout << "Fim de jogo!";

        } catch (const AcaoInvalidaException& e)
        {
            // mensagem de exceção caso encontrada
            std::cout << "\n" << e.getMensagem() << std::endl;
        }
    }

}