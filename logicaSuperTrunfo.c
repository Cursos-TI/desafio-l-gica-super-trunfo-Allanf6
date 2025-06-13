#include <stdio.h>

int main() {
    char cidade1[30], codigo1[30];
    char cidade2[30], codigo2[30];
    unsigned long int populacao1, populacao2;
    int pontos1, pontos2;
    float area1, area2, pib1, pib2;

    // Entrada da Carta 1
    printf("CARTA 1:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1);
    printf("Código da carta: ");
    scanf("%s", codigo1);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Quantidade de pontos turísticos: ");
    scanf("%d", &pontos1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);

    // Cálculos da Carta 1
    float densidade1 = populacao1 / area1;
    float pibPerCapta1 = pib1 * 1e9 / populacao1;
    float superPoder1 = densidade1 > 0 ? 
        populacao1 + area1 + pib1 * 1e9 + pontos1 + pibPerCapta1 + (1 / densidade1) :
        populacao1 + area1 + pib1 * 1e9 + pontos1 + pibPerCapta1;

    // Entrada da Carta 2
    printf("\nCARTA 2:\n");
    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);
    printf("Código da carta: ");
    scanf("%s", codigo2);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Quantidade de pontos turísticos: ");
    scanf("%d", &pontos2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);

    // Cálculos da Carta 2
    float densidade2 = populacao2 / area2;
    float pibPerCapta2 = pib2 * 1e9 / populacao2;
    float superPoder2 = densidade2 > 0 ? 
        populacao2 + area2 + pib2 * 1e9 + pontos2 + pibPerCapta2 + (1 / densidade2) :
        populacao2 + area2 + pib2 * 1e9 + pontos2 + pibPerCapta2;

    // Comparações por critérios
    int pontos_carta1 = 0, pontos_carta2 = 0;

    if (populacao1 > populacao2) pontos_carta1++;
    else if (populacao2 > populacao1) pontos_carta2++;

    if (pontos1 > pontos2) pontos_carta1++;
    else if (pontos2 > pontos1) pontos_carta2++;

    if (area1 < area2) pontos_carta1++;  // menor área vence
    else if (area2 < area1) pontos_carta2++;

    if (pib1 > pib2) pontos_carta1++;
    else if (pib2 > pib1) pontos_carta2++;

    if (superPoder1 > superPoder2) pontos_carta1++;
    else if (superPoder2 > superPoder1) pontos_carta2++;

    printf("\n---------------------------------\n");
    printf("Resultado: \n");

    if (pontos_carta1 > pontos_carta2) {
        printf("\n%s venceu 🏆", cidade1);
    } else if (pontos_carta2 > pontos_carta1) {
        printf("\n%s venceu 🏆", cidade2);
    } else {
        printf("\nEmpate 🤝");
    }

    return 0;
}

