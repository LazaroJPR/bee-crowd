#include <stdio.h>

#define MAX 100001

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}

int resto(long long x) {
    return ((x % 3) + 3) % 3;
}

long long maximizarPontos(int n, long long cartas[], long long dp[][3]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = 0;
        }
    }

    for (int fim = 1; fim <= n; fim++) {
        for (int ini = n; ini >= 1; ini--) {
            if (fim < ini)
                dp[ini][resto(fim)] = 0;

            if (fim > ini) {
                dp[ini][resto(fim)] = cartas[ini] + min(dp[ini + 2][resto(fim)], dp[ini + 1][resto(fim - 1)]);

                dp[ini][resto(fim)] = max(dp[ini][resto(fim)], cartas[fim] + min(dp[ini + 1][resto(fim - 1)], dp[ini][resto(fim - 2)]));
            }
        }
    }
    return dp[1][resto(n)];
}

int main() {
    int nmrCartoes;
    long long cartas[MAX], dp[MAX][3];

    while (scanf("%d", &nmrCartoes) != EOF) {
        for (int i = 1; i <= nmrCartoes; i++) {
            scanf("%lld", &cartas[i]);
        }

        printf("%lld\n", maximizarPontos(nmrCartoes, cartas, dp));
    }

    return 0;
}
