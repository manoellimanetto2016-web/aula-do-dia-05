#include <stdio.h>
#include <string.h>

#define TAM 12
#define MAX_PRODUTOS 100

int contar(int vet[], int numero) {
    int i, quantidade = 0;

    for (i = 0; i < TAM; i++) {
        if (vet[i] == numero) {
            quantidade++;
        }
    }

    return quantidade;
}

void ordenarNumeros(int vet[], int tamanho) {
    int i, j, aux;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vet[j] < vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void ordenarProdutos(char nomes[][100], float precos[], int quantidade) {
    int i, j;
    char nomeAux[100];
    float precoAux;

    for (i = 0; i < quantidade - 1; i++) {
        for (j = 0; j < quantidade - 1 - i; j++) {
            if (strcmp(nomes[j], nomes[j + 1]) > 0) {
                strcpy(nomeAux, nomes[j]);
                strcpy(nomes[j], nomes[j + 1]);
                strcpy(nomes[j + 1], nomeAux);

                precoAux = precos[j];
                precos[j] = precos[j + 1];
                precos[j + 1] = precoAux;
            }
        }
    }
}

int main(void) {
    int numeros[TAM];
    int pares[TAM];
    int quantidadePares = 0;
    int i, j, qtd;
    int jaContado;
    int totalProdutos = 0;
    char nomes[MAX_PRODUTOS][100];
    float precos[MAX_PRODUTOS];

    printf("Digite 12 numeros inteiros:\n");

    for (i = 0; i < TAM; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    printf("\nNumeros informados:\n");

    for (i = 0; i < TAM; i++) {
        printf("%d ", numeros[i]);
    }

    printf("\n\nQuantidade de vezes que cada numero aparece:\n");

    for (i = 0; i < TAM; i++) {
        jaContado = 0;

        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                jaContado = 1;
            }
        }

        if (jaContado == 0) {
            qtd = contar(numeros, numeros[i]);

            printf("Numero %d aparece %d vez(es).\n", numeros[i], qtd);

            if (qtd % 2 == 0) {
                pares[quantidadePares] = numeros[i];
                quantidadePares++;
            } else {
                /* A quantidade de produtos corresponde ao numero de ocorrencias. */
                for (j = 0; j < qtd; j++) {
                    if (totalProdutos >= MAX_PRODUTOS) {
                        printf("Limite de produtos atingido.\n");
                        break;
                    }

                    printf("\nCadastro do produto %d de %d\n", j + 1, qtd);
                    printf("Nome do produto: ");
                    scanf(" %99[^\n]", nomes[totalProdutos]);

                    printf("Preco unitario: R$ ");
                    scanf("%f", &precos[totalProdutos]);

                    totalProdutos++;
                }
            }
        }
    }

    ordenarNumeros(pares, quantidadePares);
    ordenarProdutos(nomes, precos, totalProdutos);

    printf("\n\nProdutos cadastrados em ordem alfabetica:\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto foi cadastrado.\n");
    }

    for (i = 0; i < totalProdutos; i++) {
        printf("Nome: %s | Preco: R$ %.2f\n", nomes[i], precos[i]);
    }

    printf("\nNumeros com quantidade de ocorrencias par (em ordem decrescente):\n");

    if (quantidadePares == 0) {
        printf("Nenhum numero encontrado.\n");
    } else {
        for (i = 0; i < quantidadePares; i++) {
            printf("%d ", pares[i]);
        }
        printf("\n");
    }

    return 0;
}
