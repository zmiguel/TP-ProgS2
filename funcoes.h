///---Funcoes.h---

void display(Grid *gamegrid){
    int i=0, i2, ptop, gridcount=0;
    char top[50] = "\\ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    Grid *temp;

    temp = gamegrid;

    while(temp->cont != "+"){
        printf("%c ",top[ptop]);
        ptop++;
    }
    printf("\n%d",i+1);
    while(gamegrid->cont != NULL){
        if(gamegrid->cont == "+"){
            i++;
            printf("\n%d",i+1);
        }else{
            printf(" %c", gamegrid->cont);
        }
    }
}

Grid * addGridIni(Grid *gamegrid, char cont){
    Grid *novo, *aux;
    aux = gamegrid;
    novo = (Grid *) malloc( sizeof( Grid));
    if(novo == NULL) exit(0);
    novo->cont = cont;
    novo->prox = aux->prox;
    aux->prox = novo;
    return(aux);
}

void addGridEnd(Grid **gamegrid, char cont){
    Grid *novo;
    novo = (Grid *) malloc( sizeof( Grid));
    if(novo == NULL) exit(0);
    novo->cont = cont;
    novo->prox = NULL;

    if(*gamegrid == NULL){
        *gamegrid = novo;
    }else{
        Grid *aux;
        aux = *gamegrid;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        *gamegrid = aux;
    }
}

Grid * make_new(){
    Grid *novo, *aux;
    novo = (Grid *)malloc(sizeof(Grid));
    if(novo == NULL) exit(0);
    novo->prox = NULL;
    aux = novo;
    return(aux);
}

Grid * make_grid(int c, int l){
    Grid *novo, *aux;
    novo = (Grid *)malloc(sizeof(Grid));
    int linhas, colunas;

    if(novo == NULL) exit(0);

    for(linhas=0;linhas<l;linhas++){
        for(colunas=0;colunas<c;colunas++){
            if(linhas==l-1 && colunas==c-1){
                printf ("sizeof (aux) = %d\n", sizeof (novo));
                printf("add x\n");
                addGridEnd(novo,"X");
            }else{
                printf ("sizeof (aux) = %d\n", sizeof (novo));
                printf("add *\n");
                addGridEnd(novo,"*");
            }
        }
            printf ("sizeof (aux) = %d\n", sizeof (novo));
            printf("add +\n");
            addGridEnd(novo,"+");
    }
    aux = novo;
    return(aux);
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
