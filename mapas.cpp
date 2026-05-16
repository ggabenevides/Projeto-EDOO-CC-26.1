#include "mapas.hpp"

void Mapa::setMapa (int mapaAtual) 
{
    switch (mapaAtual) {

        case 1:
            mapa = {
                "####..####",
                "##......##",
                "##.#..#.##",
                "##..#.....",
                "##.##.....",
                "##.###..##",
                "###...#.##",
                "###.....##",
                "####....##",
                "##########"
            };
            break;

        case 2:
            mapa = {
                "##########",
                "##......##",
                "##.##...##",
                "#......###",
                ".......###",
                "##..#...##",
                "##......##",
                "........##",
                "##......##",
                "#####..###"
            };
            break;

        case 3:
            mapa = {
                "#####..###",
                "##......##",
                "##......##",
                "........##", 
                "....#...##",
                "#.....####",
                "###...####",
                "###..#..##",
                "####....##",
                "##########"
            };
            break;
            
        default:
        // mapa inicial
            mapa = {
                "##########",
                "##########",
                "##......##",
                "##.###..##",
                "##...P....", // posição inicial do jogador
                "###...####",
                "##..#..###",
                "##.###....",
                "##.....###",
                "####..####"
            };
            break;
        }
};


// função que avalia se o movimento é válido
bool Mapa::podeMover(int x, int y) {
    // garante que o jogador não saia dos limites da matriz 10x10 e spawne um erro de memória
    if (y < 0 || y >= 10 || x < 0 || x >= 10) {
        if (mapa_atual == 0 && ((x>=10 && (y==4 || y==7)) || (y>=10 && (x==4 || x==5))))
        {
            return true;
            //mudança de mapa 1->2 ou 1->3
        }
        return false;
    }
    // retorna verdadeiro se for ponto (chão), falso se for qualquer outra coisa (parede)
    return mapa[y][x] == '.';
}