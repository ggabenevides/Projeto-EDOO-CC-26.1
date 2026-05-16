#ifndef MAPA_HPP
#define MAPA_HPP
#include <vector>
#include <string>
#include <cstdlib> // pra usar rand e srand
#include <time.h>
#include "coordenada.hpp"

class Mapa
{
    private:

        std::vector<std::string> mapa; //matriz 10x10 em que '#' significa floresta e '.' significa caminho andável
        int mapa_atual; //indica qual das 4 matrizes é o mapa atual (0-3)
    
    public:
        friend class Controller;
        friend class Player;
        void setMapa (int mapa_atual=0);
        bool podeMover(int x, int y);

};

#endif