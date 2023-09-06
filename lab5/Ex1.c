#include <stdio.h>
#include <stdlib.h>
#include "PILHA.h"

int compara(Pilha *p,Pilha *q){
    int valor1 = 0,valor2 = 0;

    valor1 = contaPilha(p);
    valor2 = contaPilha(q);

    if(valor1 == valor2){
        printf("valor igual");
        return 0;
    }
    if(valor1 > valor2){
        printf("pilha um é maior que a segunda");
        return 1;
    }
    if(valor1 < valor2){
        printf("pilha dois é maior que a primeira");
        return 2;
    }

}

int contaPilha(Pilha *p){

    int count;


    while(!vaziaPilha(p)){
        count++;
    }

    printf("Numero de elementos :%d",count);

    return count;
}

Pilha* inverte(Pilha *p){

    Pilha *x;

    x = CriaPilha();

    while(!vaziaPilha(p)){
        push(x,pop(p));
    }

    return x;
}

Pilha* rem(Pilha *p,int n){

    Pilha *x,*y;
    int valor;

    x = CriaPilha();

    while(!vaziaPilha(p)){
        valor = pop(p);

        if (valor!=n)
        {
            push(x,valor);
        }
    }
    y = inverte(x);

    return y;
}

int main()
{
    Pilha *p;
    Pilha *q;
    int n=2,j=0;

    p = CriaPilha();
    q = CriaPilha();


    for(int i;i<=10;i++)
    {

       push(p,i);

    }

    for(int j;i<=10;i++)
    {

       push(q,j);

    }

    imprimePilha(p);
    imprimePilha(q);

    /*p = inverte(p);

    printf("Pilha invertida:");

    imprimePilha(p);

    p = rem(p,n);

    imprimePilha(p);*/

    compara(p,q);

    return 0;
}

