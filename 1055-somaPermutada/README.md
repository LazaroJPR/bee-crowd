# Soma Pertubada

São disponibilizados a você n inteiros A1 A2 A3 ... An. Encontre uma permutação destes n inteiros de forma que a soma da diferença absoluta entre os elementos adjacentes seja maximizada.

Supondo n = 4 e que os inteiros fornecidos sejam 4 2 1 5. A permutação 2 5 1 4 permite a máxima soma. Para esta permutação, teríamos soma = abs(2-5) + abs(5-1) + abs(1-4) = 3+4+3 = 10.

De todas as 24 permutações possíveis, você não vai obter qualquer soma cujo valor exceda 10. Nós iremos chamar este valor 10, de soma permutada elegante.

## Entrada

A primeira linha de entrada é um valor inteiro T ( T < 100 ) que representa o número de caso de testes. Cada caso de teste consiste de uma linha que inicia com n ( 1 < n < 51 ) seguida por n inteiros não-negativos, separados por um único espaço. Nenhum dos elementos da permutação fornecida irá exceder 1000.

## Saída

Para cada caso, mostre o número do caso de teste seguido pela soma permutada elegante.
