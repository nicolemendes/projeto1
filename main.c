/* 
 * File:   main.c
 * Author: Nicole
 *
 * Created on 26 de Setembro de 2015, 06:45
 */

#include <stdio.h>
#include <stdlib.h>

/*
Essa funcao imprime o vetor inserido
 */
void imprimevetor(int*v, int n) {
    int i;
    printf("O vetor ordenado %c \n", 130);
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    
    return;
}

/*
funcao que troca posicao de vetores
 */
void troca(int *v, int x, int y) {
    int temp = v[x];
    v[x] = v[y];
    v[y] = temp;
    
    return;
}

/*
Ordenando o vetor
 */

void quicksort(int *v, int f, int l) {
    if (f >= l)
        return;
    int p = rand() % (l - f + 1) + f;
    /*
        localiza posicao aleatoria para inicio da ordenacao
     */
    troca(v, p, f);
    p = f;
    int i = f, j = l;
    while (i < j) {
        while (v[i] <= v[p] && i <= l)
            i++;
        while (v[j] > v[p])
            j--;
        if (j > i)
            troca(v, i, j);
    }
    troca(v, j, p);
    quicksort(v, f, j - 1);
    /*
    chamada recursiva para ordenar posicoes anteriores
     */
    quicksort(v, j + 1, l);
    /*
    chamada recursiva para ordenar posicoes posteriores
     */
    
    return;

}

void frequencydistribution(int *v, int n) {
    /*
        criando um vetor auxiliar para armazenar valores de ocorrencia
     */
    int *vaux = calloc(n, sizeof (int));


    int i, j;

    for (i = 0; i < n; i++) {
        vaux[i]++;
        /*
                para cada numero do vetor ja é atribuido 1 ocorrencia
         */
        for (j = 0; j < n; j++) {
            if (i != j && v[i] == v[j]) {
                /*
                                a primeira condicao do if evita comparacao entre posicoes iguais do vetor
                 */
                vaux[i]++;
            }
        }
    }

    int maior = vaux[0];
    /*
        localizando valor de maior frequencia
     */
    for (i = 0; i < n; i++) {
        if (maior < vaux[i]) {
            maior = vaux[i];
        }
    }
    printf("\n\nA maior frequencia obtida %c de %d \n", 130, maior);
    printf("\nOs numeros que possuem essa frequencia %c(sao):\n", 130);

    /*
       variaveis que evitam que um mesmo numero seja impresso mais de uma vez
     */
    int primeiraimpressao = 1, numeroimpresso = 0;

    for (i = 0; i < n; i++) {
        if (vaux[i] == maior) {
            if (primeiraimpressao == 1) {
                primeiraimpressao = 0;
                numeroimpresso = v[i];

                printf("%d ", v[i]);
            } else if (v[i] != numeroimpresso) {
                numeroimpresso = v[i];
                printf("%d ", v[i]);
            }
        }
    }



    /*
        desalocando memoria
     */
    free(vaux);
    vaux = NULL;
    
    return;
}

/*
Essa funcao acha os elementos que ocorrem uma unica vez
 */
void elementuniqueness(int *v, int n) {
    int i, j, semunico = 1;



    for (i = 0; i < n; i++) {
        int repete = 0;
        for (j = 0; j < n; j++) {
            if (i != j && v[i] == v[j]) {

                /*
                 a primeira condicao evita que o numero seja comparado a ele mesmo
                 */

                repete = 1;
                break;
            }
        }
        if (repete == 0) {
            printf("%d ", v[i]);
            semunico = 0; 
/*
            variavel utilizada para saber se existe um elemento unico
*/

        }

    }
    if (semunico == 1) {
        printf("\nNao existem elementos unicos");
    }
    
    return;

}

/*
Percorrendo o vetor enquanto calcula as diferencas entre numeros adjacentes
 */
void closestpair(int *v, int n) {

    int n1 = 0, n2 = 1, dif = v[n2] - v[n1], i;

    for (i = 2; i < n; i++) {
        int dif_aux = v[i] - v[i - 1];
        /*
                se a dif_aux for menor que dif, igualamos dif a dif_aux, ate obtermos a menor diferenca
         */
        if (dif_aux < dif) {
            n1 = i - 1;
            n2 = i;
            dif = dif_aux;
        }
    }

    printf("\n\n O par com a menor diferenca %c %d %d", 130, v[n1], v[n2]);
    
    return;
}

/*
 * 
 */
void main() {
    int *v, n, i;

    printf("Digite o tamanho do vetor\n");
    scanf("%d", &n);
    /*
        alocando espaco para vetor
     */
    v = calloc(n, sizeof (int));

    for (i = 0; i < n; i++) {
        printf("Digite o %d valor do vetor\n", i);
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, n - 1);

    char stropc[] = "\n\n0 - Sair\n1 - Exibir o vetor ordenado\n2 - Closest Pair\n3 - Element uniqueness\n4 - Frequency distribution\n";
    printf("%s", stropc);
/*
    menu para o usuario escolher comando a ser executado
*/
    int opc;
    scanf("%d", &opc);
    while (opc > 0) {
        switch (opc) {
            case 1:
            {
                imprimevetor(v, n);
                break;

            }
            case 2:
            {
                closestpair(v, n);
                break;
            }
            case 3:
            {
                elementuniqueness(v, n);
                break;
            }
            case 4:
            {
                frequencydistribution(v, n);
                break;
            }
            default:{
                printf("\nOpcao invalida\n");
                break;
            }
        }

        printf("%s", stropc);
        scanf("%d", &opc);
        
    }

    /*
        desalocando memoria
     */
    free(v);
    v = NULL;
    return;
}