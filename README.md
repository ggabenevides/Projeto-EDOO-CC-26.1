# Uma Aventura MangueBeat
## Projeto da disciplina Estrutura de Dados Orientadas a Objetos, do segundo período do curso de Ciência da Computação no CIn UFPE

A tarefa principal do projeto é traduzir um jogo implementado em Python em outra cadeira e por outra equipe para um sistema em C++ sem HUD e sem persistência.

_O projeto que escolhemos foi "Uma Aventura MangueBeat": este jogo apresenta uma jornada inspirada na cultura Manguebeat, evocando a energia artística de Chico Science. O jogador assume o papel de um explorador que precisa atravessar um ambiente hostil de mangue, enfrentando caranguejos protetores e coletando itens essenciais para avançar. O objetivo é provar seu valor e alcançar o santuário final, desviando de inimigos e superando desafios ao longo do caminho. Ele está disponível em https://github.com/safn007/Projeto-Final-IP---CC---2025.2._

## Detalhamento do código
### Classe Mapa: lida com lógica de movimentação e colisões
#### Dados
- X, Y: coordenadas atuais do jogador
- mapa: matriz 10x10 em que o jogador está navegando atualmente
- mapa_atual: inteiro (0-3) que indica qual o mapa atual

OBS.: as matrizes de mapa apresentam uma continuidade no seguinte modelo:
```
1 -- 3
|    |
2 -- 4
```
em que -- ou | indicam que é possível se deslocar de uma matriz a outra.

#### Métodos
- setMapa: troca a matriz base onde o jogador está se mexendo
- podeMover: verifica se as coordenadas para as quais o jogador deseja se mexer são válidas
- updateMapa: atualiza o mapa de acordo com o movimento desejado - seja apenas atualizando a matriz com a nova posição do jogador ou então trocando de mapa (usando ```setMapa()```)
- movimentoWASD: trata a entrada WASD usando ```podeMover()``` para verificar se é válida

### Classe Controller: controla o fluxo de jogo
#### Métodos
- promptMovimento: pergunta ao jogador qual deve ser seu próximo movimento; caso seja de deslocamento WASD, usa o método ```movimentoWASD()``` do objeto ```mapaAtual```, uma instância da classe ```Mapa``` para tratar a entrada.