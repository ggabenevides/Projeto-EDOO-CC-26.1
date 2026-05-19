# Uma Aventura MangueBeat
## Projeto da disciplina Estrutura de Dados Orientadas a Objetos, do segundo período do curso de Ciência da Computação no CIn UFPE

A tarefa principal do projeto é traduzir um jogo implementado em Python em outra cadeira e por outra equipe para um sistema em C++ sem HUD e sem persistência.

_O projeto que escolhemos foi "Uma Aventura MangueBeat": este jogo apresenta uma jornada inspirada na cultura Manguebeat, evocando a energia artística de Chico Science. O jogador assume o papel de um explorador que precisa atravessar um ambiente hostil de mangue, enfrentando caranguejos protetores e coletando itens essenciais para avançar. O objetivo é provar seu valor e alcançar o santuário final, desviando de inimigos e superando desafios ao longo do caminho. Ele está disponível em https://github.com/safn007/Projeto-Final-IP---CC---2025.2._

---

## Estrutura dos arquivos

```
main.cpp
mapas.hpp / mapas.cpp
player.hpp / player.cpp
coletavel.hpp / coletavel.cpp
coordenada.hpp
```

---

## Detalhamento do código

### `struct Coordenada` (`coordenada.hpp`)
Estrutura simples para representar uma posição na matriz do mapa.

#### Dados
- `x`: coluna
- `y`: linha

Possui construtor com valores padrão 0: `Coordenada(int x0=0, int y0=0)`.

---

### Classe `Mapa` (`mapas.hpp` / `mapas.cpp`)
Gerencia os quatro mapas do jogo e toda a lógica de movimentação, colisão e transição entre mapas.

#### Dados
- `mapa`: `vector<vector<string>>` com 4 matrizes 10x10 (uma por mapa). Cada string representa uma linha; `'.'` é chão, `'#'` é parede.
- `mapaAtual`: inteiro (0–3) que indica o mapa onde o jogador se encontra.

Os mapas se conectam no seguinte modelo:
```
0 -- 2
|    |
1 -- 3
```
(`--` e `|` indicam passagens entre mapas nas bordas das matrizes.)

#### Métodos
- `Mapa()`: construtor; inicializa as 4 matrizes e define `mapaAtual = 0`.
- `getMapaAtual()`: retorna o índice do mapa atual.
- `podeMover(int mapaEscolhido, Coordenada novaPosicao)`: retorna `true` se a posição destino está dentro dos limites e é chão (`'.'`).
- `checarMudancaDeMapa(Coordenada& posicao)`: verifica se a posição está em uma borda de transição e, caso esteja, atualiza `mapaAtual` e reposiciona a coordenada na borda oposta do novo mapa. Retorna a coordenada (possivelmente modificada).
- `updateMapa(Coordenada posicaoAtual, Coordenada& novaPosicao)`: move um personagem no mapa — chama `checarMudancaDeMapa`, desenha o caractere na nova posição e apaga o da posição antiga. O parâmetro `novaPosicao` é passado por referência para refletir a posição final após possível troca de mapa.
- `drawElement(int mapaEscolhido, Coordenada posicao, char e)`: escreve um caractere `e` na posição indicada do mapa escolhido.
- `operator[](int index)`: retorna a linha `index` do mapa atual.
- `operator<<`: imprime o mapa atual no terminal (10 linhas).

---

### Classe `Player` (`player.hpp` / `player.cpp`)
Representa o jogador e controla seu movimento.

#### Dados
- `posicaoAtual`: `Coordenada` com a posição atual do jogador.
- `coletaveisQtde`: inteiro que conta quantos coletáveis o jogador já coletou. Ao chegar em 3, o jogo deve encerrar.

#### Métodos
- `Player(Mapa& mapa)`: construtor; posiciona o jogador em `(4, 5)` no mapa 0 e desenha `'P'` no mapa.
- `movimentoWASD(Mapa& mapa, char m)`: processa a entrada `w/a/s/d`, verifica com `podeMover` se o movimento é válido e, se for, chama `updateMapa` para atualizar o mapa e a posição interna do jogador.

  Mapeamento de teclas (em relação a `x` = coluna, `y` = linha):
  | Tecla | Efeito |
  |-------|--------|
  | `a`   | `y -= 1` (esquerda) |
  | `d`   | `y += 1` (direita) |
  | `w`   | `x -= 1` (cima) |
  | `s`   | `x += 1` (baixo) |

---

### Classe `Coletavel` (`coletavel.hpp` / `coletavel.cpp`)
Representa um item coletável espalhado aleatoriamente pelos mapas.

#### Dados
- `posicao`: `Coordenada` com a posição do coletável.
- `mapaEscolhido`: inteiro (0–3) que indica em qual mapa o coletável foi spawnado.

#### Métodos
- `Coletavel(Mapa& mapa)`: construtor; gera aleatoriamente um mapa (0–3) e coordenadas (0–9) até encontrar uma posição válida (chão livre), então desenha `'C'` nessa posição.

---

### `main.cpp`
Controla o fluxo de jogo:

1. Instancia `Mapa` e `Player` (o `'P'` já é desenhado no mapa no construtor).
2. Instancia 3 objetos `Coletavel`, cada um spawnando em posição aleatória válida.
3. Loop principal: lê entrada `w/a/s/d`, chama `movimentoWASD` e imprime o mapa atualizado a cada turno.

---

## Próximos passos
- Detectar coleta de `'C'` em `movimentoWASD` e incrementar `coletaveisQtde`
- Encerrar o loop da `main` quando `coletaveisQtde == 3`
- Implementar classe `Inimigo` com movimentação própria
- Adicionar mensagens de feedback ao jogador (coletou item, bloqueado por parede, troca de mapa)