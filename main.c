#include <stdio.h>
#include <stdbool.h>

int main() {
    char nomes[10][50];
    float precos[10];
    int tamanhos[10];
    int quantidades[10];

    int total = 0;
    int opcao = 0;
    int codigo;
    int quantidadeVenda;
    int i;
    int j;
    int k;
    bool encontrado;

    while (opcao != 7) {
        printf("\n====================================\n");
        printf(" SISTEMA DE ESTOQUE - LOJA DE ROUPAS\n");
        printf("====================================\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produto\n");
        printf("3 - Atualizar produto\n");
        printf("4 - Excluir produto\n");
        printf("5 - Registrar venda\n");
        printf("6 - Ver estoque baixo\n");
        printf("7 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (total < 10) {
                    printf("\n--- CADASTRO DE PRODUTO ---\n");

                    printf("Nome do produto: ");
                    scanf(" %[^\n]", nomes[total]);

                    printf("Preco: R$ ");
                    scanf("%f", &precos[total]);

                    printf("Tamanho (numero): ");
                    scanf("%d", &tamanhos[total]);

                    printf("Quantidade: ");
                    scanf("%d", &quantidades[total]);

                    total++;

                    printf("\nProduto cadastrado com sucesso!\n");
                } else {
                    printf("\nEstoque cheio! Nao e possivel cadastrar mais produtos.\n");
                }
                break;

            case 2:
                printf("\n--- LISTA DE PRODUTOS ---\n");

                if (total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    i = 0;

                    while (i < total) {
                        printf("\nCodigo: %d\n", i + 1);
                        printf("Produto: %s\n", nomes[i]);
                        printf("Preco: R$ %.2f\n", precos[i]);
                        printf("Tamanho: %d\n", tamanhos[i]);
                        printf("Quantidade: %d\n", quantidades[i]);

                        i++;
                    }
                }
                break;

            case 3:
                printf("\n--- ATUALIZAR PRODUTO ---\n");

                if (total == 0) {
                    printf("Nenhum produto cadastrado.\n");
                } else {
                    printf("Digite o codigo do produto: ");
                    scanf("%d", &codigo);

                    if (codigo >= 1 && codigo <= total) {
                        i = codigo - 1;

                        printf("Novo nome do produto: ");
                        scanf(" %[^\n]", nomes[i]);

                        printf("Novo preco: R$ ");
                        scanf("%f", &precos[i]);

                        printf("Novo tamanho (numero): ");
                        scanf("%d", &tamanhos[i]);

                        printf("Nova quantidade: ");
                        scanf("%d", &quantidades[i]);

                        printf("\nProduto atualizado com sucesso!\n");
                    } else {
                        printf("\nCodigo invalido.\n");
                    }
                }
                break;

            case 4:
    printf("\n--- EXCLUIR PRODUTO ---\n");

    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);

        if (codigo >= 1 && codigo <= total) {

            i = codigo - 1;

            for (j = i; j < total - 1; j++) {
                for (k = 0; k < 50; k++) {
                    nomes[j][k] = nomes[j + 1][k];
                }

                precos[j] = precos[j + 1];
                tamanhos[j] = tamanhos[j + 1];
                quantidades[j] = quantidades[j + 1];
            }

            total--;

            printf("\nProduto excluido com sucesso!\n");

        } else {
            printf("\nCodigo invalido.\n");
        }
    }
    break;


case 5:
    printf("\n--- REGISTRAR VENDA ---\n");

    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
    } else {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigo);

        if (codigo >= 1 && codigo <= total) {

            i = codigo - 1;

            printf("Produto: %s\n", nomes[i]);
            printf("Quantidade disponivel: %d\n", quantidades[i]);

            printf("Quantidade vendida: ");
            scanf("%d", &quantidadeVenda);

            if (quantidadeVenda > 0 && quantidadeVenda <= quantidades[i]) {

                quantidades[i] = quantidades[i] - quantidadeVenda;

                printf("\nVenda registrada com sucesso!\n");
                printf("Estoque restante: %d\n", quantidades[i]);

            } else {
                printf("\nQuantidade invalida ou estoque insuficiente.\n");
            }

        } else {
            printf("\nCodigo invalido.\n");
        }
    }
    break;


case 6:
    printf("\n--- ESTOQUE BAIXO ---\n");

    encontrado = false;

    i = 0;

    while (i < total) {

        if (quantidades[i] < 5) {

            printf("\nCodigo: %d\n", i + 1);
            printf("Produto: %s\n", nomes[i]);
            printf("Quantidade: %d\n", quantidades[i]);

            encontrado = true;
        }

        i++;
    }

    if (encontrado == false) {
        printf("Nenhum produto com estoque baixo.\n");
    }

    break;


case 7:
    printf("\nSistema encerrado. Obrigado!\n");
    break;    

        }
    }

    return 0;
}