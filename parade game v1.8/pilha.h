typedef struct pilha * Pilha;
struct carta;

// Funções básicas
Pilha * criar ();
int inserir(Pilha *, struct carta);
int remover(Pilha *, struct carta *);
int embaralhar(Pilha *);
int mexer(Pilha *);
int tamanho(Pilha *);
int imprimir(Pilha*);

// MESA
Pilha * criar_baralho ();
