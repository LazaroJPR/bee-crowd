# Câmeras

O coordenador do curso de ciência da computação pretende instalar novas câmeras em um corredor da faculdade, no intuito de poder identificar os alunos que costumam ficar ali em horário de aula, assim quando esses alunos forem reclamar que o curso está difícil ele poderá facilmente mostrar para o aluno que está difícil pois o mesmo não tem frequentado muito as aulas.

As câmeras que serão instaladas são de uma tecnologia um pouco diferente, elas tem visão de 360 graus sem a necessidade de fazer o giro, o coordenador irá instalar as câmeras no teto do corredor e todas estarão exatamente centrada entre as paredes do corredor. Como essas câmeras são caras e consomem muita energia, o coordenador terá que usar as câmeras já existentes no corredor, que por motivo de economia estavam desligadas, porém nem todas são do mesmo modelo, assim cada uma tem um alcance de visão diferente.

Sabendo que você é o melhor programador do curso, o coordenador pediu para que você determinasse a quantidade mínima de câmeras necessárias para cobrir todo o corredor, sem deixar nenhum espaço sem visão, ou dizer se terá que comprar mais câmeras.

Assuma o corredor como um plano cartesiano, onde o tamanho das abscissas é L com início em 0, e o tamanho das ordenadas é A. As câmeras estão sempre posicionadas sobre o eixo das abscissas.

## Entrada

A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém três inteiro N, L, A (1 ≤ N ≤ 10000), indicando respectivamente o número de câmeras presentes na faculdade, largura do corredor e a distância entre as duas paredes do corredor. Segue N linhas contendo dois inteiros X e R (R ≥ A), indicando a posição onde a câmera está instalada e o seu alcance de visão. A entrada termina com N = 0 e não deve ser processada

## Saída

Para cada caso de teste você deverá imprimir a quantidade mínima de câmeras necessárias para cobrir todo o corredor. Caso não seja possível você deverá imprimir "Tera que comprar mais cameras.".
