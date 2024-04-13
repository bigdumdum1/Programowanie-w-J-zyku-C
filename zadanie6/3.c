#include <stdio.h>

int dodawanie(int a, int b);
int mnozenie(int a, int b);
int odejmowanie(int a, int b);

int main() {
    int (*wskaznik_do_funkcji)(int, int);

    int operacja;

    printf("Wybierz operacje:\n");
    printf("1. Dodawanie\n");
    printf("2. Mnozenie\n");
    printf("3. Odejmowanie\n");
    scanf("%d", &operacja);

    switch (operacja) {
        case 1:
            wskaznik_do_funkcji = &dodawanie;
            break;
        case 2:
            wskaznik_do_funkcji = &mnozenie;
            break;
        case 3:
            wskaznik_do_funkcji = &odejmowanie;
            break;
        default:
            printf("Niepoprawny wybor operacji.\n");
            return 1;
    }

    int liczba1, liczba2;
    printf("Podaj dwie liczby: ");
    scanf("%d %d", &liczba1, &liczba2);

    int wynik = (*wskaznik_do_funkcji)(liczba1, liczba2);
    printf("Wynik: %d\n", wynik);

    return 0;
}

int dodawanie(int a, int b) {
    return a + b;
}

int mnozenie(int a, int b) {
    return a * b;
}

int odejmowanie(int a, int b) {
    return a - b;
}
