#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int particao(int vetor[], int p, int r) {
  int pivot = vetor[r];
  int i = (p - 1);

  for (int j = p; j < r; j++) {
    if (vetor[j] <= pivot) {
      i++;
      troca(&vetor[i], &vetor[j]);
    }
  }

  troca(&vetor[i + 1], &vetor[r]);

  return (i + 1);
}

void quickSort(int vetor[], int p, int r) {
  if (p < r) {
    int pi = particao(vetor, p, r);
    quickSort(vetor, p, pi - 1);
    quickSort(vetor, pi + 1, r);
  }
}

int calculaMaiorValor(int vet[], int maior, int menor) {
    int somaEsq = 0, somaDir = 0;

    somaEsq += abs(vet[maior] - vet[menor-1]);
    somaDir += abs(vet[maior] - vet[menor+1]);

    return (somaEsq < somaDir) ? somaDir : somaEsq;
}

int calculaMenorValor(int vet[], int maior, int menor) {
    int somaEsq = 0, somaDir = 0;

    somaEsq += abs(vet[menor] - vet[maior]);
    somaDir += abs(vet[menor] - vet[maior+1]);

    return (somaEsq < somaDir) ? somaDir : somaEsq;
}

void somaPertubada(int vet[], int maior, int caso) {
    int menor = 0, soma = 0, somaEsq, somaDir;

    soma += abs(vet[menor] - vet[maior]);
    maior--;

    for(menor = 1; menor < maior; menor++, maior--) {
        if(menor+1 == maior){
          soma += abs(vet[maior] - vet[menor-1]);
          soma += abs(vet[menor] - vet[maior+1]);
          break;
        }

        soma += calculaMaiorValor(vet, maior, menor);
        soma += calculaMenorValor(vet, maior, menor);
    }

    if(menor == maior)
        soma += calculaMaiorValor(vet, maior, menor);

    printf("Case %d: %d\n", caso+1, soma);
}

int main() {
    int t, n, i, j;
    int vet[51];

    scanf("%d", &t);

    for(i = 0; i < t; i++) {
        scanf("%d", &n);
        for(j = 0; j < n; j++)
            scanf("%d", &vet[j]);
        quickSort(vet, 0, n-1);
        somaPertubada(vet, n-1, i);
    }
}
