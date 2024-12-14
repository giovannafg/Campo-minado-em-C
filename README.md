# Jogo Campo Minado em C

  Este é o repositório do trabalho em grupo que desenvolvemos no 1º semestre da faculdade. O objetivo principal era aprender mais sobre programação em C e trabalhar com matrizes e lógica de jogo. O código está aqui como registro do que fizemos na época e não pretendo melhorá-lo.<br/>

Instruções de compilação e execução:<br/>
No terminal, o jogador deve realizar os seguintes comandos:<br/>
- gcc -c bomba.c -o bomba.o
- gcc campominado.c bomba.o -o campominado
- ./campominado <br/>
Assim, conseguirá jogar campo minado em seu terminal.


Representação dos elementos principais:
- ■: Casa fechada que ainda não foi aberta.
- □: Casa vazia (sem bombas vizinhas).
- 🚩: Bandeira colocada pelo jogador para marcar uma casa suspeita de conter uma bomba.
- 💥: Casa com bomba. <br/>
Obs: É importante garantir que o ambiente de execução suporte UTF-8 ou UTF-16, dependendo do sistema operacional.


As funções implementadas estão localizadas na biblioteca bomba.h e são:
- gerar_bombas: É responsável por distribuir bombas aleatoriamente pelo campo. Recebe como parâmetros o tamanho do campo (max) - estabelecido pela escolha do nível do jogador -, a matriz de células (matrix) e o número de bombas a serem colocadas (num_bombas). Assim, enquanto o numero de bombas_colocadas não atinge o  num_bombas, são adicionadas bombas no mapa.
- contador_bombs: Função que percorre a matriz para cada casa e calcula quantas bombas estão ao redor dela, preenchendo o campo matrix[i][j].bombs.
- printa_ou_n: Função que abre casas vazias (sem bombas vizinhas) e suas vizinhas automaticamente até encontrar casas com números.
- printarMatriz: Função que exibe o estado atual do campo no terminal, mostrando todas as casas abertas, fechadas, marcadas com bandeiras ou com bombas.
- vitoria: Função que verifica se todas as casas sem bombas foram abertas ou se todas as bombas foram marcadas com bandeiras, determinando se o jogador venceu o jogo.

Este projeto foi uma experiência muito legal no início da faculdade e mostra como a lógica de programação pode ser aplicada para criar algo divertido.
