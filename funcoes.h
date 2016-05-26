///---Funcoes.h---

void display(Grid * gamegrid){
    int i=0, i2, ptop=0, gridcount=0;
    char top[50] = "\\ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    Grid * temp = gamegrid;
    Grid * temp2 = gamegrid;

    while(temp->cont != '+'){
        printf("%c ",top[ptop]);
        ptop++;
        temp = temp->prox;
    }
    printf("\n%d",i+1);
    if(temp2==NULL) printf("temp2 = null\n");
    while(temp2->cont != NULL){
        if(temp2->cont == '+'){
            printf("temp2 = +\n");
            i++;
            printf("\n%d",i+1);
        }else{
            printf("temp2 != +\n");
            printf(" %c", temp2->cont);
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

Grid * addGridEnd(Grid *gamegrid, char cont){
    Grid *aux = gamegrid;

    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = malloc(sizeof(Grid));
    aux->prox->cont = cont;
    aux->prox->prox = NULL;

    return gamegrid;
}


Grid * make_grid(Grid * gamegrid, int c, int l){
    int linhas, colunas;

    gamegrid->prox = NULL;

    for(linhas=0;linhas<l;linhas++){
        for(colunas=0;colunas<c;colunas++){
            if(linhas==l-1 && colunas==c-1){
                gamegrid = addGridEnd(gamegrid,'X');
                return gamegrid;
            }else{
                gamegrid = addGridEnd(gamegrid,'*');
            }
        }
            gamegrid = addGridEnd(gamegrid,'+');
    }
}

int grid_size_check(int c, int l){
    if(c<=10 || c>=6){
        if(l<=8 || l>=4){
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
