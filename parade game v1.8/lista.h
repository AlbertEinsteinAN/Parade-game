typedef struct lista *Lista;
struct carta;

Lista *criar_lista();
int imprimir_lista(Lista *);
int inserir_comeco_lista(Lista *, struct carta );
int remover_do_comeco_lista(Lista *);
int remover_carta_lista(Lista *, struct carta );
int remover_por_indice_lista(Lista *, int );
int acessar_indice_lista(Lista *, int , struct carta *);
int quantidade_dos_valores_lista(Lista*);
int soma_dos_numeros_lista(Lista*);
int colocar_carta_da_mao_para_mesa_lista(Lista*, Lista *, int );
int vencer_com_2_zeros_na_mao_no_final_lista(Lista*);
