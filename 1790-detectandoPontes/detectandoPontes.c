#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y, visitado;
} Ponte;

void dfs(Ponte* pontes, int vertice, int qntdPontes, int *pontos, int arestaEliminada) {
    pontos[vertice] = 1;

    for (int i = 0; i < qntdPontes; i++) {
        if (arestaEliminada == i) continue;

        if ((pontes[i].x - 1 == vertice || pontes[i].y - 1 == vertice) && pontes[i].visitado == 0) {
            pontes[i].visitado = 1;
            dfs(pontes, (pontes[i].x - 1 == vertice) ? pontes[i].y - 1 : pontes[i].x - 1, qntdPontes, pontos, arestaEliminada);
        }
    }
}

int contarComponentesConexas(Ponte* pontes, int qntdPontes, int cidades, int arestaEliminada) {
    int *pontos = (int*)calloc(cidades, sizeof(int));
    int componentesConexas = 0;

    for (int i = 0; i < cidades; i++) {
        if (!pontos[i]) {
            componentesConexas++;
            dfs(pontes, i, qntdPontes, pontos, arestaEliminada);
        }
    }
    return componentesConexas;
}

void limparVisita(Ponte *pontes, int qntdPontes){
    for (int i = 0; i < qntdPontes; i++)
        pontes[i].visitado = 0;
}

int main(){
    int cidades, qntdPontes;
    
    while(scanf("%d %d", &cidades, &qntdPontes) != EOF) {
        Ponte *pontes = malloc(qntdPontes * sizeof(Ponte));

        for (int i = 0; i < qntdPontes; i++) {
            scanf("%d %d", &pontes[i].x, &pontes[i].y);
            pontes[i].visitado = 0;
        }

        int componentesConexas = 0;
        int auxCompConx = 0;
        int count = 0;

        componentesConexas = contarComponentesConexas(pontes, qntdPontes, cidades, -1);

        for(int i = 0; i < qntdPontes; i++){
            limparVisita(pontes, qntdPontes);
            auxCompConx = contarComponentesConexas(pontes, qntdPontes, cidades, i);
            if(auxCompConx != componentesConexas) count++;
        }

        printf("%d\n", count);
    }
    return 0;
}
