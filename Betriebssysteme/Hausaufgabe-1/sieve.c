#include <stdio.h>
#include <stdbool.h>

#define LIMIT 97

void sieb_des_eratosthenes(bool liste[], int grenze) {
    for (int faktor = 2; faktor * faktor <= grenze; faktor++) {
        if (!liste[faktor]) {
            for (int vielfaches = faktor * faktor; vielfaches <= grenze; vielfaches += faktor) {
                liste[vielfaches] = true;
            }
        }
    }
}

int main() {
    bool kein_prim[LIMIT + 1] = { false };
    sieb_des_eratosthenes(kein_prim, LIMIT);

    printf("Primzahlen bis %d:\n", LIMIT);
    for (int zahl = 2; zahl <= LIMIT; zahl++) {
        if (!kein_prim[zahl]) {
            printf("-> %d ist eine Primzahl\n", zahl);
        }
    }

    return 0;
}