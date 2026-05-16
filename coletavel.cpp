#include "coletavel.hpp"

void Coletavel::spawnColetavel(Mapa mapa){

    // inicializando coordenadas dos coletaveis com valores válidos
    int min = 0, max = 10;
    srand(time(0));
    bool valido = false;

    Coordenada item;
    while (not valido)
    {
        item.x = std::rand() % (max - min + 1) + min; //operações para garantir que o número gerado estará entre 0 e 10 para caber na matriz
        item.y = std::rand() % (max - min + 1) + min;
        if (mapa.podeMover(item.x, item.y))
        {
            valido = true;

            //armazenando posição válida nos dados da classe
            posicao.x = item.x;
            posicao.y = item.y;
        }
    }

    // alterando matrizes com as coordenadas geradas 
}