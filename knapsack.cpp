/*
Este algoritimo representa uma solução para o problema da mochila usando programação dinâmica.
O mesmo têm como objetivo validar quais objetos podem ser inseridos em uma mochila, levando em
consideração o seu peso e valor, contanto com uma capacidade máxima da mochila.
Utilizamos programação dinâmica pois devido a natureza do problema uma solução usando força
bruta seria inviável, com complexidade exponêncial de 2^n.
*/

#include <iostream>
using namespace std;

int knapsack(int max_peso, int pesos[], int valores[], int total_itens)
{
    // Matriz que será preenchida
    int max_valor[total_itens + 1][max_peso + 1];

    // Inicializando a primeira linha e primeira coluna com 0
    for (int w = 0; w <= max_peso; w++)
    {
        max_valor[0][w] = 0;
    }
    for (int i = 1; i <= total_itens; i++)
    {
        max_valor[i][0] = 0;
    }

    for (int i = 1; i <= total_itens; i++)
    {
        for (int j = 1; j <= max_peso; j++)
        {
            // Validando se o elemento pode fazer parte da solução
            if (pesos[i - 1] <= j)
            {
                // Verificando o máximo
                if ((valores[i - 1] + max_valor[i - 1][j - pesos[i - 1]]) > max_valor[i - 1][j])
                {
                    max_valor[i][j] = valores[i - 1] + max_valor[i - 1][j - pesos[i - 1]];
                }
                else
                {
                    max_valor[i][j] = max_valor[i - 1][j];
                }
            }
            else
            {
                max_valor[i][j] = max_valor[i - 1][j];
            }
        }
    }

    // Imprimir a matriz:
    for (int i = 0; i <= total_itens; i++)
    {
        for (int j = 1; j <= max_peso; j++)
        {
            printf("%d ", max_valor[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    printf("Mochila está cheia!");
    printf("\n\n");

    // Retorna o valor máximo colocado no caminhão
    return max_valor[total_itens][max_peso];
}

int main()
{
    int max_peso = 20;                                               // Capacidade máxima do caminhão: max_peso
    int total_itens = 5;                                             // Número de elementos
    int valores[] = {3, 5, 8, 4, 10};                                // Vetor com valores (benefício) de cada elemento
    int pesos[] = {2, 4, 5, 3, 9};                                   // Vetor com pesos de cada elemento
    int max_valor = knapsack(max_peso, pesos, valores, total_itens); // Obtém o valor máximo que pode ser colocado no caminhão

    printf("Valor máximo que a mochila pode carregar: %d\n  ", max_valor);

    return (0);
};