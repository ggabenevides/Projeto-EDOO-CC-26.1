# Uma Aventura MangueBeat
## Projeto da disciplina Estrutura de Dados Orientadas a Objetos, do segundo período do curso de Ciência da Computação no CIn UFPE

A tarefa principal do projeto é traduzir um jogo implementado em Python em outra cadeira e por outra equipe para um sistema em C++ sem HUD e sem persistência.

_O projeto que escolhemos foi "Uma Aventura MangueBeat": este jogo apresenta uma jornada inspirada na cultura Manguebeat, evocando a energia artística de Chico Science. O jogador assume o papel de um explorador que precisa atravessar um ambiente hostil de mangue, enfrentando caranguejos protetores e coletando itens essenciais para avançar. O objetivo é provar seu valor e alcançar o santuário final, desviando de inimigos e superando desafios ao longo do caminho. Ele está disponível em https://github.com/safn007/Projeto-Final-IP---CC---2025.2._

---

## Compilação e execução

### Pré-requisitos

- Compilador C++ com suporte a C++17 ou superior (g++ recomendado)

### Compilando

Na raiz do projeto, compile todos os arquivos `.cpp` de uma vez:

```bash
g++ main.cpp mapas.cpp player.cpp objeto.cpp coletavel.cpp inimigo.cpp excecoes.cpp -o manguebeat
```

### Executando

```bash
./manguebeat
```

---

## Como jogar

Use as teclas **W/A/S/D** (maiúsculas ou minúsculas) para movimentar o personagem pelo mapa:

| Tecla | Direção  |
|-------|----------|
| `W`   | Cima     |
| `S`   | Baixo    |
| `A`   | Esquerda |
| `D`   | Direita  |

O jogador (`P`) deve **coletar 3 itens** (`C`) espalhados pelos mapas para vencer. Fique atento ao inimigo (`I`) — cada colisão retira 1 ponto de vida. O jogo termina com vitória ao coletar todos os itens, ou com derrota ao perder todos os 3 pontos de vida.

Os quatro mapas se conectam entre si: caminhar até a borda de um mapa transporta o jogador para o mapa adjacente.

---

## Estrutura dos arquivos

```
main.cpp
mapas.hpp / mapas.cpp
player.hpp / player.cpp
objeto.hpp / objeto.cpp
coletavel.hpp / coletavel.cpp
inimigo.hpp / inimigo.cpp
excecoes.hpp / excecoes.cpp
coordenada.hpp
```

---

## Detalhamento do código

### `struct Coordenada` (`coordenada.hpp`)
Estrutura simples para representar uma posição na matriz do mapa.

#### Dados
- `x`: linha
- `y`: coluna

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
- `podeMover(int mapaEscolhido, Coordenada novaPosicao)`: retorna `true` se a posição destino está dentro dos limites e é chão (`'.'`) ou coletável (`'C'`).
- `getChar(int mapaEscolhido, Coordenada pos)`: retorna o caractere na posição indicada do mapa escolhido.
- `checarMudancaDeMapa(Coordenada& posicao)`: verifica se a posição está em uma borda de transição e, caso esteja, atualiza `mapaAtual` e reposiciona a coordenada na borda oposta do novo mapa. Retorna a coordenada (possivelmente modificada).
- `updateMapa(Coordenada posicaoAtual, Coordenada& novaPosicao)`: move um personagem no mapa — chama `checarMudancaDeMapa`, desenha o caractere na nova posição e apaga o da posição antiga. O parâmetro `novaPosicao` é passado por referência para refletir a posição final após possível troca de mapa.
- `drawElement(int mapaEscolhido, Coordenada posicao, char e)`: escreve um caractere `e` na posição indicada do mapa escolhido.
- `operator[](int index)`: retorna a linha `index` do mapa atual.
- `operator<<`: imprime o mapa atual no terminal (10 linhas).

---

### Classe `Objeto` (`objeto.hpp` / `objeto.cpp`)
Classe base abstrata para todas as entidades não controláveis posicionadas no mapa (coletáveis e inimigo). Centraliza a lógica de spawn aleatório e define a interface polimórfica.

#### Dados (protected)
- `posicaoAtual`: `Coordenada` com a posição atual da entidade.
- `mapaEscolhido`: inteiro (0–3) que indica em qual mapa a entidade foi spawnada.

#### Métodos
- `Objeto(Mapa& mapa, char simbolo)`: construtor; gera aleatoriamente um mapa (0–3) e coordenadas (0–9) até encontrar uma posição de chão livre (`'.'`), então desenha `simbolo` nessa posição.
- `getPosicao()`: retorna `posicaoAtual`.
- `getMapa()`: retorna `mapaEscolhido`.
- `mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer)`: método virtual puro — cada subclasse define seu próprio comportamento de movimentação.
- `~Objeto()`: destrutor virtual, garantindo destruição correta ao deletar via ponteiro base.

---

