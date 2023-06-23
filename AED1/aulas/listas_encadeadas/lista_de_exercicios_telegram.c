#include <stdio.h>
#include <stdlib.h>


/*Faça uma função que receba como parâmetro uma lista encadeada e retorne verdadeiro caso a mesma seja simétrica e falso em caso contrário. 
Considere uma lista encadeada dinâmica com dados do tipo inteiro (int). 
Diz-se que uma lista encadeada é simétrica (conceito inventado para a questão) 
se cada elemento que ocorre antes da posição do meio (na primeira metade, desconsiderando o elemento do centro se houver número ímpar de elementos), 
tem um correspondente de valor igual na segunda metade da lista (há um outro com o mesmo valor na segunda metade da lista). 
Considere que nenhum valor ocorre mais de duas vezes na lista. Como exemplo, as listas <3,6,9, 3,9,6> e <6, 3,9,3,9,6> são simétricas. 
Já as listas <3,6,9,3,6,5> e <3,6,5,5,2,3> não são simétricas. 
*/