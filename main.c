#include <stdio.h>
#include <stdlib.h>
#include "sorted_list.h"


void show_menu(){
    printf("Program pozwalajacy operowac na listach jednokierunkowych posortowanych\n");
    printf("1. Wyswietlij liste\n");
    printf("2. Wczytaj liste z pliku\n");
    printf("3. Dodaj do listy\n");
    printf("4. Pobierz pierwszy element\n");
    printf("5. Pobierz ostatni element\n");
    printf("6. Wyszukaj element\n");
    printf("7. Usun szukany element\n");
    printf("8. Wyczysc liste\n");
    printf("9. Polacz dwie listy\n");
    printf("0. Wyjdz");
}

void test() {
    list l = 0, m = 0;
    l = malloc(sizeof(sorted));
    l->key = INT_MAX;
    l->next = 0;

    m = malloc(sizeof(sorted));
    m->key = INT_MAX;
    m->next = 0;
    add(&l, 2);
    add(&l, 4);
    add(&l, 6);
    add(&l, 9);

    add(&m, 2);
    add(&m, 5);
    add(&m, 7);
    add(&m, 9);

    return_two_lists ret = compare_two_lists(l, m);
    printf("List p\n");
    show(ret.first);
    printf("List q\n");
    show(ret.second);
}

void main_func() {
    list l = 0, m = 0;
    int user_input = 0, target = 0;

    l = malloc(sizeof(sorted));
    l->key = INT_MAX;
    l->next = 0;

    m = malloc(sizeof(sorted));
    m->key = INT_MAX;
    m->next = 0;

    while(true){
        show_menu();
        scanf("%d", &user_input);
        switch(user_input){
            case 1:
                show(l);
                break;
            case 2:
                read_from_a_file(&l);
                break;
            case 3:
                printf("Wprowadz element ktory chcesz dodac\n");
                scanf("%d", &user_input);
                add(&l, user_input);
                printf("Element dodano\n");
                break;
            case 4:
                printf("Pierwszy element : {%d}\n", get_first_element(&l));
                break;
            case 5:
                printf("Ostatni element : {%d}\n", get_last_element(&l));
                break;
            case 6:
                printf("Podaj element ktory chcesz znalezc\n");
                scanf("%d", &user_input);
                if(find_element(l, user_input)){
                    printf("Element znalieziony\n");
                    break;
                }
                printf("Element nie znalieziony\n");
                break;
            case 7:
                printf("Podaj element ktory chcesz usunac\n");
                scanf("%d", &user_input);
                if(remove_found(&l, user_input)){
                    printf("Element znalieziony i usuniety\n");
                    break;
                }
                printf("Element nie znalieziony\n");
                break;
            case 8:
                delete_list(&l);
                break;
            case 9:
                printf("Wprowadz rozmiar drugiej listy\n");
                scanf("%d", &user_input);
                for(int i = 1; i <= user_input; i++){
                    printf("Podaj %d element listy\n", i);
                    scanf("%d", &target);
                    add(&m, target);
                }
                //connect_two_lists(&l, &m);
            return_two_lists ret = compare_two_lists(l, m);
                printf("Lista polaczona: \n");
                show(ret.first);
                break;
            case 0:
                return;
        }
    }

}

int main() {
    test();

    return 0;
}
