#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y, visitado;
} Estrada;

void dfs(Estrada* estradas, int vertice, int estradasConstruidas, int *pontos) {
    
    pontos[vertice] = 1;
    
    for (int i = 0; i < estradasConstruidas; i++) {
        if (estradas[i].visitado == 0){
            if(estradas[i].x-1 == vertice){
                estradas[i].visitado = 1;
                dfs(estradas, estradas[i].y-1, estradasConstruidas, pontos);
            }
            else if(estradas[i].y-1 == vertice){
                estradas[i].visitado = 1;
                dfs(estradas, estradas[i].x-1, estradasConstruidas, pontos);
            }
        }
    }
}

int detectarSubgrafosDesconectados(Estrada* estradas, int pontosPrincipais, int estradasConstruidas, int *pontos) {
    int numSubgrafos = 0;

    for (int i = 0; i < pontosPrincipais; i++) {
        if (pontos[i] == 0) {
            dfs(estradas, i, estradasConstruidas, pontos);
            numSubgrafos++; 
        }
    }

    return numSubgrafos;
}

int main(){
    int casosDeTeste, pontosPrincipais, estradasConstruidas;
    scanf("%d", &casosDeTeste);

    for(int i = 0; i < casosDeTeste; i++){
        scanf("%d", &pontosPrincipais);
        scanf("%d", &estradasConstruidas);

        if (estradasConstruidas == 0) {
            if(pontosPrincipais == 1) printf("Caso #%d: a promessa foi cumprida\n", i + 1);
            else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i + 1, pontosPrincipais - 1);
        } 
        else {
            int *pontos = (int*)calloc(pontosPrincipais, sizeof(int));
            Estrada *estradas = malloc(estradasConstruidas * sizeof(Estrada));

            for (int j = 0; j < estradasConstruidas; j++) {
                scanf("%d %d", &estradas[j].x, &estradas[j].y);
                estradas[j].visitado = 0;
            }

            int resultado = detectarSubgrafosDesconectados(estradas, pontosPrincipais, estradasConstruidas, pontos);

            if(resultado == 1) printf("Caso #%d: a promessa foi cumprida\n", i + 1);
            else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", i + 1, resultado - 1);  
        }
    }
}
