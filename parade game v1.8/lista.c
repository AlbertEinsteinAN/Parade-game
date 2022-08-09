#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "jogo.h"

struct lista
{
    struct carta info;
    struct lista *prox;
};

Lista *criar_lista()
{
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if (li == NULL) return 0;

    *li = NULL;
    return li;
}

int imprimir_lista(Lista *li)
{
    if (li == NULL || *li == NULL) return 0;
    struct lista *aux = *li;
    while (aux)
    {

        printf("[%c | %d] ", aux->info.letra, aux->info.numero);
        aux = aux->prox;
    }
    return 1;
}

int inserir_comeco_lista(Lista *li, struct carta nova_carta)
{
    if (li == NULL) return 0;
    struct lista *no = (struct lista*)malloc(sizeof(struct lista));
    if (no == NULL) return 0;
    no->info = nova_carta;
    no->prox = *li;
    *li = no;
    return 1;
}

int remover_do_comeco_lista(Lista *li)
{
    if (li == NULL || *li == NULL) return 0;
    struct lista *aux = *li;
    *li = aux->prox;
    free(aux);
    return 1;
}

int remover_carta_lista(Lista *li, struct carta nova_carta)
{

    if (li == NULL || *li == NULL) return 0;
    struct lista *aux = *li, *ant, *no = (struct lista*)malloc(sizeof(struct lista));
    ant = NULL;
    if (no == NULL) return 0;
    no->info = nova_carta;
    while (aux != NULL && ((aux->info.numero != no->info.numero) || (aux->info.letra != no->info.letra)))
    {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL) return 0;
    if (aux == *li)
        *li = aux->prox;
    else
    {
        ant->prox = aux->prox;
        free(aux);
    }
    return 1;
}

int remover_por_indice_lista(Lista *li, int indice)
{
    if (li == NULL || *li == NULL || indice <= 0) return 0;
    struct lista *aux = *li, *ant = NULL;
    int i = 1;
    if (indice == 1)
    {
        (*li) = aux->prox;
        free(aux);
        return 1;
    }
    else
    {
        while (i != indice && aux != NULL)
        {
            ant = aux;
            aux = aux->prox;
            i++;
        }
    }
    if (aux == NULL) return 0;
    ant->prox = aux->prox;
    free(aux);
    return 0;
}

int acessar_indice_lista(Lista *li, int indice, struct carta *acesso_carta)
{
    if (li == NULL || *li == NULL || indice <= 0) return 0;
    struct lista *aux = *li;
    int cont = 1;
    while (aux != NULL && cont < indice)
    {
        aux = aux->prox;
        cont++;
    }
    if (aux == NULL) return 0;
    *acesso_carta = aux->info;
    return 1;
}

int quantidade_dos_valores_lista(Lista *li)
{
    if (li == NULL || *li == NULL) return 0;
    struct lista *aux = *li;
    int cont = 0;
    while (aux)
    {
        aux = aux->prox;
        cont++;
    }
    return cont;
}

int soma_dos_numeros_lista(Lista *li)
{
    if (li == NULL) return 0;
    struct lista *aux = *li;
    int cont = 0;
    while (aux)
    {
        cont += aux->info.numero;
        aux = aux->prox;
    }
    printf("%d", cont);
    return cont;
}

int colocar_carta_da_mao_para_mesa_lista(Lista *mao, Lista *mesa, int indice)
{
    if (mao == NULL || mesa == NULL || indice <= 0) return 0;
    if (*mao == NULL) return 0;
    struct lista *aux = *mao;
    int i = 1;
    while (i != indice)
    {
        aux = aux->prox;
        i++;
    }

    inserir_comeco_lista(mesa, aux->info);
    remover_por_indice_lista(mao, indice);
    return 1;
}

int vencer_com_2_zeros_na_mao_no_final_lista(Lista *mao)
{
    if (mao == NULL || *mao == NULL) return 0;
    struct lista *aux = *mao;
    int cont = 0;
    while (aux)
    {
        if (aux->info.numero == 0) cont++;
        aux = aux->prox;
    }
    if (cont >= 2)
    {
        system("cls||clear");
        printf("\n ________________\n|  Voce ganhou (flawless victory!  | *O*\n|________________|\n");
        printf("\n Jogo terminou! \n Pontuacao: \n");
        return 1;
    }
    else return 0;
}
