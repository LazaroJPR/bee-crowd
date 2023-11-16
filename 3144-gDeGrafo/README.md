# G de Grafo

Esse problema originalmente foi escrito para o primeiro contest aberto que eu criei aqui no URI no ano passado, mas por um erro com os arquivos de casos de teste ele não pode ser incluído na prova a tempo. Então nada mais justo que agora ele fazer parte do aquecimento para a minha segunda prova. Segue abaixo o texto original do problema! :)

Na semana passada estava o Tobias, Gabriel e Eu escolhendo as questões para compor a prova, e então o Gabriel declarou "G de Grafo hein!" e eu não vou negar que a ideia foi ótima. Depois disso tive a brilhante ideia de fazer todas as questões da prova autorais, e me arrependi um pouco. Se resolver as questões já é difícil, gerar casos de teste e criar códigos de validação consegue ser ainda pior.

Confesso que eu tentei, mas nenhuma ideia me pareceu boa para misturar grafos com a greve, mas como é praxe as questões na maratona terem um longo texto que não diz nada com nada para introduzir o problema, vamos imaginar uma história qualquer.

Digamos que... No Campus da UFSC aqui em Araranguá tem salas. E entre as salas tem corredores. Esses corredores formam caminhos que conectam as salas com um determinado comprimento, e pode existir mais de um caminho que saia de uma sala até outra. Até aí nenhuma surpresa, estou chamando a UFSC Campus Araranguá de grafo, as salas de vértice e os corredores de arestas. Se o leitor foi atento também notou que o grafo pode possuir ciclos e as arestas são ponderadas. Até aí nenhuma surpresa.

Digamos ainda que... Bem, sei lá. Por algum motivo aleatório ou alguma força conspiratória do universo alguém. Pode ser o Tobias, ou o Gabriel, ou os dois. Isso... Os dois querem passar por todas as salas do Campus, começando e terminando o percurso na mesma sala, sem criar nenhum ciclo no trajeto e percorrendo a menor distância possível durante todo o caminho. É possível passar por uma mesma sala ou corredor mais de uma vez se necessário. O porquê deles querem fazer isso é um mistério até para mim, estou sem criatividade para imaginar uma boa desculpa.

Então, dadas as informações do grafo, você consegue me dizer qual o caminho mínimo que eles precisam percorrer de acordo com as restrições descritas anteriormente? Espero que sim, do contrário seu time não ganha balão nessa questão. ;)

## Entrada

A primeira linha da entrada contém dois números inteiros N (2 ≤ N ≤ 500) e M (1 ≤ M ≤ 124750) que representam o número de salas e o número de corredores do campus UFSC Campus Araranguá respectivamente. Na segunda linha a um inteiro O (1 ≤ O ≤ N) que indica a sala que eles irão começar e terminar o trajeto. Cada uma das próximas M linhas é composta por três inteiros U, V (1 ≤ U, V ≤ N e U ≠ V) e D (1 ≤ D ≤ 500) que indiciam que existe um corredor com comprimento D que liga as salas U e V. É sempre possível utilizar o corredor em ambas as direções e é garantido que não existem arestas repetidas na entrada.

## Saída

Um único inteiro em uma linha. A distância mínima para o Tobias e o Gabriel percorrerem todas as salas sem fazer nenhum ciclo durante o caminho, saindo e voltando para mesma sala de origem.
