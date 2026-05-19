#ifndef COORDENADA_HPP
#define COORDENADA_HPP

struct Coordenada //usada para identificar pontos na matriz
{
    int x;
    int y;
    Coordenada(int x0=0, int y0=0)
    {
        this->x = x0;
        this->y = y0;
    }
};

#endif