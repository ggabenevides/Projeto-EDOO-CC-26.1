#ifndef MAPA_HPP
#define MAPA_HPP
#include <vector>
#include <string>

class Mapa
{
    private:

        std::vector<std::string> mapa; //matriz 10x10 em que '#' significa floresta e '.' significa caminho andável
        int x,y; //coordenadas da posição atual do jogador
        int mapa_atual;
    
    public:
        friend class Controller;
        int getX(){return x;}
        int getY(){return y;}
        void setMapa (int mapa_atual=0);
        bool podeMover(int x, int y);
        void movimentoWASD(char m);

};

#endif