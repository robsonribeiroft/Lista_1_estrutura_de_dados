#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void insere_lista(int vetor[], int tam_vetor){
    int i, tmp;
    for(i=0; i<tam_vetor; i++){
        printf("valor da posicao %d: ", i);
        scanf("%d", &tmp);
        while(tmp>=256){
            printf("valor invalido!");
            scanf("%d", &tmp);
        }
        vetor[i] = tmp;
    }
}

void insere_lista_auto(int vetor[], int tam_vetor){
    int i, tmp;
    for(i=0; i<tam_vetor;i++){
        tmp = rand()%300;
        while(tmp>=256){
            tmp = rand()%300;
        }
        vetor[i] = tmp;
    }
}

void mostra_lista(int vetor[], int tam_vetor){
    int i;
    for(i=0; i<tam_vetor; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
}

int cont_elemt_par(int vetor[], int tam_vetor){
    int i, cont=0;
    for(i=0; i<tam_vetor; i++){
        if (vetor[i]%2 == 0) cont++;
    }
    return cont;
}

int cont_elemt_impar(int vetor[], int tam_vetor){
    int i, cont=0;
    for(i=0; i<tam_vetor; i++){
        if (vetor[i]%2 != 0){
            cont++;
        }
    }
    return cont;
}

float media_maior_50(int vetor[], int tam_vetor){
    int i;
    float cont=0, soma=0, media=0;
    for(i=0; i<tam_vetor; i++){
        if (vetor[i]>50){
            cont++;
            soma += vetor[i];
        }
    }
    if(cont == 0){
        cont++;
    }
    media = soma/cont;
    return media;
}

void bubblesort_inverso(int vetor[], int tam_vetor){
    int i, j, tmp;
    for(i=tam_vetor-1; i>=1; i--){
        for(j=0; j<i; j++){
            if(vetor[j]<vetor[j+1]){
                tmp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = tmp;
            }
        }
    }
}

void bubblesort(int vetor[], int tam_vetor){
    int i, j, tmp;
    for(i=tam_vetor-1; i>=1; i--){
        for(j=0; j<i; j++){
            if(vetor[j]>vetor[j+1]){
                tmp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = tmp;
            }
        }
    }
}

void question_one(){
    int tam_vetor=100;
    int vetor[tam_vetor];
    printf("\n------------- Questao 1 -------------\n");
    insere_lista_auto(vetor, tam_vetor);
    printf("Lista incial:\n");
    mostra_lista(vetor, tam_vetor);

    int numPar = cont_elemt_par(vetor, tam_vetor);
    int numImpar = cont_elemt_impar(vetor, tam_vetor);
    printf("par: %d\nimpar: %d\n", numPar, numImpar);

    float media = media_maior_50(vetor, tam_vetor);
    printf("media: %.2f\n\n", media);

    bubblesort_inverso(vetor, tam_vetor);
    printf("lista ordenada: \n");
    mostra_lista(vetor, tam_vetor);
}

int getTamVetorY(int vetor[], int tam_vetor){
    int cont=0, i;
    for(i=0; i<tam_vetor; i++){
        if(vetor[i]>=10 && vetor[i]<=40){
            cont++;
        }
    }
    return cont;
}

void insere_vetorY(int vetorX[], int vetorY[], int tam_vetorX){
    int tmp=0, i;
    for(i=0; i<tam_vetorX; i++){
        if(vetorX[i]>=10 && vetorX[i]<=40){
            vetorY[tmp] = vetorX[i];
            tmp++;
        }
    }
}

void insere_vetorW(int vetorX[], int vetorW[], int tam_vetorX){
    int tmp=0,i;
    for(i=0; i<tam_vetorX; i++){
        if(i%2 == 0){
            vetorW[tmp] = vetorX[i];
            tmp++;
        }
    }
}

int getMenor(int vetor[], int tam_vetor){
    int menor = vetor[0], i;
    for(i=1; i<tam_vetor; i++){
        if(menor>vetor[i]){
            menor = vetor[i];
        }
    }
    return menor;
}

int getMaior(int vetor[], int tam_vetor){
    int maior = vetor[0], i;
    for(i=1; i<tam_vetor; i++){
        if(maior<vetor[i]){
            maior = vetor[i];
        }
    }
    return maior;
}

int pesquisaBinaria(int vetor[], int tam_vetor, int busca){
    int menor=0, maior=tam_vetor, meio;
    while(menor <= maior){
        meio=(menor+maior)/2;
        if(vetor[meio]==busca) return meio;
        if(vetor[meio]<busca) menor = meio+1;
        else maior = meio-1;
    }
    return -1;
}

void question_two(){
    int tam_vetorX, tam_vetorY;
    printf("\n------------- Questao 2 -------------\n");
    printf("Tamanho do vetor X: ");
    scanf("%d", &tam_vetorX);

    int vetorX[tam_vetorX];
    insere_lista_auto(vetorX, tam_vetorX);
    tam_vetorY = getTamVetorY(vetorX, tam_vetorX);
    int vetorY[tam_vetorY];
    insere_vetorY(vetorX, vetorY, tam_vetorX);
    printf("Vetor Y:\n");
    mostra_lista(vetorY, tam_vetorY);

    int tam_vetorW = (tam_vetorX/2)+1;
    int vetorW[tam_vetorW];
    insere_vetorW(vetorX, vetorW, tam_vetorX);
    printf("Vetor W:\n");
    mostra_lista(vetorW, tam_vetorW);

    printf("o menor do valor do vetor X: %d\n", getMenor(vetorX, tam_vetorX));
    printf("o maior do valor do vetor X: %d\n", getMaior(vetorX, tam_vetorX));

    printf("Vetor X:\n");
    bubblesort(vetorX, tam_vetorX);
    mostra_lista(vetorX, tam_vetorX);

    int busca;
    printf("valor a procurar no vetor X: ");
    scanf("%d", &busca);
    busca = pesquisaBinaria(vetorX, tam_vetorX, busca);
    busca>=0 ? printf("O valor esta posicao: %d\n", busca) : printf("Vetor nao possui valor pesquisado.\n");

void question_three(){
    int tam_vetorAB, busca, tam_vetorC, i, j=0, aux=1;
    printf("\n------------- Questao 3 -------------\n");
    printf("Tamanho dos vetores A e B: ");
    scanf("%d", &tam_vetorAB);
    tam_vetorC = tam_vetorAB*2;

    int vetorA[tam_vetorAB], vetorB[tam_vetorAB], vetorC[tam_vetorC];
    insere_lista_auto(vetorA, tam_vetorAB);
    insere_lista_auto(vetorB, tam_vetorAB);
    for(i=0; i<tam_vetorAB; i++){
        vetorC[j] = vetorA[i];
        j++;
        vetorC[j] = vetorB[i];
        j++;
    }
    mostra_lista(vetorA, tam_vetorAB);
    mostra_lista(vetorB, tam_vetorAB);
    mostra_lista(vetorC, tam_vetorC);

    printf("Valor a procurar no vetor C: ");
    scanf("%d", &busca);
    i = 0;
    while(i<tam_vetorC || aux==0){
        if(busca == vetorC[i]){
            printf("valor na posicao: %d\n", i);
            aux = 1;
        }
        i++;
        if(i>=tam_vetorC) printf("valor nao encontrado\n");
    }
}

int primo(int num){
    int i;
    if (num==0) return 0;
    else if (num==1 || num==2) return 1;
    else{
        for(i=3; i<sqrt(num)+1; i++){
            if (num%i==0) return 0;
        }
    }
    return 1;
}

int primoAnterior(int vetor[], int ind_primo){
    int i;
    for(i=ind_primo-1; i>=0; i--){
        if(primo(vetor[i]))
            return i;
    }
    return -1;
}

int primoPosterior(int vetor[], int ind_primo, int tam_vetor){
    int i;
    for(i=ind_primo+1; i<tam_vetor; i++){
        if (primo(vetor[i])) return i;
    }
    return -1;
}

void question_four(){
    int n, tam_vetor=100, vetor[tam_vetor], aux;
    printf("\n------------- Questao 4 -------------\n");
    insere_lista_auto(vetor, tam_vetor);
    mostra_lista(vetor, tam_vetor);
    do{
        printf("Valor a procurar(indice): ");
        scanf("%d", &n);
        if(primo(vetor[n])){
            printf("%d e primo\n", vetor[n]);
            aux = primoAnterior(vetor, n);
            aux>=0 ? printf("O proximo primo anterior esta na posicao: %d\n", aux) : printf("Nao existe um primo anterior\n");
            aux = primoPosterior(vetor, n, tam_vetor);
            aux>=0 ? printf("O proximo primo posterior esta na posicao: %d\n", aux) : printf("Nao existe um primo posterior\n");
        }
        else
            printf("O numero nao e primo\n");

    }while(!primo(vetor[n]));
}

int repitido(int vetor[], int tam_vetor){
    int i, j;
    for(i=0; i<tam_vetor; i++){
        for(j=0; j<tam_vetor; j++){
            if(vetor[i] == vetor[j]) return 1;
        }
    }
    return 0;
}

int removeRepetido(int vetor[], int tam_vetor){
    int i, j, k, cont=0;
    for(i=0; i<tam_vetor; i++){
        for(j=i+1; j<tam_vetor; j++){
            if(vetor[i] == vetor[j]){
                for(k=j+1; k<tam_vetor; k++){
                    vetor[k-1] = vetor[k];
                }
                cont++;
                tam_vetor--;
            }
        }
    }
    printf("%d elemento(s) repetido(s) foram removidos\n", cont);
    mostra_lista(vetor, tam_vetor);
    return cont;
}


void question_five(){
    int tam_vetor, aux, busca;
    printf("\n------------- Questao 5 -------------\n");
    printf("Entre com o tamanho do vetor: ");
    scanf("%d", &tam_vetor);
    int vetor[tam_vetor];
    insere_lista_auto(vetor, tam_vetor);
    aux = repitido(vetor, tam_vetor);
    if (aux){
        printf("existe elementos repetidos\n");
        tam_vetor -= removeRepetido(vetor, tam_vetor);
    }
    else
        printf("OK\n");
    bubblesort(vetor, tam_vetor);
    mostra_lista(vetor, tam_vetor);
    printf("valor da busca: ");
    fflush(stdin);
    scanf("%d", &busca);
    busca = pesquisaBinaria(vetor, tam_vetor, busca);
    busca>=0 ? printf("O valor se encontra na posicao: %d\n", busca) : printf("Valor nao enontrado\n");

int main() {
    srand((unsigned)time(NULL)); // seed para n�meros rand�mico
    question_one();
    question_two();
    question_three();
    question_four();
    question_five();
    return 0;
}
