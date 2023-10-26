#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct camera {
    double pInicial, pFinal;
};

void troca(double *a, double *b) {
  double t = *a;
  *a = *b;
  *b = t;
}

int particao(struct camera *cameras, int p, int r) {    
    double pivot = cameras[r].pInicial;
    int i = (p - 1);

    for (int j = p; j < r; j++) {
        if (cameras[j].pInicial <= pivot) {
            i++;
            troca(&cameras[i].pInicial, &cameras[j].pInicial);
            troca(&cameras[i].pFinal, &cameras[j].pFinal);
        }
    }
    troca(&cameras[i + 1].pInicial, &cameras[r].pInicial);
    troca(&cameras[i + 1].pFinal, &cameras[r].pFinal);

    return (i + 1);
}

void quickSort(struct camera *cameras, int p, int r) {
    if (p < r) {
        int pi = particao(cameras, p, r);
        quickSort(cameras, p, pi - 1);
        quickSort(cameras, pi + 1, r);
    }
}

int calculaCameras(int n, int l, struct camera *cameras){
    int i,qntdMinCameras = 0;
    double min = 0, max = 0;

    for (i = 0; i < n; i++) {
        if (cameras[i].pInicial > min) return 0;

        int j = i;

        while (j < n && cameras[j].pInicial <= min) {
            if (cameras[j].pFinal > max) max = cameras[j].pFinal;
            j++;
        }

        qntdMinCameras++;
        min = max;
        if (min >= l) break;
    }

    return (min < 1) ? 0 : qntdMinCameras;
}

int main() {
    int i, n, l, a, x, r;

    while(scanf("%d %d %d", &n, &l, &a) && n != 0) {
        struct camera *cameras = (struct camera *)malloc(n * sizeof(*cameras));

        if(cameras == NULL) return 0;

        for(i = 0; i < n; i++){
            scanf("%d %d", &x, &r);
            double aux = sqrt((r*r) - ((a/2.0) * (a/2.0)));
            cameras[i].pInicial = x - aux;
            cameras[i].pFinal = x + aux;
        }

        quickSort(cameras, 0, n - 1);
        int resultado = calculaCameras(n, l, cameras);
        printf(resultado <= 0 ? "Tera que comprar mais cameras.\n" : "%d\n", resultado);
        free(cameras);
    }
    return 0;
}