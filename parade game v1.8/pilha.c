#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "jogo.h"

struct pilha{
    struct carta Carta;
    struct pilha * prox;
};

Pilha * criar (){
    Pilha * pi;
    pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

int inserir (Pilha *pi, struct carta nova){
    if (pi == NULL){
        return 0;
    }
    else{
        struct pilha * novapilha = (struct pilha*)malloc(sizeof(struct pilha));
        if(novapilha == NULL){
            return 0;
        }
        novapilha->Carta = nova;
        novapilha->prox = *pi;
        *pi = novapilha;
        return 1;
    }
}

int remover(Pilha * pi, struct carta * acessar){
    if (pi == NULL){
        return 0;
    }
    else{
        *acessar = (*pi)->Carta;
        struct pilha * aux = *pi;
        *pi = aux->prox;
        free(aux);
        return 1;
    }
}

int tamanho(Pilha *pi){
    if (pi == NULL){
        return 0;
    }
    else{
        struct pilha * aux = *pi;
        int tam = 0;
        while(aux!=NULL){
            tam ++;
            aux = aux->prox;
        }
        return tam;
    }
}

int imprimir(Pilha * pi){
    if (pi == NULL){
        return 0;
    }
    struct pilha * aux = *pi;
    printf("\n[CARTAS]->");
    while(aux!=NULL){
        printf("[%d  %c] -> ", aux->Carta.numero, aux->Carta.letra);
        aux = aux->prox;
    }
    int tam =  tamanho(pi);
    printf("|| Baralho (%d cartas)\n", tam);
    return 1;
}

int mexer(Pilha * pi){
     if (pi == NULL){
        return 0;
    }
    else{
        struct pilha * novapilha = (struct pilha*)malloc(sizeof(struct pilha));
        if(novapilha == NULL){
            return 0;
        }
        novapilha->Carta = (*pi)->Carta;
        struct pilha * aux = *pi;
        struct pilha* ant = aux;

        int tam = tamanho(pi);
        int posicao = 1+(rand() % tam);

        if(tam == posicao){
            struct pilha * aux_1 = *pi;
            while(aux_1->prox!=NULL){
                aux_1 = aux_1->prox;
            }
            aux_1->prox = novapilha;
            novapilha->prox = NULL;
            *pi = (*pi)->prox;
            return 1;
        }
        if(posicao == 1){
            free(novapilha);
            return 1;
        }
        else{
            int cont_aux = 0;
            while (cont_aux!= posicao){
                ant = aux;
                aux = aux->prox;
                cont_aux ++;
            }
            ant->prox = novapilha;
            novapilha->prox = aux;
            *pi = (*pi)->prox;
        }
        return 1;
    }
}

int embaralhar(Pilha * pi){
    int cont = 1;
    while(cont!=1000){
        mexer(pi);
        cont++;
    }
    return 1;
}

Pilha * criar_baralho(){
    Pilha * baralho;
    baralho = criar();
    char nipe[6] = "ABCDEF";
    int i;
    for (i=0; i<6; i++)
    {
        char ni = nipe[i];
        int p;
        for (p=0; p!=11; p++){
            struct carta Card;
            Card.letra = ni;
            Card.numero = p;
            inserir(baralho, Card);
        }
    }
    return baralho;
}


