#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tempo;
    int pizzas;
} Pedido;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int calcularTempoMaximoEntrega(int n, int capacidade, Pedido *pedidos) {
    int tempoMaximo[n + 1][capacidade + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacidade; w++) {
            if (i == 0 || w == 0) {
                tempoMaximo[i][w] = 0;
            } else if (pedidos[i - 1].pizzas <= w) {
                tempoMaximo[i][w] = max(pedidos[i - 1].tempo + tempoMaximo[i - 1][w - pedidos[i - 1].pizzas], tempoMaximo[i - 1][w]);
            } else {
                tempoMaximo[i][w] = tempoMaximo[i - 1][w];
            }
        }
    }

    return tempoMaximo[n][capacidade];
}

int main() {
    int pedidos, nmrMaxRoberto;

    while (1) {
        scanf("%d", &pedidos);
        if (pedidos == 0) break;

        scanf("%d", &nmrMaxRoberto);

        Pedido *pedidosRoberto = (Pedido *)malloc(pedidos * sizeof(Pedido));

        for (int i = 0; i < pedidos; i++)
            scanf("%d %d", &pedidosRoberto[i].tempo, &pedidosRoberto[i].pizzas);

        int resultado = calcularTempoMaximoEntrega(pedidos, nmrMaxRoberto, pedidosRoberto);
        printf("%d min.\n", resultado);

        free(pedidosRoberto);
    }

    return 0;
}