### Classe `Coletavel` (`coletavel.hpp` / `coletavel.cpp`)
Herda de `Objeto`. Representa um item estático no mapa que o jogador pode coletar, spawnando com o símbolo `'C'`.

#### Métodos
- `Coletavel(Mapa& mapa, char simbolo = 'C')`: construtor; repassa os parâmetros para `Objeto`.
- `mover(...)`: implementação concreta do método virtual — sempre retorna `false`, pois coletáveis não se movem.

---

### Classe `Inimigo` (`inimigo.hpp` / `inimigo.cpp`)
Herda de `Objeto`. Representa um inimigo que persegue o jogador, spawnando com o símbolo `'I'`.

#### Métodos
- `Inimigo(Mapa& mapa)`: construtor; chama `Objeto(mapa, 'I')` para spawnar o inimigo em posição aleatória válida.
- `mover(Mapa& mapa, Coordenada posicaoPlayer, int mapaPlayer)`: move o inimigo um passo em direção ao jogador se estiver no mesmo mapa. Tenta movimento diagonal primeiro (fiel ao Python que atualiza x e y simultaneamente); se bloqueado, cai para o eixo de maior diferença. Retorna `true` se o inimigo atingiu a célula do jogador (colisão), `false` caso contrário. Não sobrescreve coletáveis nem o jogador ao se mover.

---

### Classe `Player` (`player.hpp` / `player.cpp`)
Representa o jogador, controla seu movimento e lança exceções em caso de ação inválida.

#### Dados
- `posicaoAtual`: `Coordenada` com a posição atual do jogador.
- `coletaveisQtde`: inteiro que conta quantos coletáveis o jogador já coletou. Ao chegar em 3, o jogo encerra.
- `vida`: inteiro que representa os pontos de vida do jogador (começa em 3). Ao chegar em 0, o jogo encerra.
- `novoColetavel`: booleano que indica a adição de um novo coletável.
- `colisao`: booleano que indica um novo ataque do inimigo.

#### Métodos
- `Player(Mapa& mapa)`: construtor; posiciona o jogador em `(4, 5)` no mapa 0 e desenha `'P'` no mapa.
- `movimentoWASD(Mapa& mapa, char m)`: processa a entrada `w/a/s/d`, verifica com `podeMover` se o movimento é válido e, se for, detecta coleta de `'C'` (incrementando `coletaveisQtde`) e chama `updateMapa` para atualizar o mapa e a posição interna do jogador.
- `tomarDano()`: decrementa `vida` em 1 (chamado pela `main` quando o inimigo atinge o jogador).
- `checarEvento()`: imprime mensagem em caso de adição de um novo coletável ou de colisão com o inimigo.
- `getColetaveisQtde()`: retorna `coletaveisQtde`.
- `getPosicao()`: retorna `posicaoAtual`.
- `getVida()`: retorna `vida`.

Mapeamento de teclas (em relação a `x` = coluna, `y` = linha):

| Tecla | Efeito            |
|-------|-------------------|
| `a`   | `x -= 1` (esquerda) |
| `d`   | `x += 1` (direita)  |
| `w`   | `y -= 1` (cima)     |
| `s`   | `y += 1` (baixo)    |

---

### Classe `AcaoInvalidaException` (`excecoes.hpp` / `excecoes.cpp`)
Trata exceções em caso de ação inválida.

#### Dados
- `mensagem`: string para armazenamento da mensagem impressa.

#### Métodos
- `AcaoInvalidaException(const std::string& msg)`: construtor; inicializa o atributo `mensagem`.
- `getMensagem()`: método `const` que retorna a mensagem.

---

### `main.cpp`
Controla o fluxo de jogo:

1. Instancia `Mapa` e `Player` (o `'P'` já é desenhado no mapa no construtor).
2. Instancia 3 objetos `Coletavel` via ponteiros, armazenados em `vector<Coletavel*>`, cada um spawnando em posição aleatória válida.
3. Instancia 1 objeto `Inimigo`, spawnando em posição aleatória válida.
4. Imprime mensagens iniciais de boas-vindas e instruções.
5. Loop principal:
   - lê e padroniza entrada `W/A/S/D`;
   - chama `movimentoWASD`;
   - chama `checarEvento`;
   - move o inimigo;
   - verifica condições de fim de jogo;
   - imprime o mapa atualizado a cada turno e mensagens personalizadas para novo evento;
   - trata exceções caso identificadas;
   - encerra-se quando `coletaveisQtde == 3` (vitória) ou `vida == 0` (derrota).

---

## Hierarquia de classes

```
Objeto  (abstrata — virtual mover, virtual ~Objeto)
├── Coletavel   → mover() sempre retorna false
└── Inimigo     → mover() implementa perseguição ao jogador
```

Os coletáveis são gerenciados na `main` via `vector<Coletavel*>`, permitindo alocação dinâmica e tratamento polimórfico das entidades do mapa.