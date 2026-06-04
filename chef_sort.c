#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Dependendo do nível escolhido (Novato, Aventureiro ou Mestre), 
// descomente e utilize as estruturas e funções correspondentes.

// ====================================================================
// ESTRUTURAS DE DADOS (Para Níveis Aventureiro e Mestre)
// ====================================================================

// Struct para o Nível Aventureiro

typedef struct {
    char nome[50];
    int qtd_ingredientes;
} Prato;


// Struct para o Nível Mestre
/*
typedef struct {
    char nome_prato[50];
    int numero_comanda;
} Comanda;
*/


// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
/*
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    int i, j;
    int trocou; // variavel de controle
    char temp[50]; // variavel temporaria para troca de strings
    
    // contadores
    *comparacoes = 0;
    *trocas = 0;

    // laco externo: controle de passagens
    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        // laco interno: compara elementos
        for (j = 0; j < n - 1 - i; j++) { 
            
            (*comparacoes)++; 

            // comparacao alfabetica das strings
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Realiza a troca usando strcpy
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);

                (*trocas)++; // incrementa o valor apontado por 'trocas'
                trocou = 1;  // sinaliza que houve movimentação
            }
        }

        // se a passagem terminou sem trocas, a lista já está ordenada (melhor caso O(n))
        if (trocou == 0) {
            break;  
        }
    }
}
*/

// Nível Aventureiro: Selection Sort para array de structs (Prato)

void selectionSortPratos(Prato arr[], int n) {
    // Sua lógica do Selection Sort aqui buscando a menor qtd_ingredientes
    int i, j, min_idx;
    Prato temp; // Usado para fazer a troca (recebe a struct inteira)

    // O laço externo avança a fronteira do array ordenado
    for (i = 0; i < n - 1; i++) {
        // Encontra o índice do menor elemento no array desordenado
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            // Comparamos a quantidade de ingredientes numericamente
            if (arr[j].qtd_ingredientes < arr[min_idx].qtd_ingredientes) {
                min_idx = j;
            }
        }

        // Se o menor elemento encontrado não for o que já está na posição 'i', fazemos a troca
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}



// Nível Mestre: Recursive Insertion Sort para array de structs (Comanda)
// Dica: Lembre-se de definir o "caso base" (n <= 1) para parar a recursão!
/*
void recursiveInsertionSort(Comanda arr[], int n) {
    // Sua lógica do Insertion Sort Recursivo aqui
}
*/


// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    /*
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    // Laco para imprimir ingredientes antes
    for(int i = 0; i < num_ingredientes; i++) {
        printf("%d. %s\n", i + 1, ingredientes[i]);
    }

    // Chamada da funcao bubbleSortStrings(...)
    bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);

    printf("\nLista DEPOIS da ordenacao:\n");
    // Laco para imprimir ingredientes depois
    for(int i = 0; i < num_ingredientes; i++) {
        printf("%d. %s\n", i + 1, ingredientes[i]);
    }
    // Imprimir totais de comparacoes e trocas
    printf("\n--------------------------------------------\n");
    printf("METRICAS DE DESEMPENHO (Bubble Sort):\n");
    printf("- Total de comparacoes: %d\n", comparacoes);
    printf("- Total de trocas efetuadas: %d\n", trocas);
    printf("--------------------------------------------\n");
    */
    


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL AVENTUREIRO (Pratos / Selection Sort)
    // ---------------------------------------------------------
    
    // Inicialize aqui o seu vetor de Pratos
    Prato cardapio[5] = {
        {"Feijoada", 12},
        {"Ovo Frito", 2},
        {"Lasanha", 8},
        {"Salada de Frutas", 5},
        {"Macarrao Alho e Oleo", 3}
    };
    int num_pratos = 5;
    
    printf("\n--- Nivel Aventureiro: Organizando os Pratos ---\n");
    // Imprima antes, chame a funcao selectionSortPratos, imprima depois
    printf("Lista ANTES da ordenacao:\n");
    for(int i = 0; i < num_pratos; i++) {
        printf("%d. %s (%d ingredientes)\n", i + 1, cardapio[i].nome, cardapio[i].qtd_ingredientes);
    }
    
    // Chama a função Selection Sort
    selectionSortPratos(cardapio, num_pratos);

    // Imprime DEPOIS da ordenação
    printf("\nLista DEPOIS da ordenacao:\n");
    for(int i = 0; i < num_pratos; i++) {
        printf("%d. %s (%d ingredientes)\n", i + 1, cardapio[i].nome, cardapio[i].qtd_ingredientes);
    }


    // ---------------------------------------------------------
    // ÁREA DO NÍVEL MESTRE (Comandas / Recursive Insertion Sort)
    // ---------------------------------------------------------
    /*
    // Inicialize aqui o seu vetor de Comandas
    
    printf("\n--- Nivel Mestre: Organizando as Comandas ---\n");
    // Imprima antes, chame a funcao recursiveInsertionSort, imprima depois
    */

    return 0;
}
