#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo {
   void * data;
   int priority;
} heapElem;

typedef struct Heap {
  heapElem * heapArray;
  int size;
  int capac;
} Heap;


void * heap_top(Heap * pq){
  if(!pq || pq->size == 0) return NULL;
  return pq->heapArray[0].data;
}



void heap_push(Heap * pq, void * data, int priority) {
  heapElem aux;
  int hijo = pq->size;
  int padre = (hijo - 1) / 2;
  
  if(pq->size == pq->capac) {
    pq->heapArray = realloc(pq->heapArray, (pq->capac * 2) + 1);
    pq->capac = (pq->capac * 2) + 1;
  }

  pq->heapArray[hijo].data = data;
  pq->heapArray[hijo].priority = priority;
  pq->size = hijo + 1;

  while(priority > pq->heapArray[padre].priority) {
    aux.priority = pq->heapArray[hijo].priority;
    aux.data = pq->heapArray[hijo].data;
      
    pq->heapArray[hijo].priority = pq->heapArray[padre].priority;
    pq->heapArray[hijo].data = pq->heapArray[padre].data;
      
    pq->heapArray[padre].priority = aux.priority;
    pq->heapArray[padre].data = aux.data;
  }

    if(priority > pq->heapArray[0].priority) {
        aux.priority = pq->heapArray[hijo].priority;
    aux.data = pq->heapArray[hijo].data;
      
    pq->heapArray[hijo].priority = pq->heapArray[0].priority;
    pq->heapArray[hijo].data = pq->heapArray[0].data;
      
    pq->heapArray[0].priority = aux.priority;
    pq->heapArray[0].data = aux.data;

    }
}


void heap_pop(Heap * pq) {

}

Heap * createHeap() {
  Heap * new = (Heap *) malloc(sizeof(Heap));
  new->heapArray = (heapElem * ) malloc(sizeof(heapElem) * 3);
  new->size = 0;
  new->capac = 3;

  return new;
}
