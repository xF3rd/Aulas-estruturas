#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int val;
    struct no *prox;

}lista;

lista* inicializa(){

    return NULL;
}

lista* del(lista *aux){
    lista *inicio;
    inicio = aux->prox;
    free(aux);

    return inicio;
}

lista* add(lista *recebida,int valor){

    lista *novo;
    novo = (lista*)malloc(sizeof(lista));
    novo->val=valor;
    novo->prox=recebida;

    return novo;

}

void imprime(lista *aux){

    if(aux!=NULL){

        printf("\n\tLista: ");

        for(;aux!=NULL; aux=aux->prox){

            printf("%d ",aux->val);
        }
    }
}

int verifica(lista *aux) {
    if(aux!=NULL){
        return 0;
    }else{
        return 1;
    }



}

int main(){
    lista *comeca;
    int valor,vazio,j;

    comeca = inicializa();

    printf("Quantos num: ");
    scanf("%d",&j);

    for(int i=0 ; i<j; i++){

        printf("\nQual o valor q quer salvar:");

        scanf("%d",&valor);

        comeca = add(comeca,valor);
    }

    imprime(comeca);

    comeca = del(comeca);

    vazio = verifica(comeca);

    if(vazio == 1){
        printf("\nLista Vazia");
        return 0;
    }

    comeca = del(comeca);

    imprime(comeca);



return 0;
}
