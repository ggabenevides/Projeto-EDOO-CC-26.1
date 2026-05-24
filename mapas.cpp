#include "mapas.hpp"

Mapa::Mapa () 
{
    // mapa inicial
    std::vector<std::string> mapa0 = {
        "##########",
        "##########",
        "##......##",
        "##.###..##",
        "##........", 
        "###...####",
        "##..#..###",
        "##.###....",
        "##.....###",
        "####..####"
    };

    std::vector<std::string> mapa1 = {
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

    std::vector<std::string> mapa2 = {
        "##########",
        "##......##",
        "##.##...##",
        "#......###",
        ".......###",
        "##..#...##",
        "##......##",
        "........##",
        ".#......##",
        ".####..###"
    };

    std::vector<std::string> mapa3 = {
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

    // inicializando data member com valores iniciais p matrizes de mapa        
    mapa.push_back(mapa0);
    mapa.push_back(mapa1);
    mapa.push_back(mapa2);
    mapa.push_back(mapa3);

    // inicializando data member com valor inicial
    mapaAtual = 0;

};


// função que avalia se o movimento é válido
bool Mapa::podeMover(int mapaEscolhido, Coordenada novaPosicao) {
    // garante que o jogador não saia dos limites da matriz 10x10 e spawne um erro de memória
    if (novaPosicao.y < 0 || novaPosicao.y >= 10 || novaPosicao.x < 0 || novaPosicao.x >= 10) {
        return false;
    }
    char c = mapa[mapaEscolhido][novaPosicao.y][novaPosicao.x];
    // retorna verdadeiro se for chão ou coletável; falso se for parede
    return c == '.' || c == 'C';
}

// retorna o char na posição indicada do mapa escolhido
char Mapa::getChar(int mapaEscolhido, Coordenada pos) {
    return mapa[mapaEscolhido][pos.y][pos.x];
}

Coordenada Mapa::checarMudancaDeMapa(Coordenada& posicao) {
    
    /*
    lembrando: 
    0 -- 2
    |    |
    1 -- 3
    */

    if (mapaAtual == 0) {
        // saiu pela DIREITA (linha 4 ou 7) -> vai para o MAPA 2 (esquerda)
        if (posicao.x == 9 && (posicao.y == 4 || posicao.y == 7)) {
            mapaAtual = 2;
            posicao.x = 0; // aparece na borda esquerda do Mapa 1
        }
        // saiu por BAIXO (coluna 4 ou 5) -> vai para o MAPA 1 (Cima)
        if (posicao.y == 9 && (posicao.x == 4 || posicao.x == 5)) {
            mapaAtual = 1;
            posicao.y = 0; // aparece no topo do Mapa 2
        }
    }

    // TRANSIÇÕES DO MAPA 1
    else if (mapaAtual == 1) {
        // saiu pela DIREITA (linha 3 ou 4) -> vai para o MAPA 3 (Direita)
        if (posicao.x == 9 && (posicao.y == 3 || posicao.y == 4)) {
            mapaAtual = 3;
            posicao.x = 0; // aparece na borda esquerda do mapa 3
        }
        // saiu por CIMA (coluna 4 ou 5) -> volta para o MAPA 0 (Baixo)
        if (posicao.y == 0 && (posicao.x == 4 || posicao.x == 5)) {
            mapaAtual = 0;
            posicao.y = 9; // aparece no fundo do mapa 0
        }
    }

    // TRANSIÇÕES DO MAPA 2
    else if (mapaAtual == 2) {
        // saiu por BAIXO (coluna 4 ou 5) -> vai para o MAPA 3 (cima)
        if (posicao.y == 9 && (posicao.x == 5 || posicao.x == 6)) {
            mapaAtual = 3;
            posicao.y = 9; // aparece no topo do mapa 3
        }
        // saiu pela ESQUERDA (linhas 5 ou 6) -> vai para o MAPA 0 (direita)
        if (posicao.x == 0 && (posicao.y == 4 || posicao.y == 7)) {
            mapaAtual = 0;
            posicao.x = 9; // aparece no canto direito do mapa 0
        }
    }

    // TRANSIÇÕES DO MAPA 3
    else if (mapaAtual == 3) {
        // saiu por CIMA (coluna 5 ou 6) -> volta para o MAPA 2 (baixo)
        if (posicao.y == 0 && (posicao.x == 5 || posicao.x == 6)) {
            mapaAtual = 2;
            posicao.y = 9; // aparece no fundo do Mapa 2
        }
        // saiu pela ESQUERDA (linha 3 ou 4) -> vai para o MAPA 1 (direita)
        if (posicao.x == 0 && (posicao.y == 3 || posicao.y == 4)) {
            mapaAtual = 1; //
            posicao.x = 9;
        }
    }

    // retorna a coordenada após a checagem e atualização de mapas; se não houve mudança, o valor retornado será igual aos parâmetros
    return posicao;
}

// função para atualizar mapa com movimentos de personagens que se movem (inimigo, player)
void Mapa::updateMapa(Coordenada posicaoAtual, Coordenada& novaPosicao)
{
    // identificar qual o char identificador na posicao atual e armazenar ele
    char temp = mapa[mapaAtual][posicaoAtual.y][posicaoAtual.x];
    // guardando mapa antigo p conseguir apagar posição antiga em caso de mudança de mapa
    int mapaAntigo = mapaAtual;

    // colocar o char na nova posicao
    // assumir que validade do movimento foi checada antes
    novaPosicao = checarMudancaDeMapa(novaPosicao);
    drawElement(mapaAtual, novaPosicao, temp);
    // substituir posicao antiga por '.'
    drawElement(mapaAntigo, posicaoAtual, '.');
    
}

// função generalizada para expressar algo no mapa
void Mapa::drawElement(int mapaEscolhido, Coordenada posicao, char e)
{
    mapa[mapaEscolhido][posicao.y][posicao.x] = e;
}

std::string Mapa::operator[](int index)
{
    return this->mapa[this->mapaAtual][index];
} 

std::ostream& operator<< (std::ostream& os, Mapa& mapa)
{
    for (int i = 0; i < 10; i++)
    {
        os << mapa[i] + "\n";
    }
    return os;
}