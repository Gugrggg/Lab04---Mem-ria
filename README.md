# Lab04---Memoria

1. Considerando a estrutura de dados celula, crie três instâncias do objeto célula (três valores na lista);
  
void insere_novos_elementos(celula **lista, int valor){
    celula *nova_celula = (celula *) malloc(sizeof(celula));
    nova_celula -> conteudo = valor;
    nova_celula -> prox = *lista;
    *lista = nova_celula;
}

   
2. Construa uma função que imprima todos os valores da lista;

void imprime_lista(celula *lista){
    if (lista != NULL){
        printf("%d \n", lista -> conteudo);
        imprime_lista(lista -> prox);
    }
}

   
3. Calcule a quantidade de memória gasta por cada instância da célula

int memoria_total(celula *cel){
    int memoria = sizeof(*cel);
    return memoria;
}
   
4. Construa uma função que remove os elementos da lista;


void remove_elemento(celula **lista, int elem){
    celula *depois = *lista;
    celula *antes = NULL;

    while (depois != NULL && depois -> conteudo != elem) {
        antes = depois;
        depois = depois -> prox;
    }

    if (depois != NULL) {
        if (antes == NULL) {
            *lista = depois -> prox;
        } else {
            antes -> prox = depois -> prox;
        }
        free(depois);
    }
}

5. Incremente sua função liberando a memória quando um elemento é liberado;

    memoriaGb = memoria * 1024 * 1024 * 1024;

6. Calcule o máximo de elementos possíveis na fila, considerando a memória disponível no computador.

    printf("\nIndique a quantidade de Memória disponivel(GB): "); 
    scanf("%lf", &memoria);
