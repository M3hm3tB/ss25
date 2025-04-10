#include <stdio.h>
#include <stdbool.h>

const int MAX = 97;

bool check_if_prime(int number) {
	int i;
	for(i=2; i<number; i++) {
		int division = number % i;
		if (division == 0) {
			return false;
		}
	}
	return true;
}


/*
 * Funktion: calculate_multiply
 * -----------------------------------
 * Durchläuft das array und setzt alle vielfachen von prime_number auf true.
 *
 * Parameter:
 *   prime - das array welche die prim makiert.
 *   MAX - ist die constante (muss nicht übergeben werden, aber dadurch liest
 *         sich der code besser).
 *   prime_number - das element das für prim gültig makiert wurde.
 */
void calculate_multiply(bool prime[], int MAX, int prime_number) {
	int i;
	for (i= 2 * prime_number; i<MAX; i += prime_number) {
		prime[i] = true;
	}
}


/*
 * Funktion: main
 * -----------------------------------
 * Erstellt ein Array. (Initalisiert ist ein leeres Array Feld in C immer false).
 *
 * Parameter:
 *   hat keine.
 *
 * Rückgabewert:
 *   gibt alle Index Werte aus für die das array false gespeichert hat.
 */
int main() {
	bool prime[MAX];
	int i;

	for (i=2; i<MAX; i++){
		if (prime[i] == false) {
			if (check_if_prime(i)==true) {
				calculate_multiply(prime, MAX, i);
			}
		}
	}
	int j;
	for (j = 0; j<MAX+1; j++) {
		if (prime[j] == false) {
			printf("%d\n", j);
		}
	}
}