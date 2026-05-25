#ifndef MAPA_HPP
#define MAPA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // pra usar rand e srand
#include <time.h>
#include "coordenada.hpp"

class Mapa
{
    private:

        std::vector<std::vector<std::string>> mapa; //vetor de 4 matrizes 10x10, em que cada matriz é um mapa
        int mapaAtual; //indica qual das 4 matrizes é o mapa em que o jogador se encontra atualmente (0-3)
    
    public:

        Mapa (); 
        int getMapaAtual() {return mapaAtual;}
        std::string operator[](int index);

        bool podeMover(int mapaEscolhido, Coordenada novaPosicao);
        char getChar(int mapaEscolhido, Coordenada pos); // retorna o char na posição indicada do mapa escolhido
        Coordenada checarMudancaDeMapa(Coordenada& posicao);

        void updateMapa (Coordenada posicaoAtual, Coordenada& novaPosicao);
        void drawElement(int mapaEscolhido, Coordenada posicao, char e);

        friend std::ostream& operator<< (std::ostream& os, Mapa& mapa);

};

#endif