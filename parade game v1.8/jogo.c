#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "jogo.h"


int soma_dos_numeros_da_colecao_lista(Lista **colecao_do_jogador, Lista **colecao_do_computador)
{
    if (colecao_do_jogador == NULL || **colecao_do_jogador == NULL){
        printf("\nPONTUACAO\nTotal: %d", 0);
            return 0;
    }
    if (colecao_do_computador == NULL || **colecao_do_computador == NULL) return 0;
    int i = 0, cont = 0;

    while (i < 6)
    {
        printf("\n %c -> ", i + 65);

        if (quantidade_dos_valores_lista(colecao_do_jogador[i]) > quantidade_dos_valores_lista(colecao_do_computador[i]))
        {
            cont += quantidade_dos_valores_lista(colecao_do_jogador[i]);
            printf("%d", quantidade_dos_valores_lista(colecao_do_jogador[i]));
        }
        else
        {
            cont += soma_dos_numeros_lista(colecao_do_jogador[i]);
        }
        i++;
    }
    printf("\nPONTUACAO\nTotal: %d", cont);
    return 1;
}

int imprimir_colecao_lista(Lista **colecao)
{
   if (colecao == NULL) return 0;
    int i = 0;
    while (i < 6)
    {
        printf("%c -> ", i + 65);
            if(*colecao[i] == NULL) printf("[     ]");
            imprimir_lista(colecao[i]);
            printf("\n");
            i++;
    }
    return 1;
}

int colocar_da_mao_2_cartas_para_colecao_lista(Lista *mao, Lista **colecao, int indice)
{
    if (mao == NULL || *mao == NULL|| indice <= 0 || indice > 4) return 0;
    struct carta carta;
    acessar_indice_lista(mao, indice, &carta);
    inserir_comeco_lista(colecao[carta.letra-'A'], carta);
    remover_por_indice_lista(mao, indice);
    return 1;
}

int colocar_carta_da_mesa_para_colecao_lista(Lista *mesa, Lista **colecao)
{
    if (mesa == NULL) return 0;
    int i;
    struct carta c;
    struct carta aux;
    int cont = 1;

    acessar_indice_lista(mesa, 1, &c);
    for (i = 2 ; i <= quantidade_dos_valores_lista(mesa) ; i++)
    {
        acessar_indice_lista(mesa, i, &aux);
        if (c.numero >= cont) {
            cont++;
        }else if ((c.letra == aux.letra) || (c.numero >= aux.numero))
        {
            inserir_comeco_lista(colecao[aux.letra - 'A'], aux);
            remover_carta_lista(mesa, aux);
            i--;
        }
    }
    return 1;
}

int perder_por_ter_todas_colecoes_cheias_no_final_lista(Lista **colecao)
{
    if (colecao == NULL || **colecao == NULL) return 0;
    struct lista *aux;
    int cont = 0, i = 0;
    while (i < 6)
    {
        aux = *colecao[i];
        if (aux != NULL) cont++;
        else return 0;
        i++;
    }
    system("cls||clear");
    printf("\n ________________\n|  Voce perdeu!  | *_*\n|________________|\n");
    printf("\n Jogo terminou!\n");
    system("pause");
    return 1;
}

int vencer_por_colecoes_vazias_no_final_lista(Lista **colecao)
{
    if (colecao == NULL) return 0;
    struct lista *aux;
    int i = 0;
    while (i < 6)
    {
        aux = *colecao[i];
        if (aux != NULL) return 0;
        else
        {
            i++;
        }
    }
    system("cls||clear");
    printf("\n ________________\n|  Voce ganhou!  | *O*\n|________________|\n");
    printf("\n Jogo terminou!\n");
    return 1;
}

int inserir_do_baralho_lista(Pilha *baralho, Lista *mao)
{
    if (baralho == NULL || mao == NULL) return 0;
    struct carta c;
    remover(baralho,&c);
    inserir_comeco_lista(mao,c);
    return 1;
}

int colocar_carta_da_mao_para_mesa_e_puxar_lista(Lista *mao, Lista *mesa, Pilha *baralho, int indice)
{
    if (mao == NULL || *mao == NULL || mesa == NULL || indice <= 0 || indice > 5) return 0;
    struct carta c;
    acessar_indice_lista(mao, indice, &c);
    inserir_comeco_lista(mesa, c);
    remover_por_indice_lista(mao, indice);
    inserir_do_baralho_lista(baralho,mao);
    return 1;
}

void informacoes(Pilha *baralho, Lista *mao_do_jogador , Lista * mesa, Lista **colecao_do_jogador, Lista **colecao_do_computador)
{
    printf("\n%d carta(s)", tamanho(baralho));
    printf("\nMao do jogador: \n");
    imprimir_lista(mao_do_jogador);
    printf("\nMesa: \n");
    imprimir_lista(mesa);
    printf("\nColecao do jogador: \n");
    imprimir_colecao_lista(colecao_do_jogador);
    printf("\nColecao do computador: \n");
    imprimir_colecao_lista(colecao_do_computador);
}
