#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int salaU, salaV, comprimento;
} Corredor;

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(Corredor *arestas, int p, int r) {
  int pivot = arestas[r].comprimento;
  int i = (p - 1);

  for (int j = p; j < r; j++) {
    if (arestas[j].comprimento <= pivot) {
      i++;
      troca(&arestas[i].salaU, &arestas[j].salaU);
      troca(&arestas[i].salaV, &arestas[j].salaV);
      troca(&arestas[i].comprimento, &arestas[j].comprimento);
    }
  }

  troca(&arestas[i + 1].salaU, &arestas[r].salaU);
  troca(&arestas[i + 1].salaV, &arestas[r].salaV);
  troca(&arestas[i + 1].comprimento, &arestas[r].comprimento);

  return (i + 1);
}

void quickSort(Corredor *arestas, int p, int r) {
  if (p < r) {
    int pi = particao(arestas, p, r);
    quickSort(arestas, p, pi - 1);
    quickSort(arestas, pi + 1, r);
  }
}

int procurar(int *conjunto, int i) {
    if (conjunto[i] == -1)
        return i;
    return procurar(conjunto, conjunto[i]);
}

void unir(int *conjunto, int x, int y) {
    int raizX = procurar(conjunto, x);
    int raizY = procurar(conjunto, y);
    conjunto[raizX] = raizY;
}

int kruskal(Corredor *corredores, int qntdCorredores, int qntdSalas) {
    int *conjunto = malloc(qntdSalas * sizeof(int));

    for (int i = 0; i < qntdSalas; i++) conjunto[i] = -1;

    int distancia = 0;

    for (int i = 0; i < qntdCorredores; i++) {
        int raizU = procurar(conjunto, corredores[i].salaU - 1);
        int raizV = procurar(conjunto, corredores[i].salaV - 1);

        if (raizU != raizV) {
            distancia += corredores[i].comprimento;
            unir(conjunto, raizU, raizV);
        }
    }
    return distancia;
}

int main(){
    int qntdSalas, qntdCorredores, salaInicial;

    scanf("%d %d", &qntdSalas, &qntdCorredores);
    scanf("%d", &salaInicial);

    Corredor *corredores = malloc(qntdCorredores * sizeof(Corredor));

    for(int i = 0; i < qntdCorredores; i++)
        scanf("%d %d %d", &corredores[i].salaU, &corredores[i].salaV, &corredores[i].comprimento);

    quickSort(corredores, 0, qntdCorredores - 1);
    int resultado = kruskal(corredores, qntdCorredores, qntdSalas);
    printf("%d\n", resultado*2);

    return 0;
}
