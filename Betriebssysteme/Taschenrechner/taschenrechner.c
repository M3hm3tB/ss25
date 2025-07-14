#include <stdio.h>

int addition(int a,  int b){
    return a + b;
}

int subtraktion(int a, int b){
    return a - b; 
}

int mult(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}


int main(){
    int zahl1;
    int zahl2;
    char operator;
    int status_zahl1;
    int status_zahl2;
    int status_operator;
    printf("Gebe eine Zahl ein ");
    status_zahl1 = scanf("%d", &zahl1);
    printf("Gebe noch eine Zahl ein ");
    status_zahl2 = scanf("%d", &zahl2);
    printf("Gebe einen Operator an ");
    status_operator = scanf(" %c", &operator);

    if (status_zahl1 == 1 && status_zahl2 == 1 && status_operator == 1){
        int ergebnis;
        if(operator == '+'){
            ergebnis = addition(zahl1, zahl2);
        }
        else if(operator == '-'){
            ergebnis = subtraktion(zahl1, zahl2);
        }
        else if(operator == '*'){
            ergebnis = mult(zahl1, zahl2);
        }
        else if(operator == '/'){
            ergebnis = div(zahl1, zahl2);
        }
        else {
            printf("Unbekanter Op: %c\n", operator);
            return 1;
        }
        printf("Ergebnis: %d %c %d = %d\n", zahl1, operator, zahl2, ergebnis);
    }
    else {
        printf("Ungültige Eingabe erkannt!\n");
    }
    return 0;
}
