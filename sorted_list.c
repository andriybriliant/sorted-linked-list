#include "sorted_list.h"
#include <stdlib.h>

void show(list l){
    list temp = l;
    printf("[ ");
    while(temp && (temp->key < INT_MAX)){
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("]\n");
}


void add_to_start(list *l, int key){
    list p = malloc(sizeof(sorted));
    p->key = key;
    p->next = *l;
    *l = p;
}


void add(list* l, int key){
    if(l == NULL){
        return;
    }
    while((*l)->key < key){
        l = &(*l)->next;
    }
    add_to_start(&(*l), key);
}


bool find_element(list l, int key){
    if(l == NULL){
        return false;
    }
    list p = l;
    while(p->key <= key){
        if(p->key == key){
            return true;
        }
        p = p->next;
    }
    return false;
}


bool remove_found(list *l, int key){
    if(l == NULL){
        return false;
    }
    list p;
    int found_element = 0;
    while((*l)->key <= key){
        if((*l)->key == key){
            p = (*l);
            found_element = (*l)->key;
            (*l) = (*l)->next;
            free(p);
            return true;
        }
        else{
            l = &(*l)->next;
        }
    }
    return false;
}


void remove_first(list *l){
    if(*l == NULL){
        return;
    }
    list p = *l;
    *l = (*l)->next;
    free(p);
}


int get_first_element(list *l){
    if(*l == NULL || (*l)->key == INT_MAX){
        return 0;
    }
    int key = (*l)->key;
    remove_first(l);
    return key;
}


int get_last_element(list *l){
    int received_key = 0;

    if((*l) == NULL || (*l)->key == INT_MAX){
        return 0;
    }

    while((*l)->next->key < INT_MAX){
        l = &(*l)->next;
    }

    received_key = (*l)->key;
    remove_found(&(*l), received_key);
    return received_key;
}


void delete_list(list *l){
    while(*l && ((*l)->key < INT_MAX)){
        remove_first(l);
    }
}


void read_from_a_file(list *l){
    FILE* list_f = fopen("lista.txt", "r");
    if(list_f == NULL){
        printf("Failed to open a file\n");
    }
    int temp = 0;
    while(fscanf(list_f, "%d ", &temp) == 1){
        add(l, temp);
    }
}


void connect_two_lists(list* p, list* q){
    if(*p == NULL){
        *p = *q;
        *q = NULL;
        return;
    }

    if(*q == NULL){
        return;
    }

    list *last = p;
    list curr_p = *p;
    list curr_q = *q;

    while(curr_p && curr_q){
        if(curr_q->key < curr_p->key){
            list start_q = curr_q;
            while(curr_q->next && curr_q->next->key < curr_p->key){
                curr_q = curr_q->next;
            }

            list next_q = curr_q->next;
            curr_q->next = curr_p;
            *last = start_q;
            last = &(curr_q->next);
            curr_q = next_q;
        }else{
            last = &(curr_p->next);
            curr_p = curr_p->next;
        }
    }

    if(curr_q){
        *last = curr_q;
    }

    *q = NULL;

}


return_two_lists compare_two_lists(list p, list q) {
    list p_not_q = malloc(sizeof(sorted));
    list q_not_p = malloc(sizeof(sorted));
    p_not_q->key = INT_MAX;
    p_not_q->next = 0;

    q_not_p->key = INT_MAX;
    q_not_p->next = 0;

    if(p == NULL) {
        p_not_q = q;
        q_not_p = q;
    }

    if(q == NULL) {
        q_not_p = p;
        p_not_q = p;
    }

    while (p) {
        list temp_q = q;
        while (temp_q) {
            if (temp_q->key == p->key) {
                remove_found(&q, p->key);
                remove_found(&p, p->key);
                break;
            }
            if (temp_q->key < p->key) {
                temp_q = temp_q->next;
            }
            else {
                add(&p_not_q, p->key);
                p = p->next;
                break;
            }
        }
    }

    q_not_p = q;
    return_two_lists ret;
    ret.first = p_not_q;
    ret.second = q_not_p;
    return  ret;
}