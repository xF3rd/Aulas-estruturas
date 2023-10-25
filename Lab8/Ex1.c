#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore{
    int info;
    struct NoArvore *esq;
    struct NoArvore *dir;
}NoArv;

typedef struct Base{

    NoArv *raiz;
}Arv;

Arv* CriaArvore(){

    Arv *aux;
    aux = (Arv*)malloc(sizeof(Arv));
    aux->raiz = NULL;
    return aux;

}

int ArvVazia(Arv *base){

    if(base->raiz == NULL){
        return 1;
    }

    return 0 ;
}

NoArv* aux_insere(NoArv *no,int num){

    int flag;
    NoArv *pai;
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;

    if(no==NULL){
        return novo;
    }else{

        pai = no;
        flag = 0;

        while(flag == 0){

            if(pai->info < num){
                if(pai->dir == NULL){
                    pai->dir = novo;
                    flag = 1;
                }else{
                    pai = pai->dir;
                }
            }else{

                if(pai->info > num){

                    if(pai->esq == NULL){

                        pai->esq = novo;
                        flag = 1;
                    }else{
                        pai=pai->esq;
                    }
                }
            }
        }
    }
    return no;
}


void InsereArv(Arv *arvore,int num){

    arvore->raiz = aux_insere(arvore->raiz,num);
}

void posorder(NoArv *pai){

    if(pai != NULL){
        posorder(pai->dir);
        posorder(pai->esq);
        printf("%d ", pai->info);
    }

}

int main(){

    int j,valor = 0;
    Arv *tree;

    tree = CriaArvore();

    printf("Quantos num: ");
    scanf("%d",&j);

    for(int i = 0 ; i < j; i++){

        printf("\nQual o valor q quer salvar:");

        scanf("%d",&valor);

        InsereArv(tree,valor);
    }

    posorder(tree->raiz);

return 0;
}
