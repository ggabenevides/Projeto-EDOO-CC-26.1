#include "objeto.hpp"

Objeto::Objeto(Mapa& mapa, char simbolo){

    // inicializando coordenadas com valores válidos (apenas chão livre)
    bool valido = false;

    Coordenada item;
    while (not valido)
    {
        mapaEscolhido = std::rand() % 4; // número entre 0 e 3 p indicar qual foi o mapa escolhido
        item.x = std::rand() % 10; // operações para garantir que o número gerado estará entre 0 e 10 para caber na matriz
        item.y = std::rand() % 10;
        if (mapa.getChar(mapaEscolhido, item) == '.')
        {
            valido = true;

            // armazenando posição válida nos dados da classe
            posicaoAtual = item;
        }
    }

    mapa.drawElement(mapaEscolhido, posicaoAtual, simbolo);
}
