# Roteadores

Bruno é o responsável por configurar os roteadores de uma empresa. Os roteadores transmitem os dados entre si através dos cabos de internet, Os dados transmitidos podem trafegar por uma ou mais rotas para serem entregues ao destinatário.

O preço dos cabos de rede utilizados nos roteadores da empresa pode chegar a ser muito caro, e a empresa precisa cortar gastos. Pensando nisso a empresa decidiu fazer algumas alterações na infra-estrutura de redes.

Bruno deve modificar a infra-estrutura da rede da empresa de forma com que todos os roteadores consigam transmitir dados entre si e exista somente uma rota entre cada par de roteadores, economizando o máximo possível de cabos de internet.

A sua tarefa é descobrir qual será o custo total com cabos que a empresa terá após as modificações feitas por Bruno. A figura abaixo mostra (a) a infraestrutura de redes atual; e (b) a infraestrutura de redes após as modificação feitas.

## Entrada

A primeira linha é composta por dois inteiros R (3 ≤ R ≤ 60) e C (R ≤ C ≤ 200) representado respectivamente a quantidade de roteadores e a quantidade de cabos de internet utilizados atualmente.

Seguem C linhas, cada uma contendo três inteiros V (1 ≤ V ≤ R), W (1 ≤ W ≤ R) e P (1 ≤ P ≤ 10000), sendo V e W um par de roteadores que estão conectados por um cabo de internet e P o preço do cabo de internet utilizado.

## Saída

Seu programa deve imprimir um único valor inteiro que representa o custo total que a empresa gastará com cabos após as modificações.
