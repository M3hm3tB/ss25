#include <stdio.h>
#include <stdbool.h>

const int MAX = 97;  // Maximale Zahl, bis zu der Primzahlen gesucht werden

// Sieb des Eratosthenes zur Markierung von Primzahlen
void sieb(bool prime[], int grenze) {
    for (int i = 2; i * i <= grenze; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= grenze; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    bool prime[MAX + 1];  // Index 0 bis MAX erlaubt
    for (int i = 0; i <= MAX; i++) {
        prime[i] = true;
    }

    prime[0] = false;  // 0 ist keine Primzahl
    prime[1] = false;  // 1 ist keine Primzahl

    sieb(prime, MAX);

    for (int i = 2; i <= MAX; i++) {
        if (prime[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
