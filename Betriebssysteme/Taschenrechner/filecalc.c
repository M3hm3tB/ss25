#include <stdio.h>


void read_from_file_and_calc(const char *filename){
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("fopen failed");
        return;
    }

    int a, b;
    while (fscanf(file, "%d,%d", &a, &b) == 2)
    {
       printf("%d + %d = %d\n", a, b, a + b);
    }

    if (ferror(file))
    {
        perror("Error while reading file");
    }
    
    fclose(file);
}

int main(void){
    read_from_file_and_calc("integer.txt");
    return 0;
}

