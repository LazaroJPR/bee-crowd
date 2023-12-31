# ManyFile

No ano de 2569, Vasya recebe de sua mãe um grandioso presente de aniversário, o código fonte do seu vídeo-game favorito, Aranha Paciente. Vasya corre direto ao seu computador, com 4096 núcleos de processamento, insere o disquete, digita ls no diretório do código e nota que ele é composto de N arquivos fonte e um Manyfile.

Um Manyfile é como uma receita de bolo para compilar o código. Ao se executar o comando many, o Manyfile é lido e os arquivos começam a ser compilados, de forma que o máximo de núcleos de processamento são utilizados simultaneamente. Se o mundo fosse perfeito, este processo seria muito rápido, uma vez que cada arquivo fonte do jogo demora exatamente um minuto para ser compilado, mas infelizmente a compilação de alguns arquivos depende da conclusão de outros, impossibilitando que todos os arquivos sejam processados simultaneamente.

Considerando a compilação da Aranha Paciente como terminada quando todos os seus N arquivos tiverem sido compilados e sabendo quais arquivos dependem de qual, escreva um programa que calcule para Vasya quantos minutos demorará para que a Aranha Paciente seja compilada.

## Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso contém o inteiro N (1 ≤ N ≤ 1000), o número de arquivos fonte da Aranha Paciente. Os arquivos são numerados de 1 a N. As N linhas seguintes descrevem os arquivos. A i-ésima linha contém um inteiro Mi (0 ≤ Mi < N) seguido de Mi inteiros com valor entre 1 e N e diferentes de i, representando o índice dos arquivos dos quais o arquivo i depende.

A entrada termina com fim-de-arquivo (EOF).

## Saída

Para cada caso de teste, imprima uma única linha contendo o tempo total em minutos que demorará para que a Aranha Paciente seja compilada. Caso seja impossível terminal a compilação, imprima -1.
