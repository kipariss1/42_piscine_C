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

// MAIN FUNCTION OF THE TASK
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)()){

    t_list *curr;
    for (curr = begin_list2; curr->next!=0x00; curr=curr->next){
        ft_sorted_list_insert(begin_list1, curr->data, cmp);
    }

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

    t_list **list_array1 = (t_list**)malloc(sizeof(t_list*));

    char a[] = "1 test data";
    char b[] = "3 test data";
    char c[] = "4 test data";
    char d[] = "6 tets data";
    char e[] = "8 test data";

    ft_list_push_back(list_array1, a);
    ft_list_push_back(list_array1, b);
    ft_list_push_back(list_array1, c);
    ft_list_push_back(list_array1, d);
    ft_list_push_back(list_array1, e);

    t_list **list_array2 = (t_list**)malloc(sizeof(t_list*));

    char f[] = "2 test data";
    char g[] = "5 test data";
    char h[] = "7 test data";

    ft_list_push_back(list_array2, f);
    ft_list_push_back(list_array2, g);
    ft_list_push_back(list_array2, h);    

    ft_sorted_list_merge(list_array1, *list_array2, compare_func);

    return (0);
}
