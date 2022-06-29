#include <stack>
#include <iostream>

using namespace std;

struct carga // Criando uma estrutura para as cargas
{
    int id, destino, quantidade;
    char *produto;
    float peso, valor;
};

int main()
{
    struct carga caixa[5];

    // Declarando os valores dos produtos
    /*
    ___________________________________________________
    | ID | Produto | Peso | Valor | Quatidade | Destino |
    | 0  | Caderno | 1.0  | 25.0  |    10     |    4    |
    | 1  | Lâmpada | 0.2  | 10.0  |    24     |    4    |
    | 2  |  Livro  | 1.0  | 80.0  |     5     |    2    |
    | 3  |  Papel  | 0.3  | 10.0  |    15     |    3    |
    | 4  |  Prato  | 7.0  | 200.0 |     3     |    3    |
    |____|_________|______|_______|___________|_________|

    */

    caixa[0].id = 1;
    caixa[0].produto = "Caderno";
    caixa[0].peso = 1.0;
    caixa[0].valor = 25.0;
    caixa[0].quantidade = 10;
    caixa[0].destino = 4;

    caixa[1].id = 2;
    caixa[1].produto = "Lâmpada";
    caixa[1].peso = 0.2;
    caixa[1].valor = 10.0;
    caixa[1].quantidade = 24;
    caixa[1].destino = 4;

    caixa[2].id = 3;
    caixa[2].produto = "Livro";
    caixa[2].peso = 1.0;
    caixa[2].valor = 80.0;
    caixa[2].quantidade = 5;
    caixa[2].destino = 2;

    caixa[3].id = 4;
    caixa[3].produto = "Resma de papel";
    caixa[3].peso = 0.3;
    caixa[3].valor = 10.0;
    caixa[2].quantidade = 15;
    caixa[3].destino = 3;

    caixa[4].id = 5;
    caixa[4].produto = "Caixa de pratos (com 12und)";
    caixa[4].peso = 7.0;
    caixa[4].valor = 200.0;
    caixa[2].quantidade = 3;
    caixa[4].destino = 3;

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("\n O Produto %s, com id %d, pesa %.2fkg, tem valor de R$%.2f e deve chegar ao destino %d", caixa[i].produto, caixa[i].id, caixa[i].peso, caixa[i].valor, caixa[i].destino);
    }

    printf("\n\n");

    return (0);
};