#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "jogo.h"
#include "time.h"

#define JOGANDO 0
#define CRIANDO_6_COLECOES 6
#define QUANTIDADE_COLECOES 6
#define NENHUMA_COLECAO 0
#define DANDO_CARTAS_NO_INICIO_DO_JOGO 5
#define NENHUMA_CARTA_NO_INICIO_DO_JOGO 0
#define NENHUMA_CARTA_NO_BARALHO 1
#define MAO_COM_5_CARTAS 5
#define MAO_COM_4_CARTAS 4
#define MAO_COM_3_CARTAS 3
#define MAO_COM_1_CARTA 1
#define VERDADEIRO 1
#define COMPUTADOR_JOGAR_CARTA_1 1
#define NENHUMA_CARTA 0
#define UMA_CARTA 1
#define CINCO_CARTA 5


int main()
{
    srand(time(NULL));
    Pilha * baralho;
    baralho = NULL;
    baralho = criar_baralho();
    embaralhar(baralho);

    int durante_jogo, jogar_na_mesa, jogar_na_colecao_primeira_carta, jogar_na_colecao_segunda_carta, i;

    Lista *mesa;
    mesa = NULL;
    mesa = criar_lista();

    Lista *mao_do_jogador;
    mao_do_jogador = NULL;
    mao_do_jogador = criar_lista();

    Lista *mao_do_computador;
    mao_do_computador = NULL;
    mao_do_computador = criar_lista();

    Lista **colecao_do_computador;
    colecao_do_computador = (Lista **)malloc(QUANTIDADE_COLECOES*sizeof(Lista *));
    for (i = NENHUMA_COLECAO ; i < QUANTIDADE_COLECOES ; i++) colecao_do_computador[i] = criar_lista();

    Lista **colecao_do_jogador;
    colecao_do_jogador = (Lista **)malloc(QUANTIDADE_COLECOES*sizeof(Lista *));
    for (i = NENHUMA_COLECAO ; i < QUANTIDADE_COLECOES ; i++) colecao_do_jogador[i] = criar_lista();

    for (i = NENHUMA_CARTA_NO_INICIO_DO_JOGO ; i < DANDO_CARTAS_NO_INICIO_DO_JOGO ; i++)
    {
        inserir_do_baralho_lista(baralho, mao_do_jogador);
        inserir_do_baralho_lista(baralho, mesa);
        inserir_do_baralho_lista(baralho, mao_do_computador);
    }
    informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);
    int turno = JOGANDO;
    while (turno == JOGANDO)
    {
        colocar_carta_da_mao_para_mesa_e_puxar_lista(mao_do_computador, mesa, baralho, COMPUTADOR_JOGAR_CARTA_1);
        colocar_carta_da_mesa_para_colecao_lista(mesa,colecao_do_computador);

        system("cls||clear");
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);

        printf("\nEscolha uma carta: (Digite um numero entre 1 a 5 da esquerda para direita e pressione enter)\n");

        if (tamanho(baralho) > NENHUMA_CARTA)
        {
            scanf("%d", &durante_jogo);
            while( getchar() != '\n' );
            while (durante_jogo < UMA_CARTA || durante_jogo > CINCO_CARTA)
            {
                printf("Esse caractere eh invalido.\ n");
                scanf("%d", &durante_jogo);
                while( getchar() != '\n' );
            }
            colocar_carta_da_mao_para_mesa_e_puxar_lista(mao_do_jogador, mesa, baralho, durante_jogo);
            colocar_carta_da_mesa_para_colecao_lista(mesa,colecao_do_jogador);
            if (perder_por_ter_todas_colecoes_cheias_no_final_lista(colecao_do_jogador) == VERDADEIRO)
            {
                system("cls||clear");
                informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);
                soma_dos_numeros_da_colecao_lista(colecao_do_jogador, colecao_do_computador);
                return 0;
            }
        }
        else
        {
            turno = NENHUMA_CARTA_NO_BARALHO;
        }
    }

    if (quantidade_dos_valores_lista(mao_do_jogador) == MAO_COM_5_CARTAS)
    {
        system("cls||clear");
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);

        printf("\nEscolha uma carta para a mesa: \n");
        scanf("%d", &jogar_na_mesa);
        while( getchar() != '\n' );
        while (jogar_na_mesa < MAO_COM_1_CARTA || jogar_na_mesa > MAO_COM_5_CARTAS)
        {
            printf("Por favor digite um numero de 1 a 5 e pressione enter.\ n");
            scanf("%d", &jogar_na_mesa);
            while( getchar() != '\n' );
        }
        colocar_carta_da_mao_para_mesa_lista(mao_do_jogador, mesa, jogar_na_mesa);
        colocar_carta_da_mesa_para_colecao_lista(mesa,colecao_do_jogador);
        if (perder_por_ter_todas_colecoes_cheias_no_final_lista(colecao_do_jogador) == VERDADEIRO)
        {
            informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);
            soma_dos_numeros_da_colecao_lista(colecao_do_jogador, colecao_do_computador);
            return 0;
        }
    }

    if (quantidade_dos_valores_lista(mao_do_computador) == MAO_COM_5_CARTAS)
    {
        colocar_carta_da_mao_para_mesa_lista(mao_do_computador, mesa, COMPUTADOR_JOGAR_CARTA_1);
        colocar_carta_da_mesa_para_colecao_lista(mesa,colecao_do_computador);
    }

    if (vencer_por_colecoes_vazias_no_final_lista(colecao_do_jogador) == VERDADEIRO)
    {
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);
        soma_dos_numeros_da_colecao_lista(colecao_do_jogador, colecao_do_computador);
        if (vencer_com_2_zeros_na_mao_no_final_lista(mao_do_jogador) == VERDADEIRO)
        {
            informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);
            soma_dos_numeros_da_colecao_lista(colecao_do_jogador, colecao_do_computador);
        }
        return 0;
    }

    if (quantidade_dos_valores_lista(mao_do_jogador) == MAO_COM_4_CARTAS)
    {

        colocar_carta_da_mesa_para_colecao_lista(mesa,colecao_do_jogador);

        system("cls||clear");
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);

        printf("\n\nEscolha uma carta da sua mao para a colecao: \n");
        scanf("%d", &jogar_na_colecao_primeira_carta);
        while( getchar() != '\n' );
        while (jogar_na_colecao_primeira_carta < MAO_COM_1_CARTA || jogar_na_colecao_primeira_carta > MAO_COM_4_CARTAS)
        {
            printf("Por favor digite um numero de 1 a 4 e pressione enter.\ n");
            scanf("%d", &jogar_na_colecao_primeira_carta);
            while( getchar() != '\n' );
        }
        colocar_da_mao_2_cartas_para_colecao_lista(mao_do_jogador, colecao_do_jogador, jogar_na_colecao_primeira_carta);

        system("cls||clear");
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);

        printf("\n\nEscolha outra carta para colecao: \n");
        scanf("%d", &jogar_na_colecao_segunda_carta);
        while( getchar() != '\n' );
        while (jogar_na_colecao_segunda_carta < MAO_COM_1_CARTA || jogar_na_colecao_segunda_carta > MAO_COM_3_CARTAS)
        {
            printf("Por favor digite um numero de 1 a 3 e pressione enter.\ n");
            scanf("%d", &jogar_na_colecao_segunda_carta);
            while( getchar() != '\n' );
        }
        colocar_da_mao_2_cartas_para_colecao_lista(mao_do_jogador, colecao_do_jogador, jogar_na_colecao_segunda_carta);

        system("cls||clear");
        informacoes(baralho, mao_do_jogador , mesa, colecao_do_jogador, colecao_do_computador);

        printf("\n Jogo terminou!\n");
        soma_dos_numeros_da_colecao_lista(colecao_do_jogador, colecao_do_computador);

        return 1;
    }
    return 0;
}
