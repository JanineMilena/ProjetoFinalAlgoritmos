#include <stack>
#include <iostream>

using namespace std;

// Criando uma estrutura para as cargas
struct carga
{
    int id, valor, peso;
};

// Função com resolução do problema da mochila, usando programação dinâmica
int knapsack(int max_peso, int pesos[], int valores[], int total_itens)
{
    int max_valor[total_itens + 1][max_peso + 1];

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
            if (pesos[i - 1] <= j)
            {
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

    return max_valor[total_itens][max_peso];
}

int main()
{
    struct carga caixa[5];

    /*
    Declarando os valores dos produtos:
     ___________________
    |    |       |      |
    | ID | Valor | Peso |
    | 1  |   3   |  2   |
    | 2  |   5   |  4   |
    | 3  |   8   |  5   |
    | 4  |   4   |  3   |
    | 5  |  10   |  9   |
    |____|_______|______|
    */

    caixa[0].id = 1;
    caixa[0].valor = 3;
    caixa[0].peso = 2;

    caixa[1].id = 2;
    caixa[1].valor = 5;
    caixa[1].peso = 4;

    caixa[2].id = 3;
    caixa[2].valor = 8;
    caixa[2].peso = 5;

    caixa[3].id = 4;
    caixa[3].valor = 4;
    caixa[3].peso = 3;

    caixa[4].id = 5;
    caixa[4].valor = 10;
    caixa[4].peso = 9;

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("\nO produto id %d, pesa %dkg, tem valor de R$%d", caixa[i].id, caixa[i].peso, caixa[i].valor);
    }

    printf("\n\n");

    int max_peso = 20;   // Capacidade máxima do caminhão: max_peso
    int total_itens = 5; // Número de elementos que precisam ser alocados
    int valores[5];      // Vetor com valores (benefício) de cada elemento
    int pesos[5];        // Vetor com pesos de cada elemento

    // Preenchendo valor dos vetores com os valores da structure
    for (i = 0; i < 5; i++)
    {
        valores[i] = caixa[i].valor;
        pesos[i] = caixa[i].peso;
    }

    // Obtém o valor máximo que pode ser colocado no caminhão
    int max_valor = knapsack(max_peso, pesos, valores, total_itens);

    printf("Valor máximo que a mochila pode carregar: %d\n  ", max_valor);

    return (0);
};