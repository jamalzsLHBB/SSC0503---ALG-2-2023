#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100

struct Livro {
    char titulo[50];
    char autor[30];
    int ano;
};

int main() {
    struct Livro livros[MAX_LIVROS];
    int n, i;
    FILE *arquivo;

    // Leitura dos dados de registro de livros
    printf("Digite o número de livros: ");
    scanf("%d", &n);
    printf("Digite os dados dos livros:\n");
    for (i = 0; i < n; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: ");
        scanf("%s", livros[i].titulo);
        printf("Autor: ");
        scanf("%s", livros[i].autor);
        printf("Ano: ");
        scanf("%d", &livros[i].ano);
    }

    // Escrita dos dados no arquivo
    arquivo = fopen("livros.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fwrite(livros, sizeof(struct Livro), n, arquivo);
    fclose(arquivo);

    // Leitura e impressão dos últimos registros escritos no arquivo
    arquivo = fopen("livros.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fseek(arquivo, -(long)sizeof(struct Livro) * 2, SEEK_END);
    printf("Últimos registros escritos no arquivo:\n");
    for (i = 0; i < 2; i++) {
        fread(&livros[i], sizeof(struct Livro), 1, arquivo);
        printf("Título: %s, Autor: %s, Ano: %d\n",
               livros[i].titulo, livros[i].autor, livros[i].ano);
    }
    fclose(arquivo);

    return 0;
}
