#include <stdio.h>

void vytvorSachovnici(int pocet, int velikost) {
    // Vytvoření horního rámce
    printf("+");
    for (int i = 0; i < pocet *  velikost; i++) {
        printf("-");
    }
    printf("+\n");

    // Vytváření šachovnice
    for (int i = 0; i < pocet; i++) {
        for (int j = 0; j < velikost; j++) {
            printf("|");
            for (int k = 0; k < pocet; k++) {
                for (int l = 0; l < velikost; l++) {
                    if ((i + k) % 2 == 0) {
                        printf(" ");
                    } else {
                        printf("X");
                    }
                }
            }
            printf("|\n");
        }
    }

    // Vytvoření dolního rámce
    printf("+");
    for (int i = 0; i < pocet * velikost; i++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    int pocet;
    int velikost;

    // Čtení vstupu od uživatele
    printf("Zadejte pocet poli:\n");
    if (scanf("%d", &pocet) != 1 || pocet <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    
    printf("Zadejte velikost pole:\n");
    if (scanf("%d", &velikost) != 1 || velikost <= 0) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    // Vytvoření a vypsání šachovnice
    vytvorSachovnici(pocet, velikost);

    return 0;
}
