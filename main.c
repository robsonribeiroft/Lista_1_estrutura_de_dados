#include <stdio.h>
#include <stdlib.h>

typedef struct emplyee{
    char name[35], gender;
    int peaces;
}SEmployee;

void fillVector(SEmployee vector[], int sizeVector){
    int i;
    for(i=0; i<sizeVector;i++){
        printf("Nome: ");
        fflush(stdin);
        scanf("%s", vector[i].name);
        printf("Sexo: ");
        fflush(stdin);
        scanf("%c", &vector[i].gender);
        printf("Peças fabricadas: ");
        fflush(stdin);
        scanf("%d", &vector[i].peaces);
        printf("\n\n");
    }
}

void report(SEmployee vector[], int sizeVector){
    int allPeaces=0, indBig, i, bigger=-1;
    for(i=0; i<sizeVector; i++){
        allPeaces += vector[i].peaces;
        if(vector[i].peaces>bigger){
            indBig = i;
            bigger = vector[i].peaces;
        }
    }
    printf("\n\nNumero de pecas podruzidas por todos os funcionario: %d\nO Funcionario mais produtivo: %s\n\n", allPeaces, vector[indBig].name);
}

void first(){
    int size;
    printf("Tamanho do vetor: ");
    scanf("%d", &size);
    printf("\n\n");
    SEmployee vector[size];
    fillVector(vector, size);
    report(vector, size);
}

int main()
{
    first();
    return 0;
}
