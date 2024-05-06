// Gustavo Galhardo Rodrigues – 10403091
// Pedro Nogueira Ribeiro – 10324924

#include <stdio.h>
#include <stdlib.h>

//Nó inicial
struct reg {
    int conteudo;
    struct reg *prox;
};

//Declaração da célula
typedef struct reg celula;

//Questão 2: imprime a lista
void imprime_lista(celula *lista){
    if (lista != NULL){
        printf("%d \n", lista -> conteudo);
        imprime_lista(lista -> prox);
    }
}

//Questão 3: quantidade de memória ocupada
int memoria_total(celula *cel){
    int memoria = sizeof(*cel);
    return memoria;
}

//Questão 1: inserção de novos elementos na lista
void insere_novos_elementos(celula **lista, int valor){
    celula *nova_celula = (celula *) malloc(sizeof(celula));
    nova_celula -> conteudo = valor;
    nova_celula -> prox = *lista;
    *lista = nova_celula;
}

//Questão 4: remoção de elemento da lista
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


int main() {
    //Criando a lista
    celula *lista = NULL;
  
    //Questão 1: Adicionando três elementos na lista
    insere_novos_elementos(&lista, 0);
    insere_novos_elementos(&lista, 1);
    insere_novos_elementos(&lista, 2);

    //Questão 2: imprimindo a lista
    imprime_lista(lista);
  
    //Questão 3: Quantidade de memoria ocupada pela lista.
    printf("Memoria utilizada: %d bytes\n", memoria_total(lista));
  
    //Questão 4: removendo o elemento 1 da lista, ulizando a função
    remove_elemento(&lista, 1);
    imprime_lista(lista);
  
    //Quantidade máxima de elementos possíveis na lista
    double memoria, memoriaGb, maximo;
  
    //Input da memória total
    printf("\nIndique a quantidade de Memória disponivel(GB): "); 
    scanf("%lf", &memoria);
  
    //Transforma de gb para bytes
    memoriaGb = memoria * 1024 * 1024 * 1024;
  
    //Divide de a memoria do pc pela memória ocupada pela lista.
    printf("\nQuantidade máxima de elementos = %.2lf ", memoriaGb / memoria_total(lista));
}
