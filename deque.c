#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deque.h"      // DEQUE_TAD

// Inicia deque
node_t *initialize(){
    return NULL;
}

// Insere node_t
void insert(node_t *first, char *word, char *lemma, descriptor_t **descriptor){
    node_t *newNode = (node_t *) malloc(sizeof(node_t)); // Aloca nodo
    int wordSize = strlen(word);    // tamanho da word
    int lemmaSize = strlen(lemma);  // Tamanho do lemma

    // Aloca word
    newNode->word = (char *) malloc(wordSize + 1); strncpy(newNode->word, word, wordSize + 1);
    // Aloca Lemma
    newNode->lemma = (char *) malloc(lemmaSize + 1); strncpy(newNode->lemma, lemma, lemmaSize + 1);
    // Deque vazio
    counterIns(0); // Comparação com elemento da estrutura (if)
    if(!first){
        first = newNode;
        first->next = first->prev = first;
        (*descriptor)->first = (*descriptor)->last = first;
    }else{
        node_t *aux = (*descriptor)->first;
        // Procura posicao correta (Ordem lexicografica)
        while(aux->next != (*descriptor)->first && strcmp(newNode->word, aux->word) > 0){
            counterIns(0); counterIns(0); // Duas comparações com elementos da estrutura (while)
            aux = aux->next;
        }

        int strCmp = strcmp(newNode->word, aux->word);  // Resultado da comparação
        // Não insere
        if (strCmp == 0){
            free(newNode);
            return;
        }
        // Insere no inicio
        else if (aux->prev == (*descriptor)->last && strCmp < 0){
            counterIns(0); // Comparação com elemento da estrutura (if)
            newNode->next = aux;
            newNode->prev = (*descriptor)->last;
            aux->prev = newNode;
            (*descriptor)->last->next = newNode;
            (*descriptor)->first = newNode;
        }
        // Insere no fim
        else if (aux->next == (*descriptor)->first && strCmp > 0){
            counterIns(0); counterIns(0); // Comparação com elemento da estrutura (if e else if)
            aux->next = newNode;
            newNode->next = (*descriptor)->first;
            newNode->prev = aux;
            (*descriptor)->first->prev = newNode;
            (*descriptor)->last = newNode;
        }
        // Insere no Meio
        else{
            counterIns(0); counterIns(0); // Comparação com elemento da estrutura (if e else if)
            newNode->next = aux;
            newNode->prev = aux->prev;
            aux->prev = newNode;
            newNode->prev->next = newNode;
        }
    }
}

// Procura word
node_t *query(descriptor_t *descriptor, char *word){
    counterCmp(0); // Comparação com elemento da estrutura (if)
    if (!descriptor)
        return NULL;

    node_t *firstAux = descriptor->first, *lastAux = descriptor->last;
    
    while (1){
        counterCmp(0); // Comparação com elemento da estrutura (if)
        if (!strcmp(firstAux->word, word))
            return firstAux;
        counterCmp(0); // Comparação com elemento da estrutura (if)
        if (!strcmp(lastAux->word, word))
            return lastAux;
        counterCmp(0); // Comparação com elemento da estrutura (if)
        if (firstAux == lastAux)
            return NULL;
        counterCmp(0); // Comparação com elemento da estrutura (if)
        if (firstAux == lastAux->prev)
            return NULL;
        lastAux = lastAux->prev;
        firstAux = firstAux->next;
    }
}

// Conta cmp's
void counterCmp(int flag){
    static unsigned long long countCmp = 0;

    countCmp++;
    if(flag)
        printf("Numero de comparacoes na criacao do arquivo: %llu\n", --countCmp);
}

// Conta ins's
void counterIns(int flag){
    static unsigned long long countIns = 0;

    countIns++;
    if(flag)
        printf("Numero de comparacoes na insercao: %llu\n", --countIns);
}