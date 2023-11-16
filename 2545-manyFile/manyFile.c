#include <stdio.h>
#include <stdlib.h>

#define MAX_FILES 1000

typedef struct {
    int dependencias[MAX_FILES];
    int num_dependencias;
} Arquivo;

void enfileirarVerticesComGrauZero(int *grau, int *nivel, int qntdArquivos, int fila[], int *fim) {
    for (int i = 0; i < qntdArquivos; i++)
        if (grau[i] == 0) {
            nivel[i] = 1;
            fila[++(*fim)] = i;
        }
}

void bfs(Arquivo *arquivos, int *fila, int *grau, int nivel[], int qntdArquivos, int *inicio, int *fim, int *processado, int *resp) {
    while ((*inicio) <= (*fim)) {
        int v = fila[(*inicio)++];
        (*processado)++;
        (*resp) = (*resp) > nivel[v] ? (*resp) : nivel[v];

        for (int u = 0; u < arquivos[v].num_dependencias; u++) {
            int dependencia = arquivos[v].dependencias[u];
            if (dependencia >= 0) {
                grau[dependencia]--;
                if (grau[dependencia] == 0) {
                    fila[++(*fim)] = dependencia;
                    nivel[dependencia] = nivel[v] + 1;
                }
            }
        }
    }
}


int main() {
    int qntdArquivos, tempoTotal;

    while (scanf("%d", &qntdArquivos) != EOF) {
        int processado = 0, resp = 0;
        int grau[MAX_FILES], nivel[MAX_FILES];

        Arquivo *arquivos = malloc(qntdArquivos * sizeof(Arquivo));

        for (int i = 0; i < qntdArquivos; i++)
            grau[i] = nivel[i] = 0;

        for (int i = 0; i < qntdArquivos; i++) {
            scanf("%d", &arquivos[i].num_dependencias);

            for (int j = 0; j < arquivos[i].num_dependencias; j++) {
                int dependencia;
                scanf("%d", &dependencia);

                arquivos[i].dependencias[j] = dependencia - 1;
                grau[dependencia - 1]++;
            }
        }

        int fila[MAX_FILES];
        int inicio = 0, fim = -1;

        enfileirarVerticesComGrauZero(grau, nivel, qntdArquivos, fila, &fim);
        bfs(arquivos, fila, grau, nivel, qntdArquivos, &inicio, &fim, &processado, &resp);

        printf("%d\n", (processado == qntdArquivos) ? resp : -1);

    }

    return 0;
}
