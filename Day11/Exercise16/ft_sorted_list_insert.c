#include "ft_list.h"
#include <stdlib.h>

t_list* ft_create_elem(void *data){

    t_list *new_list_el = (t_list*)malloc(sizeof(t_list));
    new_list_el->data = data;
    new_list_el->next = NULL;

    return new_list_el;
}

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()){

    t_list *curr;
    t_list *prev;
    for (curr = *begin_list; curr->next!=0x00 && cmp(data, curr->data)>=0; prev = curr, curr = curr->next){}   

    if (curr->next==0x00){
        curr->next = ft_create_elem(data);
        return;
    }

    prev->next = ft_create_elem(data);
    prev->next->next = curr;

    return;
}

void ft_list_push_back(t_list **begin_list, void *data){
    if (*begin_list==0){
        *begin_list = (t_list*)malloc(sizeof(t_list));
        (*begin_list)->data = data;
        return;
    }

    t_list *last; 
    for (last = *begin_list; last->next!=0x00; last = last->next){}

    t_list *new = (t_list*)malloc(sizeof(t_list));
    new->data = data;
    last->next = new;

}

int compare_func(char *s1, char *s2){
    return *s1-*s2;
}

int main(){

    t_list **list_array = (t_list**)malloc(sizeof(t_list*));

    char a[] = "1 test data";
    char b[] = "2 test data";
    char c[] = "4 test data";
    char d[] = "5 tets data";
    char e[] = "6 test data";

    ft_list_push_back(list_array, a);
    ft_list_push_back(list_array, b);
    ft_list_push_back(list_array, c);
    ft_list_push_back(list_array, d);
    ft_list_push_back(list_array, e);

    ft_sorted_list_insert(list_array, "6 test data", compare_func);

    return (0);
}
