/*
    Nome: Luiz Henrique Benedito
    nUSP: 12563814

    SSC0503 - Algoritimos de Estruturas de Dados 2
    Profª.: Maria Cristina

    ATIVIDADE 1 

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 50;

typedef struct cadlivros{
    int id;
    char titulo[100];
    char autor[50];
};


int main(){
    FILE *arquivo;
    struct cadlivros livros[SIZE];
    int r, m, i;


    arquivo = fopen("lista_livros.bin", "rb+");
    if(arquivo==NULL){
        printf("Não foi possivel abrir o arquivo!");
    }

    for(i=0; i<r; i++){
        livros[i].id = i+1;
        scanf("%s", livros[i].titulo);
        scanf("%s", livros[i].autor);
    }
}