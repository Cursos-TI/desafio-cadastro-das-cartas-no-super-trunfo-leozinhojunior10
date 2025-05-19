#include <stdio.h>

struct CartaCidade {
    char estado[50];
    int codigo;
    char nomeCidade[100];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    struct CartaCidade cidade[2];

    for (int i = 0; i < 2; i++) {
        printf("Digite os dados da cidade %d:\n", i + 1);

        printf("Estado: ");
        scanf(" %[^\n]", cidade[i].estado);

        printf("Codigo da carta: ");
        scanf("%d", &cidade[i].codigo);

        printf("Nome da cidade: ");
        scanf(" %[^\n]", cidade[i].nomeCidade);

        printf("Populacao: ");
        scanf("%d", &cidade[i].populacao);

        printf("Area (km²): ");
        scanf("%f", &cidade[i].area);

        printf("PIB (em reais): ");
        scanf("%f", &cidade[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cidade[i].pontosTuristicos);

        // Cálculo da densidade populacional e PIB per capita
        cidade[i].densidadePopulacional = cidade[i].populacao / cidade[i].area;
        cidade[i].pibPerCapita = cidade[i].pib / cidade[i].populacao;

        printf("\n");
    }

    // Exibição dos dados
    for (int i = 0; i < 2; i++) {
        printf("\n--- Informações da Cidade %d ---\n", i + 1);
        printf("Estado: %s\n", cidade[i].estado);
        printf("Codigo da carta: %d\n", cidade[i].codigo);
        printf("Nome da cidade: %s\n", cidade[i].nomeCidade);
        printf("Populacao: %d\n", cidade[i].populacao);
        printf("Area: %.2f km²\n", cidade[i].area);
        printf("PIB: R$ %.2f\n", cidade[i].pib);
        printf("Pontos turisticos: %d\n", cidade[i].pontosTuristicos);
        printf("Densidade populacional: %.2f hab/km²\n", cidade[i].densidadePopulacional);
        printf("PIB per capita: R$ %.2f\n", cidade[i].pibPerCapita);
    }

    return 0;
}
