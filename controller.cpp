#include "controller.hpp"

void Controller::promptMovimento(Mapa mapaAtual)
{
    char movimento;
    std::cout << "Para onde você deseja se movimentar? (w/a/s/d) ";
    std::cin >> movimento;
    mapaAtual.movimentoWASD(movimento);

}