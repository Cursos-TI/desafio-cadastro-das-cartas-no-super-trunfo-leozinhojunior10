#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void ler_carta(Carta *carta) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Digite o código: ");
    scanf("%d", &carta->codigo);

    printf("Digite o nome: ");
    scanf(" %[^\n]", carta->nome);

    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);

    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    // Calcular densidade populacional e PIB per capita
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = (carta->pib * 1000000000) / carta->populacao; // Convertendo PIB para reais
}

float calcular_super_poder(Carta carta) {
    return (float)carta.populacao + carta.area + carta.pib + 
           carta.pontos_turisticos + carta.pib_per_capita + 
           (1.0f / carta.densidade_populacional);
}

void comparar_atributo(const char* nome, float valor1, float valor2, int menor_vence) {
    int resultado = 0;
    if (menor_vence) {
        resultado = valor1 < valor2 ? 1 : 0;
    } else {
        resultado = valor1 > valor2 ? 1 : 0;
    }
    printf("%s: Carta 1 vence? %d\n", nome, resultado);
}

int main() {
    Carta carta1, carta2;

    printf("Insira os dados da Carta 1:\n");
    ler_carta(&carta1);

    printf("\nInsira os dados da Carta 2:\n");
    ler_carta(&carta2);

    // Calcular Super Poder
    carta1.super_poder = calcular_super_poder(carta1);
    carta2.super_poder = calcular_super_poder(carta2);

    // Comparações
    printf("\nResultados das Comparações:\n");
    comparar_atributo("População", (float)carta1.populacao, (float)carta2.populacao, 0);
    comparar_atributo("Área", carta1.area, carta2.area, 0);
    comparar_atributo("PIB", carta1.pib, carta2.pib, 0);
    comparar_atributo("Pontos Turísticos", (float)carta1.pontos_turisticos, (float)carta2.pontos_turisticos, 0);
    comparar_atributo("PIB per Capita", carta1.pib_per_capita, carta2.pib_per_capita, 0);
    comparar_atributo("Densidade Populacional", carta1.densidade_populacional, carta2.densidade_populacional, 1);
    comparar_atributo("Super Poder", carta1.super_poder, carta2.super_poder, 0);

    return 0;
}
