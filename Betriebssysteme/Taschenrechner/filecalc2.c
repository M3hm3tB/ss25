#include <stdio.h>
#include <string.h>

// Prototyp
void read_from_file_and_calc(const char *filename);

int main(void) {
    read_from_file_and_calc("integer.txt");
    return 0;
}

void read_from_file_and_calc(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("fopen failed");
        return;
    }

    char line[256];
    // Zeile für Zeile einlesen
    while (fgets(line, sizeof(line), file)) {
        // 1) Komma finden
        char *comma = strchr(line, ',');
        if (!comma) 
            continue;                // kein Komma → nächste Zeile

        // 2) String in zwei Teile splitten
        *comma = '\0';
        char *left  = line;
        char *right = comma + 1;

        // 3) Newline am Ende entfernen
        // char *newline = strchr(right, '\n');
        //if (newline)
        //   *newline = '\0';

        // 4) Manuelles Parsen der Zahlen
        int a = 0, b = 0;
        for (char *p = left; *p; ++p) {
            if (*p >= '0' && *p <= '9')
                a = a * 10 + (*p - '0');
        }
        for (char *p = right; *p; ++p) {
            if (*p >= '0' && *p <= '9')
                b = b * 10 + (*p - '0');
        }

        // 5) Addition ausgeben
        printf("%d + %d = %d\n", a, b, a + b);
    }

    // auf Lese-Fehler prüfen
    if (ferror(file)) {
        perror("Error while reading file");
    }

    fclose(file);
}
