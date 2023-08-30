#include <stdio.h>
#include <stdlib.h>

typedef struct produto{

    int cod,quant;
    float valCompra,valVenda;

}prod;


prod* atribui(int a, int b, float c, float d){
    prod *aux;

    aux = (prod *)malloc(1*sizeof(prod));
    aux->cod=a;
    aux->quant=b;
    aux->valCompra=c;
    aux->valVenda=d;

    return aux;

}

int main() {
    prod *produto[10];
    int a,b;
    float c,d;

    for(int i = 0 ; i < 2 ; i++){
        printf("Codigo do prod:");
        scanf("%d",&a );

        printf("Codigo do quant:");
        scanf("%d",&b);

        printf("Codigo do compra:");
        scanf("%f",&c);

        printf("Codigo do venda:");
        scanf("%f",&d);

        produto[i] = atribui(a,b,c,d);

    }

    for(int i=0; i<2 ; i++){
        printf("\n %d \n %d \n %.2f \n %.2f",produto[i]->cod,produto[i]->quant,produto[i]->valCompra,produto[i]->valVenda);
    }

    free(produto[10]);


return 0;
}
