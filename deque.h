
typedef struct node_t{
    struct node_t *prev;    // Nodo anterior
    struct node_t *next;    // Proximo nodo
    char *word, *lemma;     // palavra e lema respectivamente
}node_t;

// Descritor:
typedef struct descriptor_t{ 
    node_t *first;  // Primeiro elemento
    node_t *last;   // Ultimo elemento
}descriptor_t;

// Inicializa um nodo do tipo node_t
node_t *initialize();
// Insere um nodo, do tipo node_t, no deque
void insert(node_t *first, char *word, char *lemma, descriptor_t **descriptor);
// Procura por uma palavra, word, no deque
node_t *query(descriptor_t *descriptor, char *word);
// Função que conta as comparações feitas na comparação
//      - Se flag, então imprime o numero de comparações
void counterCmp(int flag);
// Função que conta as comparações feitas na inserção
//      - Se flag, então imprime o numero de inserções
void counterIns(int flag);