///---Funcoes.h---

void display(Grid * gamegrid){
    int i=0, gridcount=0, lin, col;
    char top[50] = "\\ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    Grid * temp = gamegrid;

    lin = out_lin_col(gamegrid, 0);
    col = out_lin_col(gamegrid, 1);

    for(i=0;i<col+1;i++){
        printf("%c ",top[i]);
    }
    i = 0;
    printf("\n%d",i+1);

    if(temp==NULL) printf("temp = null\n");

    while(temp->prox != NULL){
        temp = temp->prox;
        if(temp->col == col && temp->lin != lin){
            i++;
            printf(" %c", temp->cont);
            printf("\n%d",i+1);
        }else{
            printf(" %c", temp->cont);
        }
    }
    printf("\n");
}

Grid * addGridIni(Grid *gamegrid, char cont){
    Grid *novo, *aux;
    aux = gamegrid;
    novo = /*(Grid *) */malloc( sizeof( Grid));
    if(novo == NULL) exit(0);
    novo->cont = cont;
    novo->prox = aux->prox;
    aux->prox = novo;
    return(aux);
}

Grid * addGridEnd(Grid *gamegrid, char cont, int lin, int col){
    Grid *aux = gamegrid;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = malloc(sizeof(Grid));
    aux->prox->cont = cont;
    aux->prox->lin = lin;
    aux->prox->col = col;
    aux->prox->prox = NULL;

    return gamegrid;
}

Grid * make_grid(Grid * gamegrid, int c, int l){
    int linhas, colunas;

    for(linhas=0;linhas<l;linhas++){
        for(colunas=0;colunas<c;colunas++){
            if(linhas==l-1 && colunas==c-1){
                gamegrid = addGridEnd(gamegrid,'X',linhas+1,colunas+1);
                return gamegrid;
            }else{
                gamegrid = addGridEnd(gamegrid,'*',linhas+1,colunas+1);
            }
        }
    }
}

int grid_size_check(int c, int l){
    if(c<=10 && c>=6){
        if(l<=8 && l>=4){
            if(c>l){
                return 1;
            }else{
                printf("Tamanho da grelha de jogo invalido!\n");
                return 0;
            }
        }else{
            printf("Tamanho da grelha de jogo invalido!\n");
            return 0;
        }
    }else{
        printf("Tamanho da grelha de jogo invalido!\n");
        return 0;
    }
}

int out_lin_col(Grid * gamegrid, int val){///val = 0 -> linhas // val = 1 -> colunas
    int output;
    Grid * temp = gamegrid;

    if(val==0){/// linhas
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        output = temp->lin;
    }else if(val==1){/// colunas
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        output = temp->col;
    }else{
        printf("Erro!\n");
    }

    return output;
}

int win_cond(Grid * gamegrid, int jog){
    return 0;
}
