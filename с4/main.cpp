#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct d {
    char* name;
    int year;
    int cost;
    int count;
};

int campdet(const void *a, const void *b) {
    d aa = *((d*) a);
    d bb = *((d*) b);
    return aa.cost - bb.cost;
};

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int i = 0;
    d details[10];
    char* names[10] = { "Гайка", "Шуруп", "Винт", "Фланец", "Прокладка", "Манометр", "Клапан", "Индикаторная лампа", "Вентель", "Сетка" };

    printf("\n\t*** До сортировки ***\n\n");
    printf("|  Год:  |  Цена:  |  Количество: | Наименование:\n");
    printf("-------------------------------------------------------\n");

    for ( i = 0; i < 10; i++ ) {
        details[i].name = names[i];
        details[i].year = 1950 + rand() % 67;
        details[i].cost = 100 + rand() % 20 * 100;
        details[i].count = rand() % 50;
        printf("|  %d  |  %4dр. | %6dшт.    | %s\n", details[i].year, details[i].cost, details[i].count, details[i].name);
    };

    qsort(details, 10, sizeof(details[0]), campdet);

    printf("\n\t*** После сортировки ***\n\n");
    printf("|  Год:  |  Цена:  |  Количество: | Наименование:\n");
    printf("-------------------------------------------------------\n");

    for ( i = 0; i < 10; i++ ) {
        printf("|  %d  |  %4dр. | %6dшт.    | %s\n", details[i].year, details[i].cost, details[i].count, details[i].name);
    };

    return 0;
}