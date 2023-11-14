#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int v, w, p;
} Aresta;

typedef struct {
    int *pai, *rank;
    int n;
} Infraestrutura;

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(Aresta *arestas, int p, int r) {
  int pivot = arestas[r].p;
  int i = (p - 1);

  for (int j = p; j < r; j++) {
    if (arestas[j].p <= pivot) {
      i++;
      troca(&arestas[i].p, &arestas[j].p);
      troca(&arestas[i].v, &arestas[j].v);
      troca(&arestas[i].w, &arestas[j].w);
    }
  }

  troca(&arestas[i + 1].p, &arestas[r].p);
  troca(&arestas[i + 1].v, &arestas[r].v);
  troca(&arestas[i + 1].w, &arestas[r].w);

  return (i + 1);
}

void quickSort(Aresta *arestas, int p, int r) {
  if (p < r) {
    int pi = particao(arestas, p, r);
    quickSort(arestas, p, pi - 1);
    quickSort(arestas, pi + 1, r);
  }
}

Infraestrutura *criarInfraestrutura(int n){
    Infraestrutura *infraestrutura = malloc(sizeof(Infraestrutura));
    infraestrutura->n = n;
    infraestrutura->pai = malloc(n * sizeof(int));
    infraestrutura->rank = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++){
        infraestrutura->pai[i] = i;
        infraestrutura->rank[i] = 0;
    }
    
    return infraestrutura;
}

int procurar(Infraestrutura *infraestrutura, int i){
    if(infraestrutura->pai[i] != i)
        infraestrutura->pai[i] = procurar(infraestrutura, infraestrutura->pai[i]);
    return infraestrutura->pai[i];
}

int unir(Infraestrutura *infraestrutura, int i, int j){
    int pi = procurar(infraestrutura, i);
    int pj = procurar(infraestrutura, j);

    if(infraestrutura->rank[pi] < infraestrutura->rank[pj])
        infraestrutura->pai[pi] = pj;
    else if(infraestrutura->rank[pi] > infraestrutura->rank[pj])
        infraestrutura->pai[pj] = pi;
    else{
        infraestrutura->pai[pi] = pj;
        infraestrutura->rank[pj]++;
    }
}

int encontrarCusto(Aresta *arestas, int roteadores, int cabos){
    int custo = 0;

    Infraestrutura *infraestrutura = criarInfraestrutura(roteadores);

    for(int i = 0; i < cabos; i++){
        int v = arestas[i].v;
        int w = arestas[i].w;

        if(procurar(infraestrutura, v) != procurar(infraestrutura, w)){
            custo += arestas[i].p;
            unir(infraestrutura, v, w);
        }
    }
    return custo;
}

int main(){
    int roteadores, cabos;
    scanf("%d %d", &roteadores, &cabos);

    Aresta *arestas = malloc(cabos * sizeof(Aresta));

    for (int i = 0; i < cabos; i++)
        scanf("%d %d %d", &arestas[i].v, &arestas[i].w, &arestas[i].p);

    quickSort(arestas, 0, cabos - 1);
    printf("%d\n", encontrarCusto(arestas, roteadores, cabos));

    return 0;
}
