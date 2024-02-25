#include "ft_list.h"
#include <stdlib.h>

void clear_list_recursive(t_list *curr){
    if (curr->next != 0){
        clear_list_recursive(curr->next);
    }

    free(curr);
}

void ft_list_clear(t_list **begin_list){

    if (*begin_list == 0x00){
        return;
    }

    clear_list_recursive(*begin_list);
    free(begin_list);
    *begin_list = 0x00;

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

int main(){

    t_list **list_array = (t_list**)malloc(sizeof(t_list));
    ft_list_push_back(list_array, "1 test data");
    ft_list_push_back(list_array, "2 test data");
    ft_list_push_back(list_array, "3 test data");

    ft_list_clear(list_array);

    return (0);
}
