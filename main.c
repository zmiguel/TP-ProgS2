#include <stdio.h>
#include <tgmath.h>
#include <ctype.h>
#include <string.h>
///headers

int win = 0;

#include "estruturas.h"
#include "funcoes.h"

void main(void){
    int i,c=0,l=0;

    Grid *GameGrid = NULL;
    GameSave *Hist = NULL;

    GameGrid = malloc(sizeof(Grid));
    Hist = malloc(sizeof(GameSave));

    if(GameGrid == NULL) printf("ERRO a criar GameGrid");
    if(Hist == NULL) printf("ERRO a criar Hist");

    printf("Bem-Vindo!\n");

    do{
        printf("Indique os tamanhos para a grelha de jogo [COLUNAS   LINHAS] --> ");
        scanf("%d %d", &c, &l);
    }while(grid_size_check(c,l)==0);
    printf("\n");
    GameGrid = make_grid(GameGrid,c,l); ///cria a grelha de jogo
    display(GameGrid); ///mostra grelha de jogo

    int jog=0, jogada=0, linha;
    char coluna;

    int icol=0;

    do{///ciclo de jogo principal aqui:
        jog=jogada%2 +1;

        do{ /// ciclo ate os dados inceridos serem validos
            fflush(stdin);
            printf("\n[Jogador %d]:[LIN COL]:[3 B] -> ", jog);
            scanf("%d %c", &linha, &coluna);
            fflush(stdin);
        }while(valida_jogada(GameGrid,convert_to_number(coluna),linha)!=1);

        Hist = save_jog(Hist,jogada,convert_to_number(coluna),linha); ///gravar as jogadas
        GameGrid = jogar(GameGrid,convert_to_number(coluna),linha); ///jogar
        display(GameGrid); ///mostrar grelha de jogo

    jogada++;
    }while(win!=1);

    printf("\n\tO VENCEDOR E O JOGADOR %d", jog);
}
