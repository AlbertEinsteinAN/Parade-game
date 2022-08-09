struct carta {
    char letra;
    int numero;
};

typedef struct lista *Lista;
typedef struct pilha *Pilha;
struct carta;

int soma_dos_numeros_da_colecao_lista(Lista **, Lista **);
int imprimir_colecao_lista(Lista **);
int colocar_da_mao_2_cartas_para_colecao_lista(Lista *, Lista **, int );
int colocar_carta_da_mesa_para_colecao_lista(Lista *, Lista **);
int perder_por_ter_todas_colecoes_cheias_no_final_lista(Lista **);
int vencer_por_colecoes_vazias_no_final_lista(Lista **);
int inserir_do_baralho_lista(Pilha *, Lista *);
int colocar_carta_da_mao_para_mesa_e_puxar_lista(Lista *, Lista *, Pilha *, int );
void informacoes(Pilha * , Lista * , Lista *, Lista **, Lista **);
